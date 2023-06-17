/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:49:21 by sdg               #+#    #+#             */
/*   Updated: 2023/06/17 13:11:06 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_middle(char *cmd, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	char	**exec_arg;
	char	**cmd_s;
	char	*cmd_path;

	pipe(pipe_fd);
	if (dup2(STDIN_FD, pipe_fd[0]) == -1)
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
		pipe_middle_child(pipe_fd, cmd, envp);
	else
	{
		wait(0);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
}

void	pipe_middle_child(int *pipe_fd, char *cmd, char **envp)
{
	char	**cmd_s;
	char	*cmd_path;
	char	**exec_arg;

	close(pipe_fd[0]);
	pipe_middle_child_redi(pipe_fd);
	cmd_s = ft_split(cmd, ' ');
	if (!cmd_s)
		exit(1);
	exec_arg = exec_arg_set(cmd_s);
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

void	pipe_middle_child_redi(int *pipe_fd)
{
	if (dup2(pipe_fd[1], STDOUT_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
}