/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:46:29 by sdg               #+#    #+#             */
/*   Updated: 2023/06/17 21:50:02 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(int argc, char **argv, t_file_info *file_info, char **envp)
{
	int		pipe_fd[2];
	int		read_len;
	char	buffer[BUFFER_SIZE];

	pipe(pipe_fd);
	rw_open_file("heredoc", O_WRONLY | O_CREAT | O_TRUNC, file_info);
	write(1, "pipe heredoc> ", 14);
	read_len = read(STDIN_FD, buffer, BUFFER_SIZE);
	while (ft_strncmp(buffer, argv[2], 7))
	{
		write(file_info->fd, buffer, read_len);
		write(1, "pipe heredoc> ", 14);
		read_len = read(STDIN_FD, buffer, BUFFER_SIZE);
	}
	pipe_middle_heredoc(argv[3], file_info->fd, envp);
	rw_open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, file_info);
	pipe_write_end(argv[argc - 2], file_info->fd, envp);
	unlink("heredoc");
}

void	pipe_middle_heredoc(char *cmd, int heredoc, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	pipe(pipe_fd);
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
		heredoc_redi(pipe_fd);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
}

void	pipe_middle_heredoc_child(int *pipe_fd, \
char *cmd, int heredoc, char **envp)
{
	char	**cmd_s;
	char	*cmd_path;
	char	**exec_arg;

	close(pipe_fd[0]);
	pipe_middle_heredoc_redi(pipe_fd, heredoc);
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

void	heredoc_redi(int *pipe_fd)
{
	if (dup2(pipe_fd[0], STDIN_FD) == -1)
	{
		perror("Failed to execute dup2.");
		exit(1);
	}
}
