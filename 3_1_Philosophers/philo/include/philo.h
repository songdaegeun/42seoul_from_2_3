/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:15 by dasong            #+#    #+#             */
/*   Updated: 2023/06/23 14:03:19 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
typedef enum {
    THINK,
    EAT,
    SLEEP
} philo_state;

typedef struct s_rule_info {
    int start_time;
    int num_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int min_times_eat;
}   t_rule_info;

typedef struct s_philo_info {
    int id;
    int left_id;
    int right_id;
    int prev_eat_start_time;
    int cnt_eat;
}   t_philo_info;

#endif