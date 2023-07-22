/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:32:01 by yde-goes          #+#    #+#             */
/*   Updated: 2023/07/22 01:25:07 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <dirent.h>

# include "exec.h"
# include "helpers.h"

# define NEW_LINE "-n"
# define PATH_MAX 50

typedef int	(*t_builtin)(char **args);

t_builtin	builtin_pool(char *name, t_context *ctx);
int			ft_echo(char **args);
int			ft_env(char **args);
int			ft_pwd(char **args);
int			ft_unset(char **args);
int			ft_cd(char	**args);
int			ft_export(char	**args);
int			ft_exit(char **args);

#endif
