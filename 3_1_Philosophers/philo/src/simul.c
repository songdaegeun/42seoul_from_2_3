/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:18:57 by sdg               #+#    #+#             */
/*   Updated: 2023/07/01 22:53:48 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simul_start(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int			i;
	int			dead_id;

	i = 0;
	while (i < rule_info->num_of_philo)
	{
		if (pthread_create(&philo_info[i].tid, 0, philo_thread, \
		(void *)&(philo_info[i])))
			return (4);
		i++;
	}
	dead_id = mornitoring(rule_info, philo_info);
	i = 0;
	while (i < rule_info->num_of_philo)
	{
		pthread_join(philo_info[i++].tid, 0);
	}
	philo_state_print(rule_info, dead_id, "died", 1);
	pthread_mutex_destroy(&rule_info->mutex_print);
	i = -1;
	while (++i < rule_info->num_of_philo)
		mem_release(&philo_info[i], i);
	free(philo_info);
	free(rule_info->mutex_forks);
	return (0);
}

void	*philo_thread(void *init_param)
{
	t_philo_info	*philo_info;
	t_rule_info		*rule_info;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;
	if (philo_info->id % 2)
		usleep(50);
	while (!rule_info->end_flag)
	{
		philo_eating(philo_info);
		if (rule_info->min_times_eat <= philo_info->cnt_eat)
		{
			rule_info->end_philo_cnt++;
		}
		philo_state_print(rule_info, philo_info->id, "is sleeping", 0);
		philo_info->prev_sleep_start_time = get_milli_time();
		wait_duration(rule_info->time_to_sleep, philo_info, 2);
		philo_state_print(rule_info, philo_info->id, "is thinking", 0);
		usleep(50);
	}
	return (0);
}

int	mornitoring(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int			i;
	long long	now;

	while (!rule_info->end_flag)
	{
		if (rule_info->min_times_eat != -1 && rule_info->num_of_philo == \
		rule_info->end_philo_cnt)
		{
			rule_info->end_flag = 1;
			return (-1);
		}
		i = -1;
		while (++i < rule_info->num_of_philo)
		{
			now = get_milli_time();
			if ((now - philo_info[i].prev_eat_start_time) >= \
			rule_info->time_to_die)
			{
				rule_info->end_flag = 1;
				return (i);
			}
		}
		usleep(2000);
	}
	return (-1);
}
