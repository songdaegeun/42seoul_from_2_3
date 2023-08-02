/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:56:51 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 15:11:14 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "expansion.h"
#include "events.h"

#define DELIMLEN 1024

static char	*quote_removal(char *word);
static void	set_delimiter(t_node *node, char buf[]);

void	exec_heredoc(t_node *node, t_context *ctx)
{
	int		pid;
	char	delim[DELIMLEN];
	int wstatus;
	
	set_delimiter(node, delim);
	pid = pfork();
	if (pid == FORKED_CHILD)
	{
		here_doc(delim);
		msh_clean();
		exit(EXIT_SUCCESS);
	}
	heredoc_parent_sighandler();
	// enqueue(pid, ctx);
	// reaper(ctx);
	waitpid(pid, &wstatus, 0);
	set_wstatus(wstatus, ctx);
	wait_user_signals();
	if (ctx->retcode == EXIT_SUCCESS)
	{
		ctx->fd[STDIN_FILENO] = open(HEREDOC_TEMPFILE, O_RDONLY, 0644);
		exec_node(node->data.pair.left, ctx);
		close(ctx->fd[STDIN_FILENO]);
	}
}

static void	set_delimiter(t_node *node, char buf[])
{
	char	*word;

	word = node->data.pair.right->data.cmd[0];
	word = quote_removal(word);
	ft_strlcpy(buf, word, DELIMLEN);
	free(word);
}

static char	*quote_removal(char *word)
{
	t_list	*list;
	char	*chunk;

	list = split_quotes(word);
	unquote(list);
	chunk = concatenate(list);
	ft_lstclear(&list, free);
	return (chunk);
}
