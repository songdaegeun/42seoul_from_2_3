/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:46:14 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/04 12:02:47 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "events.h"

static void	report_sigterm(int wstatus);

t_bool	execute(t_node *root)
{
	t_context	ctx;

	ctx.fd[STDIN_FILENO] = STDIN_FILENO;
	ctx.fd[STDOUT_FILENO] = STDOUT_FILENO;
	ctx.fd_close = -1;
	ctx.retcode = *get_exit_status();
	ctx.error = FALSE;
	ctx.quit = FALSE;
	ctx.proc = 0;
	ctx.pipeline = FALSE;
	char *file_name[16] = {"heredoc_0", "heredoc_1", "heredoc_2", "heredoc_3", "heredoc_4", "heredoc_5", "heredoc_6", "heredoc_7", "heredoc_8", "heredoc_9", "heredoc_10", "heredoc_11", "heredoc_12", "heredoc_13", "heredoc_14", "heredoc_15"};
	ctx.heredoc_file_name = file_name;
	ctx.heredoc_file_idx = 0;
	ft_memset(ctx.pid, 0, PIPE_LIMIT * sizeof(int));
	save_tree_ref(root);
	exec_node(root, &ctx);
	reaper(&ctx);
	wait_user_signals();
	set_exit_status(ctx.retcode);
	return (ctx.quit);
}

void	exec_node(t_node *node, t_context *ctx)
{
	if (node == NULL || ctx->error)
		return ;
	if (node->type == COMMAND)
		exec_command(node, ctx);
	else if (node->type == INPUT)
		exec_input(node, ctx);
	else if (node->type == OUTPUT)
		exec_output(node, ctx);
	else if (node->type == APPEND)
		exec_append(node, ctx);
	else if (node->type == PIPE)
		exec_pipe(node, ctx);
	else if (node->type == AND)
		exec_and(node, ctx);
	else if (node->type == OR)
		exec_or(node, ctx);
	else if (node->type == HERE_DOC)
		exec_heredoc(node, ctx);
	else if (node->type == SUBSHELL)
		exec_subshell(node, ctx);
	return ;
}

void	reaper(t_context *ctx)
{
	int	it;
	int	wstatus;

	it = 0;
	wstatus = 0;
	while (ctx->pid[it] != 0)
	{
		waitpid(ctx->pid[it], &wstatus, 0);
		ctx->pid[it] = 0;
		ctx->proc--;
		it++;
	}
	if (ctx->error == TRUE || ctx->retcode)
		return ;
	set_wstatus(wstatus, ctx);
}

void	set_wstatus(int wstatus, t_context *ctx)
{
	if (WIFEXITED(wstatus))
		ctx->retcode = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
	{
		ctx->retcode = WTERMSIG(wstatus);
		if (ctx->retcode == 11)
			report_sigterm(wstatus);
		ctx->retcode += 128;
	}
}

static void	report_sigterm(int wstatus)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("Process finished with exit code ", STDERR_FILENO);
	ft_putnbr_fd(wstatus, STDERR_FILENO);
	ft_putstr_fd(" (interrupted by signal ", STDERR_FILENO);
	ft_putnbr_fd(WTERMSIG(wstatus), STDERR_FILENO);
	ft_putendl_fd(")", STDERR_FILENO);
}
