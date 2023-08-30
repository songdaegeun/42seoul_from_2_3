/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:27:47 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/07 01:20:56 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_node	*mkio(t_node_type type, t_token_type tk, t_scanner *scanner);

// io_file -> LESS WORD
//          | GREAT WORD
//          | DGREAT WORD
t_node	*io_file(t_scanner *scanner)
{
	if (match(TOKEN_LESS, scanner))
		return (mkio(INPUT, TOKEN_WORD, scanner));
	if (match(TOKEN_GREAT, scanner))
		return (mkio(OUTPUT, TOKEN_WORD, scanner));
	if (match(TOKEN_DGREAT, scanner))
		return (mkio(APPEND, TOKEN_WORD, scanner));
	return (NULL);
}

/************************************************************************************/
#include "minishell.h"

void	set_delimiter(t_node *node, char buf[]);
char	*quote_removal(char *word);

// io_here -> DLESS WORD
t_node	*io_here(t_scanner *scanner)
{
	if (match(TOKEN_DLESS, scanner)) {
		t_node	*node;
		node = mkio(HERE_DOC, TOKEN_WORD, scanner);

		#define DELIMLEN 1024

		char	delim[DELIMLEN];

		if(scanner->heredoc_file_idx >= 16) {
			printf("bash: maximum here-document count exceeded\n");
			// memory release
			exit(1);
		}
		set_delimiter(node, delim);
		// printf("del: %s\n",delim);
		here_doc(delim, scanner);
		if (*get_heredoc_exit_flag() == 1)
		{
			dup2(*get_tmp_stdin_fd(), STDIN_FILENO);
			close(*get_tmp_stdin_fd());
			return (NULL);
		}
		return (node);
	}
	return (NULL);
}
/************************************************************************************/


static t_node	*mkio(t_node_type type, t_token_type tk, t_scanner *scanner)
{
	t_node	*right;

	if (peek(scanner).type == tk)
	{
		right = mkleaf(next(scanner));
		return (mknode(type, NULL, right));
	}
	syntax_error(scanner);
	return (NULL);
}

/************************************************************************************/

void	set_delimiter(t_node *node, char buf[])
{
	char	*word;

	word = node->data.pair.right->data.cmd[0];
	word = quote_removal(word);
	ft_strlcpy(buf, word, DELIMLEN);
	free(word);
}

char	*quote_removal(char *word)
{
	t_list	*list;
	char	*chunk;

	list = split_quotes(word);
	unquote(list);
	chunk = concatenate(list);
	ft_lstclear(&list, free);
	return (chunk);
}

int *get_heredoc_exit_flag(void)
{
	static int heredoc_exit_flag;
	return (&heredoc_exit_flag);
}

int *get_tmp_stdin_fd(void)
{
	static int tmp_stdin_fd;
	return (&tmp_stdin_fd);
}

void set_heredoc_exit_flag(int flag)
{
	*get_heredoc_exit_flag() = flag;
}

void set_tmp_stdin_fd(int fd)
{
	*get_tmp_stdin_fd() = fd;
}


/************************************************************************************/
