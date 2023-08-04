/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:36:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/04 12:03:21 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"

t_scanner	init_scanner(const char *source)
{
	t_scanner	self;
	char *file_name[16] = {"heredoc_0", "heredoc_1", "heredoc_2", "heredoc_3", "heredoc_4", "heredoc_5", "heredoc_6", "heredoc_7", "heredoc_8", "heredoc_9", "heredoc_10", "heredoc_11", "heredoc_12", "heredoc_13", "heredoc_14", "heredoc_15"};

	self.iter.start = source;
	self.iter.current = source;
	self.next = scan_token(&self);
	self.heredoc_file_name = file_name;
	self.heredoc_file_idx = 0;
	return (self);
}

t_token	make_token(const t_scanner *self, t_token_type type)
{
	t_token	token;

	token.type = type;
	token.start = self->iter.start;
	token.length = self->iter.current - self->iter.start;
	return (token);
}

t_token	error_token(const char *message)
{
	t_token	token;

	token.type = TOKEN_ERROR;
	token.start = message;
	token.length = ft_strlen(message);
	return (token);
}

t_bool	is_at_end(t_scanner *self)
{
	return (*self->iter.current == '\0');
}

char	advance(t_scanner *self)
{
	self->iter.current++;
	return (self->iter.current[-1]);
}
