/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:15 by dasong            #+#    #+#             */
/*   Updated: 2023/07/01 17:24:01 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <libft.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_rule_info {
	long long		start_time;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_times_eat;
	int				end_philo_cnt;
	int				end_flag;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
}	t_rule_info;

typedef struct s_philo_info {
	int			id;
	int			left_id;
	int			right_id;
	long long	prev_eat_start_time;
	int			cnt_eat;
	pthread_t	tid;
	t_rule_info	*rule;
}	t_philo_info;


#endif