/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by sdg               #+#    #+#             */
/*   Updated: 2023/06/15 23:01:16 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex file1 cmd1 cmd2 file2

//  ./pipex test.txt "ls -l" "wc -l" res1.txt
//  < test.txt ls -l | wc -l > res2.txt

// ./pipex test.txt "grep a" "wc -w" res1.txt
// < test.txt grep a | wc -w > res2.txt
// ./pipex test1.txt "grep a" "wc -w" res1.txt
// < test1.txt grep a | wc -w > res2.txt
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

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			pipe_fd1[2];
	int			pipe_fd2[2];
	t_file_info	file_unfo;

	if (argc != 5)
	{
		write(1, "Format error!\n", 14);
		exit(1);
	}
	pipe(pipe_fd1);
	pipe(pipe_fd2);
	rw_open_file(argv[1], O_RDONLY, &file_unfo);
	if (dup2(pipe_fd1[0], STDIN_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
	pipe_read_end(pipe_fd1, argv[2], file_unfo.fd, envp);
	if (file_unfo.empty)
		unlink(argv[1]);
	rw_open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC, &file_unfo);
	if (dup2(file_unfo.fd, STDOUT_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
	pipe_write_end(pipe_fd2, argv[3], file_unfo.fd, envp);	
	return (0);
}

void	pipe_read_end(int *pipe_fd1, char *cmd, int infile_fd, char **envp)
{
	pid_t	pid;
	char	**exec_arg;
	char	**cmd_s;

	pid = fork();
	if (pid < 0)
	{
		perror("Failed to fork.");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipe_fd1[0]);
		if (dup2(infile_fd, STDIN_FD) == -1)
		{
			perror("Failed to execute dup2.");
			exit(1);
		}
		if (dup2(pipe_fd1[1], STDOUT_FD) == -1)
		{
			perror("Failed to execute dup2.");
			exit(1);
		}
		cmd_s = ft_split(cmd, ' ');
		if (!cmd_s)
			exit(1);
		exec_arg = (char **)malloc(sizeof(char *) * (2 + 1));
		exec_arg[0] = cmd_s[0];
		exec_arg[1] = cmd_s[1];
		exec_arg[2] = 0;
		close(pipe_fd1[1]);
		char *cmd_path = cmd_path_find(exec_arg[0], envp);
		if(!cmd_path)
		{
			perror("Failed to find command path.");
			exit(1);
		}
		if (execve(cmd_path, exec_arg, envp) == -1)
		{
			perror("Failed to execute execve.");
			exit(1);
		}
		perror("Failed to execute 'read end' side command.");
		exit(1);
	}
	else
	{
		wait(0);
		close(pipe_fd1[1]);
		close(pipe_fd1[0]);
		close(infile_fd);
	}
}

void	pipe_write_end(int *pipe_fd2, char *cmd, int outfile_fd, char **envp)
{
	pid_t	pid;
	char	**exec_arg;
	char	**cmd_s;

	pid = fork();
	if (pid < 0)
	{
		perror("Failed to fork.");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipe_fd2[0]);
		cmd_s = ft_split(cmd, ' ');
		if (!cmd_s)
			exit(1);
		exec_arg = (char **)malloc(sizeof(char *) * (2 + 1));
		exec_arg[0] = cmd_s[0];
		exec_arg[1] = cmd_s[1];
		exec_arg[2] = 0;
		close(pipe_fd2[1]);
		char *cmd_path = cmd_path_find(exec_arg[0], envp);
		if(!cmd_path)
		{
			perror("Failed to find command path.");
			exit(1);
		}
		if (execve(cmd_path, exec_arg, envp) == -1)
		{
			perror("Failed to execute execve.");
			exit(1);
		}
		perror("Failed to execute 'read end' side command.");
		exit(1);
	}
	else
	{
		wait(0);
		close(pipe_fd2[1]);
		close(pipe_fd2[0]);
		close(outfile_fd);
	}
}

void	rw_open_file(char *filename, int flag, t_file_info *file_unfo)
{
	file_unfo->fd = open(filename, flag, 0777);
	file_unfo->empty = 0;
	if (file_unfo->fd == -1)
	{
		perror("Failed to open file.");
		if (flag == O_RDONLY)
		{
			file_unfo->fd = open(filename, O_RDONLY | O_CREAT, 0777);
			file_unfo->empty = 1;
			if (file_unfo->fd == -1)
				exit(1);
		}
		else
			exit(1);
	}
}

char *cmd_path_find(char *cmd, char **envp)
{
	char **env_pt;
	env_pt = envp;
	while (*env_pt)
	{
		char **res = ft_split(*env_pt, '=');
		if(!ft_strncmp(res[0], "PATH", 4))
		{
			char **res2 = ft_split(res[1], ':');
			// res2를 순회하며 cmd_path 실행가능여부확인
			int i = 0;
			while(res2[i])
			{
				cmd = ft_strjoin("/", cmd);
				char *cmd_path = ft_strjoin(res2[i++], cmd);
				if (access(cmd_path, X_OK) != -1)
				{
					return (cmd_path);
				}
			}
		}
		env_pt++;
	}
	return (0);
}
