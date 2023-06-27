/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:15 by dasong            #+#    #+#             */
/*   Updated: 2023/06/27 20:56:07 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

#ifndef PHILO_H
# define PHILO_H
#include <libft.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

typedef enum
{
	THINK,
	EAT,
	SLEEP
} philo_state;

typedef struct s_rule_info {
	int				start_time;
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
	int	id;
	int	left_id;
	int	right_id;
	int	prev_eat_start_time;
	int	cnt_eat;
}	t_philo_info;

#endif