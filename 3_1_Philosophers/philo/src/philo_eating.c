/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:19:45 by sdg               #+#    #+#             */
/*   Updated: 2023/07/03 17:55:40 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_philo_info *philo_info)
{
	if (philo_info->id % 2)
		odd_eating(philo_info);
	else
		even_eating(philo_info);
}

void	wait_duration(long long duration, t_philo_info *philo_info, int flag)
{
	long long	target;
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	if (flag == 1)
		target = duration + philo_info->prev_eat_start_time;
	else if (flag == 2)
		target = duration + philo_info->prev_sleep_start_time;
	while (!rule_info->end_flag && target >= get_micro_time())
	{
		usleep(100 * rule_info->num_of_philo * 10 / 200);
	}
}

void	odd_eating(t_philo_info *philo_info)
{
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	pthread_mutex_lock(&rule_info->mutex_forks[philo_info->left_id]);
	philo_state_print(rule_info, philo_info->id, "has taken a fork", 0);
	pthread_mutex_lock(&(rule_info->mutex_forks[philo_info->right_id]));
	philo_state_print(rule_info, philo_info->id, "has taken a fork", 0);
	philo_state_print(rule_info, philo_info->id, "is eating", 0);
	philo_info->prev_eat_start_time = get_micro_time();
	wait_duration(rule_info->time_to_eat * 1000LL, philo_info, 1);
	philo_info->cnt_eat++;
	pthread_mutex_unlock(&rule_info->mutex_forks[philo_info->left_id]);
	pthread_mutex_unlock(&(rule_info->mutex_forks[philo_info->right_id]));
}

void	even_eating(t_philo_info *philo_info)
{
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	pthread_mutex_lock(&rule_info->mutex_forks[philo_info->right_id]);
	philo_state_print(rule_info, philo_info->id, "has taken a fork", 0);
	pthread_mutex_lock(&(rule_info->mutex_forks[philo_info->left_id]));
	philo_state_print(rule_info, philo_info->id, "has taken a fork", 0);
	philo_state_print(rule_info, philo_info->id, "is eating", 0);
	philo_info->prev_eat_start_time = get_micro_time();
	wait_duration(rule_info->time_to_eat * 1000LL, philo_info, 1);
	philo_info->cnt_eat++;
	pthread_mutex_unlock(&rule_info->mutex_forks[philo_info->right_id]);
	pthread_mutex_unlock(&(rule_info->mutex_forks[philo_info->left_id]));
}
