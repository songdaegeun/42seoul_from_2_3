/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:43:36 by ygorgsena         #+#    #+#             */
/*   Updated: 2023/08/22 23:04:20 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_new_prompt(int sig)
{
	ft_putendl_fd("", STDOUT_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	set_exit_status(128 + sig);
}

void	exit_child(int sig)
{
	if (sig == SIGINT)
		ft_putendl_fd("", STDIN_FILENO);
	else if (sig == SIGQUIT)
		ft_putendl_fd("Quit", STDIN_FILENO);
}

void	exit_heredoc(int sig)
{
	int	fd;

	sig += 128;
	fd = *get_fd_close();
	if (fd != STDIN_FILENO || fd != STDOUT_FILENO)
		close(fd);
	set_exit_status(sig);
	ft_putendl_fd("", STDOUT_FILENO);
	msh_clean();
	
	set_heredoc_exit_flag(1);
	set_tmp_stdin_fd(dup(0));
	close(STDIN_FILENO);
}
