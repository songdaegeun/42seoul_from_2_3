/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_write_end_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:18:37 by sdg               #+#    #+#             */
/*   Updated: 2023/06/17 22:11:17 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipe_write_end(char *cmd, int outfile_fd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Failed to fork.");
		exit(1);
	}
	if (pid == 0)
		write_end_child(cmd, outfile_fd, envp);
	else
	{
		wait(0);
		close(outfile_fd);
	}
}

void	write_end_child_redi(int outfile_fd)
{
	if (dup2(outfile_fd, STDOUT_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
}

void	write_end_child(char *cmd, int outfile_fd, char **envp)
{
	char	**cmd_s;
	char	*cmd_path;
	char	**exec_arg;

	write_end_child_redi(outfile_fd);
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
	if (execve(cmd_path, exec_arg, envp) == -1)
	{
		perror("Failed to execute execve.");
		exit(1);
	}
	perror("Failed to execute 'read end' side command.");
	exit(1);
}
