/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:17:47 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/07 01:22:52 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "exec.h"
#include "minishell.h"

#define FAILED 2

t_node	*parse(t_scanner *scanner)
{
	t_node	*root;

	if (peek(scanner).type == TOKEN_EOF)
	{
		set_exit_status(EXIT_SUCCESS);
		return (NULL);
	}
	root = list(scanner);
	if (*get_heredoc_exit_flag() != 1 && peek(scanner).type != TOKEN_EOF)
	{
		syntax_error(scanner);
		free_tree(root);
		set_exit_status(FAILED);
		return (NULL);
	}
	set_heredoc_exit_flag(0);
	return (root);
}

t_bool	match(t_token_type type, t_scanner *scanner)
{
	if (peek(scanner).type == type)
	{
		next(scanner);
		return (TRUE);
	}
	return (FALSE);
}
