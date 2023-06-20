/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by sdg               #+#    #+#             */
/*   Updated: 2023/06/20 14:26:59 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_file_info	file_info;

	if (argc < 5)
	{
		write(1, "Format error!\n", 14);
		exit(1);
	}
	else if (argc == 6 && !ft_strncmp(argv[1], "here_doc", 8))
		heredoc(argc, argv, &file_info, envp);
	else
		redirection(argc, argv, &file_info, envp);
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

void	redirection(int argc, char **argv, t_file_info *file_info, char **envp)
{
	int	pipe_fd[2];
	int	i;

	pipe(pipe_fd);
	rw_open_file(argv[1], O_RDONLY, file_info);
	pipe_read_end(pipe_fd, argv[2], file_info->fd, envp);
	if (file_info->empty)
		unlink(argv[1]);
	if (argc > 5)
	{
		i = 0;
		while (i < argc - 5)
			pipe_middle(argv[3 + i++], envp);
	}
	rw_open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, file_info);
	pipe_write_end(argv[argc - 2], file_info->fd, envp);
}
