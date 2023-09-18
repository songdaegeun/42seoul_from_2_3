/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:03:29 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 15:16:50 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	exec_subshell(t_node *node, t_context *ctx)
{
	int			pid;
	// int			saved_fd[2];
	t_node		*list;
	t_context	aux_ctx;

	list = node->data.pair.left;
	// redirect_io(saved_fd, ctx);
	aux_ctx = *ctx;
	pid = pfork();
	if (pid == FORKED_CHILD)
	{
		exec_node(list, &aux_ctx);
		// restore_io(saved_fd);
		reaper(&aux_ctx);
		msh_clean();
		exit(aux_ctx.retcode);
	}
	// restore_io(saved_fd);
	enqueue(pid, ctx);
	reaper(ctx);
}
