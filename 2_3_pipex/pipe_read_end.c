/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_read_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:34:21 by sdg               #+#    #+#             */
/*   Updated: 2023/06/17 19:45:40 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_read_end(int *pipe_fd1, char *cmd, int infile_fd, char **envp)
{
	pid_t	pid;

	if (dup2(pipe_fd1[0], STDIN_FD) == -1)
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
		read_end_child(pipe_fd1, infile_fd, cmd, envp);
	else
	{
		wait(0);
		close(pipe_fd1[1]);
		close(pipe_fd1[0]);
		close(infile_fd);
	}
}

void	read_end_child(int *pipe_fd1, int infile_fd, char *cmd, char **envp)
{
	char	**cmd_s;
	char	*cmd_path;
	char	**exec_arg;

	close(pipe_fd1[0]);
	read_end_child_redi(infile_fd, pipe_fd1);
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
	close(pipe_fd1[1]);
	if (execve(cmd_path, exec_arg, envp) == -1)
	{
		perror("Failed to execute execve.");
		exit(1);
	}
	perror("Failed to execute 'read end' side command.");
	exit(1);
}

void	read_end_child_redi(int infile_fd, int *pipe_fd1)
{
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
}

char	**exec_arg_set(char **cmd_s)
{
	char	**exec_arg;
	int		i;

	exec_arg = (char **)malloc(sizeof(char *) * (ft_split_len(cmd_s) + 1));
	if (!exec_arg)
	{
		perror("Failed to memory allocation.");
		exit(1);
	}
	exec_arg[0] = ft_strjoin("/", cmd_s[0]);
	free(cmd_s[0]);
	i = 1;
	while (cmd_s[i])
	{
		exec_arg[i] = cmd_s[i];
		i++;
	}
	exec_arg[i] = 0;
	return (exec_arg);
}