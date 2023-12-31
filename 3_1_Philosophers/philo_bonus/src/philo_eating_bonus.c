/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:19:45 by sdg               #+#    #+#             */
/*   Updated: 2023/07/04 00:20:14 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_wait(rule_info->sem_monitor);
	if (flag == 1)
		target = duration + philo_info->prev_eat_start_time;
	else if (flag == 2)
		target = duration + philo_info->prev_sleep_start_time;
	sem_post(rule_info->sem_monitor);
	sem_wait(rule_info->sem_end_flag);
	while (!rule_info->end_flag && target >= get_micro_time())
	{
		sem_post(rule_info->sem_end_flag);
		usleep(100 * rule_info->num_of_philo * 10 / 200);
		sem_wait(rule_info->sem_end_flag);
	}
	sem_post(rule_info->sem_end_flag);
}

void	odd_eating(t_philo_info *philo_info)
{
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	sem_wait(rule_info->sem_lock);
	philo_state_print(rule_info, philo_info->id, "has taken a fork");
	sem_wait(rule_info->sem_lock);
	philo_state_print(rule_info, philo_info->id, "has taken a fork");
	philo_state_print(rule_info, philo_info->id, "is eating");
	sem_wait(rule_info->sem_monitor);
	philo_info->prev_eat_start_time = get_micro_time();
	sem_post(rule_info->sem_monitor);
	wait_duration(rule_info->time_to_eat * 1000LL, philo_info, 1);
	philo_info->cnt_eat++;
	sem_post(rule_info->sem_lock);
	sem_post(rule_info->sem_lock);
}

void	even_eating(t_philo_info *philo_info)
{
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	sem_wait(rule_info->sem_lock);
	philo_state_print(rule_info, philo_info->id, "has taken a fork");
	sem_wait(rule_info->sem_lock);
	philo_state_print(rule_info, philo_info->id, "has taken a fork");
	philo_state_print(rule_info, philo_info->id, "is eating");
	sem_wait(rule_info->sem_monitor);
	philo_info->prev_eat_start_time = get_micro_time();
	sem_post(rule_info->sem_monitor);
	wait_duration(rule_info->time_to_eat * 1000LL, philo_info, 1);
	philo_info->cnt_eat++;
	sem_post(rule_info->sem_lock);
	sem_post(rule_info->sem_lock);
}
