/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:23:39 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/07 00:07:54 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "events.h"
# include "hash_table.h"
# include "builtins.h"
# include "scanner.h"
# include "parser.h"
# include "helpers.h"
# include "exec.h"
# include "expansion.h"


int *get_heredoc_exit_flag(void);
int *get_tmp_stdin_fd(void);
void set_heredoc_exit_flag(int flag);
void set_tmp_stdin_fd(int fd);

#endif
