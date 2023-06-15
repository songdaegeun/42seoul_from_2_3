/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 04:32:42 by dasong            #+#    #+#             */
/*   Updated: 2023/06/02 15:57:04 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_buff
{
	char	*buff;
	int		size;
	int		capacity;
}	t_buff;

char	*get_next_line(int fd);
int		init_buff(t_buff *p_buff);
int		ret_buff(t_buff *p_buff, char **res, int *p_size);
int		is_in(t_buff *p_buff, char ch);
int		chk_size(t_buff *p_buff);
int		load_buff(int fd, t_buff *p_buff);

#endif