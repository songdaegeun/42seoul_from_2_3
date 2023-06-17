/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:14:30 by sdg               #+#    #+#             */
/*   Updated: 2023/06/17 12:52:15 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define BUFFER_SIZE 1024
# define STDOUT_FD 1
# define STDIN_FD 0
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_file_info
{
	int	fd;
	int	empty;
}	t_file_info;

void	rw_open_file(char *filename, int creat_flag, t_file_info *file_unfo);
void	pipe_read_end(int *pipe_fd1, char *cmd, int infile_fd, char **envp);
void	pipe_write_end(int *pipe_fd2, char *cmd, int outfile_fd, char **envp);
char	*cmd_path_find(char *cmd, char **envp);
void	read_end_child(int *pipe_fd1, int infile_fd, char *cmd, char **envp);
void	write_end_child(int *pipe_fd2, char *cmd, char **envp);
void	read_end_child_redi(int infile_fd, int *pipe_fd1);
void	write_end_parent_redi(int outfile_fd);
char	**exec_arg_set(char **cmd_s);
void	pipe_middle(char *cmd, char **envp);
void	pipe_middle_child(int *pipe, char *cmd, char **envp);
void pipe_middle_child_redi(int *pipe);



#endif