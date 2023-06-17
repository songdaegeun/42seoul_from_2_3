/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_middle_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:46:29 by sdg               #+#    #+#             */
/*   Updated: 2023/06/17 17:38:13 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_middle_heredoc(char *cmd, int heredoc, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	char	**exec_arg;
	char	**cmd_s;
	char	*cmd_path;

	pipe(pipe_fd);
	if (dup2(pipe_fd[0], STDIN_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Failed to fork.");
		exit(1);
	}
	if (pid == 0)
		pipe_middle_heredoc_child(pipe_fd, cmd, heredoc, envp);
	else
	{
		wait(0);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
}

void	pipe_middle_heredoc_child(int *pipe_fd, char *cmd, int heredoc, char **envp)
{
	char	**cmd_s;
	char	*cmd_path;
	char	**exec_arg;

	close(pipe_fd[0]);
	pipe_middle_heredoc_redi(pipe_fd, heredoc);
	unlink("heredoc");
	cmd_s = ft_split(cmd, ' ');
	if (!cmd_s)
		exit(1);
	exec_arg = exec_arg_set(cmd_s);
	// 각 cmd_s[i]에 대해 할 것
	// quote 제거 필요. quote(' or ") 쌍이 맞으면 null값 대입, 쌍이 안맞으면 quote(heredoc)
	
	// 쌍이 안맞아서 임시파일을 사용하는 경우:
	// 1,2번째 인수, 즉 cmd_s[0,1]의 경우 명령어와 옵션인데(옵션이 없는 경우도 고려해야함), 이것은 read는 따로하지만 '\n'도 포함해서 연결한다.
	// 나머지 2개는 임시파일에 읽은 것들을 '\n'기준으로 나눠서 주어진 명령어와 옵션에 대해 thread로 돌린다(예시1의 결과를 보면 3,7p인자와 p인자의 결과가 섞여나오는 걸로 보아
	// thread인 것으로 보임. 사실 확인 필요.)

	// 예시1.
	// 2_3_pipex % < test.txt sed -n '3,7p 
	// quote> p'
	cmd_path = cmd_path_find(exec_arg[0], envp);
	if (!cmd_path)
	{
		perror("Failed to find command path.");
		exit(1);
	}
	close(pipe_fd[1]);
	if (execve(cmd_path, exec_arg, envp) == -1)
	{
		perror("Failed to execute execve.");
		exit(1);
	}
	perror("Failed to execute 'read end' side command.");
	exit(1);
}

void	pipe_middle_heredoc_redi(int *pipe_fd, int heredoc)
{
	if (dup2(heredoc, STDIN_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
	if (dup2(pipe_fd[1], STDOUT_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
}
