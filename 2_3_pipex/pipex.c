/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by sdg               #+#    #+#             */
/*   Updated: 2023/06/17 16:47:14 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
// ./pipex file1 cmd1 cmd2 file2

//  ./pipex test.txt "ls -l" "wc -l" res1.txt
//  < test.txt ls -l | wc -l > res2.txt

// ./pipex test.txt "grep a" "wc -w" res1.txt
// < test.txt grep a | wc -w > res2.txt
// ./pipex test1.txt "grep a" "wc -w" res1.txt
// < test1.txt grep a | wc -w > res2.txt
*/
/*
sudo:
pipe operator의 read end와 write end 각각의 명령을 실행할 프로세스는 2개 필요하다.
./pipex [args]를 실행하는 순간, 쉘에서 fork되어 'pipex 프로세스'가 생성된다.

pipex프로세스에서 infile을 읽고, 그 결과를 입력으로 받을 프로세스는 pipe_read_end이다.
pipe_read_end의 출력을 입력으로 받을 프로세스는 pipe_write_end이다.
pipex프로세스는 2개의 프로세스 pipe_read_end, pipe_write_end와 통신해야하므로 
2개의 파이프 pipe_fd1, pipe_fd2를 사용한다.

pipex프로세스의 실행흐름은 다음과 같다.

pipe(pipe_fd1);
pipe(pipe_fd2);
dup2(pipe_fd1[0], STDIN_FD);
cmd1을 실행할 프로세스인 pipe_read_end프로세스를 fork한다.

pipex프로세스에서
pipe_read_end가 끝날 때까지 대기하다가 infile 및 pipe_fd1을 닫는다.

pipe_read_end에서
dup2(infile_fd, STDIN_FD);
dup2(pipe_fd1[1], STDOUT_FD);
으로 redirection 해놓는다.

execve로 cmd1을 실행하여 pipe_read_end의 memory를 덮어쓴다.
표준출력에 write된 내용은
pipe_read_end의 pipe_fd1[1]이 가리키고 있으므로
pipex프로세스의 pipe_fd1[0]으로 read할 수 있다.
pipe_fd1[0]은 STDIN_FDd으로 redirection 되어있으므로 
pipe_write_end에서 cmd2를 실행할 준비는 끝났다.

pipe_write_end를 fork하고 pipex에서 기다리는 과정도 위와 유사하다.
*/
/*
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

./pipex here_doc LIMITER cmd cmd1 file
cmd << LIMITER | cmd1 >> file

ls << LIMMITER | grep a >> res3.txt 

*/

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			pipe_fd1[2];
	int			pipe_fd2[2];
	char		buffer[BUFFER_SIZE];
	t_file_info	file_info;
	int			read_len;

	pipe(pipe_fd1);
	pipe(pipe_fd2);
	if (argc < 5)
	{
		write(1, "Format error!\n", 14);
		exit(1);
	}
	else if (argc == 6 && !ft_strncmp(argv[1], "here_doc", 8))
	{
		rw_open_file("heredoc", O_WRONLY | O_CREAT | O_TRUNC, &file_info);
		write(1, "pipe heredoc> ", 14);
		read_len = read(STDIN_FD, buffer, BUFFER_SIZE);
		while (ft_strncmp(buffer, argv[2], 7))
		{
			write(file_info.fd, buffer, read_len);
			write(1, "pipe heredoc> ", 14);
			read_len = read(STDIN_FD, buffer, BUFFER_SIZE);
		}
		pipe_middle_heredoc(argv[3], file_info.fd, envp);
		rw_open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, &file_info);
		pipe_write_end(pipe_fd2, argv[argc - 2], file_info.fd, envp);
	}
	else
	{
		rw_open_file(argv[1], O_RDONLY, &file_info);
		pipe_read_end(pipe_fd1, argv[2], file_info.fd, envp);
		if (file_info.empty)
			unlink(argv[1]);
		if (argc > 5)
		{
			for (int i = 0; i < argc - 5; i++)
			{
				pipe_middle(argv[3 + i], envp);
			}
		}
		rw_open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, &file_info);
		pipe_write_end(pipe_fd2, argv[argc - 2], file_info.fd, envp);
	}
	return (0);
}

char	*cmd_path_find(char *cmd, char **envp)
{
	char	**env_pt;
	char	**res1;
	char	**res2;
	int		i;
	char	*cmd_path;

	env_pt = envp;
	while (*env_pt)
	{
		res1 = ft_split(*(env_pt++), '=');
		if (!ft_strncmp(res1[0], "PATH", 4))
		{
			res2 = ft_split(res1[1], ':');
			i = 0;
			while (res2[i])
			{
				cmd_path = ft_strjoin(res2[i++], cmd);
				if (access(cmd_path, X_OK) != -1)
					return (cmd_path);
			}
			free(res2);
			free(res1);
		}
	}
	return (0);
}

void	rw_open_file(char *filename, int flag, t_file_info *file_info)
{
	file_info->fd = open(filename, flag, 0777);
	file_info->empty = 0;
	if (file_info->fd == -1)
	{
		perror("Failed to open file.");
		if (flag == O_RDONLY)
		{
			file_info->fd = open(filename, O_RDONLY | O_CREAT, 0777);
			file_info->empty = 1;
			if (file_info->fd == -1)
				exit(1);
		}
		else
			exit(1);
	}
}

int	ft_split_len(char **cmd_s)
{
	int	i;

	i = 0;
	while (cmd_s[i])
		i++;
	return (i);
}