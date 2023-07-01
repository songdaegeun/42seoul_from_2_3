/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:18:57 by sdg               #+#    #+#             */
/*   Updated: 2023/07/01 15:49:51 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	simul_start(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int			i;

	i = 0;
	while (i < rule_info->num_of_philo)
	{
		if (pthread_create(&philo_info[i].tid, 0, philo_thread, \
		(void *)&(philo_info[i])))
			return (4);
		i++;
	}
	mornitoring(rule_info, philo_info);
	i = 0;
	while (i < rule_info->num_of_philo)
	{
		pthread_join(philo_info[i++].tid, 0);
	}
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
	while (!rule_info->end_flag)
	{
		philo_eating(philo_info);
		if (rule_info->min_times_eat <= philo_info->cnt_eat)
		{
			rule_info->end_philo_cnt++;
		}
		philo_state_print(rule_info, philo_info->id, "is sleeping");
		wait_duration(rule_info->time_to_eat + rule_info->time_to_sleep, \
		philo_info);
		philo_state_print(rule_info, philo_info->id, "is thinking");
	}
	return (0);
}

void	mornitoring(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int			i;
	long long	now;

	while (!rule_info->end_flag)
	{
		if (rule_info->min_times_eat != -1 && rule_info->num_of_philo == \
		rule_info->end_philo_cnt)
		{
			rule_info->end_flag = 1;
		}
		i = 0;
		while (i < rule_info->num_of_philo)
		{
			now = get_milli_time();
			if ((now - philo_info[i].prev_eat_start_time) >= \
			rule_info->time_to_die)
			{
				philo_state_print(rule_info, i, "died");
				rule_info->end_flag = 1;
			}
			i++;
		}
	}
}