/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:29:43 by seykim            #+#    #+#             */
/*   Updated: 2023/09/18 13:29:44 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_signal.h"

t_bool	*get_is_subshell(void)
{
	static t_bool	is_subshell;

	return (&is_subshell);
}

void	set_is_subshell(t_bool flag)
{
	*get_is_subshell() = flag;
}
