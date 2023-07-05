/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:19:45 by sdg               #+#    #+#             */
/*   Updated: 2023/07/05 21:44:24 by dasong           ###   ########.fr       */
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

void	odd_eating(t_philo_info *philo_info)
{
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	pthread_mutex_lock(&rule_info->mutex_forks[philo_info->left_id]);
	philo_state_print(rule_info, philo_info->id, "has taken a fork", 0);
	pthread_mutex_lock(&(rule_info->mutex_forks[philo_info->right_id]));
	philo_state_print(rule_info, philo_info->id, "has taken a fork", 0);
	philo_state_print(rule_info, philo_info->id, "is eating", 0);
	pthread_mutex_lock(&rule_info->mutex_monitor);
	philo_info->prev_eat_start_time = get_micro_time();
	pthread_mutex_unlock(&rule_info->mutex_monitor);
	wait_duration(rule_info->time_to_eat * 1000LL, philo_info, 1);
	pthread_mutex_lock(&rule_info->mutex_monitor);
	philo_info->cnt_eat++;
	pthread_mutex_unlock(&rule_info->mutex_monitor);
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
	pthread_mutex_lock(&rule_info->mutex_monitor);
	philo_info->prev_eat_start_time = get_micro_time();
	pthread_mutex_unlock(&rule_info->mutex_monitor);
	wait_duration(rule_info->time_to_eat * 1000LL, philo_info, 1);
	pthread_mutex_lock(&rule_info->mutex_monitor);
	philo_info->cnt_eat++;
	pthread_mutex_unlock(&rule_info->mutex_monitor);
	pthread_mutex_unlock(&rule_info->mutex_forks[philo_info->right_id]);
	pthread_mutex_unlock(&(rule_info->mutex_forks[philo_info->left_id]));
}

void	philo_thread_loop(t_rule_info *rule_info, t_philo_info *philo_info)
{
	if (philo_info->id % 2 || (philo_info->id + 1) == rule_info->num_of_philo)
	{
		usleep(100);
		if ((philo_info->id + 1) == rule_info->num_of_philo)
			usleep(100);
	}
	pthread_mutex_lock(&rule_info->mutex_end_flag);
	while (!rule_info->end_flag)
	{
		pthread_mutex_unlock(&rule_info->mutex_end_flag);
		philo_eating(philo_info);
		pthread_mutex_lock(&rule_info->mutex_monitor);
		if (rule_info->min_times_eat == philo_info->cnt_eat)
			rule_info->end_philo_cnt++;
		pthread_mutex_unlock(&rule_info->mutex_monitor);
		philo_state_print(rule_info, philo_info->id, "is sleeping", 0);
		pthread_mutex_lock(&rule_info->mutex_monitor);
		philo_info->prev_sleep_start_time = get_micro_time();
		pthread_mutex_unlock(&rule_info->mutex_monitor);
		wait_duration(rule_info->time_to_sleep * 1000LL, philo_info, 2);
		philo_state_print(rule_info, philo_info->id, "is thinking", 0);
		usleep(100);
		pthread_mutex_lock(&rule_info->mutex_end_flag);
	}
	pthread_mutex_unlock(&rule_info->mutex_end_flag);
}

void	wait_duration(long long duration, t_philo_info *philo_info, int flag)
{
	long long	target;
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	pthread_mutex_lock(&rule_info->mutex_monitor);
	if (flag == 1)
		target = duration + philo_info->prev_eat_start_time;
	else if (flag == 2)
		target = duration + philo_info->prev_sleep_start_time;
	pthread_mutex_unlock(&rule_info->mutex_monitor);
	pthread_mutex_lock(&rule_info->mutex_end_flag);
	while (!rule_info->end_flag && target >= get_micro_time())
	{
		pthread_mutex_unlock(&rule_info->mutex_end_flag);
		usleep(100 * rule_info->num_of_philo * 10 / 200);
		pthread_mutex_lock(&rule_info->mutex_end_flag);
	}
	pthread_mutex_unlock(&rule_info->mutex_end_flag);
}
