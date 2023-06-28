/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:19:45 by sdg               #+#    #+#             */
/*   Updated: 2023/06/28 22:24:05 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_philo_info *philo_info)
{
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	if (philo_info->id != (rule_info->num_of_philo - 1))
	{
		printf("hi1\n");
		// printf("id is not last: %d\n", philo_info->id + 1);
		pthread_mutex_lock(&rule_info->mutex_forks[philo_info->left_id]);
		if (rule_info->end_flag == 1)
			return ;
		philo_state_print(rule_info, philo_info->id, "has taken a fork");
		// philo_state_print(rule_info, philo_info->id, "has taken a left fork");
		pthread_mutex_lock(&(rule_info->mutex_forks[philo_info->right_id]));
		if (rule_info->end_flag == 1)
			return ;
		philo_state_print(rule_info, philo_info->id, "has taken a fork");
		// philo_state_print(rule_info, philo_info->id, "has taken a right fork");
		philo_state_print(rule_info, philo_info->id, "is eating");
		philo_info->prev_eat_start_time = get_milli_time();
		philo_info->cnt_eat++;
		wait_duration(rule_info->time_to_eat, philo_info);
		// usleep(rule_info->time_to_eat * 1000);
		pthread_mutex_unlock(&rule_info->mutex_forks[philo_info->left_id]);
		pthread_mutex_unlock(&(rule_info->mutex_forks[philo_info->right_id]));
	}
	else
	{
		pthread_mutex_lock(&rule_info->mutex_forks[philo_info->right_id]);
		if (rule_info->end_flag == 1)
			return ;
		philo_state_print(rule_info, philo_info->id, "has taken a fork");
		// philo_state_print(rule_info, philo_info->id, "has taken a right fork");
		pthread_mutex_lock(&(rule_info->mutex_forks[philo_info->left_id]));
		if (rule_info->end_flag == 1)
			return ;
		philo_state_print(rule_info, philo_info->id, "has taken a fork");
		// philo_state_print(rule_info, philo_info->id, "has taken a left fork");
		philo_state_print(rule_info, philo_info->id, "is eating");
		philo_info->prev_eat_start_time = get_milli_time();
		philo_info->cnt_eat++;
		wait_duration(rule_info->time_to_eat, philo_info);
		// usleep(rule_info->time_to_eat * 1000);
		pthread_mutex_unlock(&rule_info->mutex_forks[philo_info->right_id]);
		pthread_mutex_unlock(&(rule_info->mutex_forks[philo_info->left_id]));
	}
}

void	wait_duration(int duration, t_philo_info *philo_info)
{
	long long	target;
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	target = duration + philo_info->prev_eat_start_time;
	while (!rule_info->end_flag && target > get_milli_time())
	{
		usleep(10);
	}
}
