/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:18:57 by sdg               #+#    #+#             */
/*   Updated: 2023/07/05 21:47:16 by dasong           ###   ########.fr       */
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
		pthread_join(philo_info[i++].tid, 0);
	philo_state_print(rule_info, dead_id, "died", 1);
	mem_release(philo_info);
	return (0);
}

void	*philo_thread(void *init_param)
{
	t_philo_info	*philo_info;
	t_rule_info		*rule_info;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;
	if (rule_info->num_of_philo == 1)
	{
		pthread_mutex_lock(&rule_info->mutex_forks[philo_info->left_id]);
		philo_state_print(rule_info, philo_info->id, "has taken a fork", 0);
		pthread_mutex_lock(&rule_info->mutex_end_flag);
		while (!rule_info->end_flag)
		{
			pthread_mutex_unlock(&rule_info->mutex_end_flag);
			pthread_mutex_lock(&rule_info->mutex_end_flag);
		}
		pthread_mutex_unlock(&rule_info->mutex_end_flag);
	}
	else
		philo_thread_loop(rule_info, philo_info);
	return (0);
}

int	mornitoring(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int			ret;

	pthread_mutex_lock(&rule_info->mutex_monitor);
	pthread_mutex_lock(&rule_info->mutex_end_flag);
	while (!rule_info->end_flag)
	{
		if (monitor_min_times_eat(rule_info) < 0)
			return (-1);
		ret = monitor_die(philo_info);
		if (ret >= 0)
			return (ret);
		pthread_mutex_unlock(&rule_info->mutex_monitor);
		pthread_mutex_unlock(&rule_info->mutex_end_flag);
		usleep(1000);
		pthread_mutex_lock(&rule_info->mutex_monitor);
		pthread_mutex_lock(&rule_info->mutex_end_flag);
	}
	pthread_mutex_unlock(&rule_info->mutex_monitor);
	pthread_mutex_unlock(&rule_info->mutex_end_flag);
	return (-1);
}

int	monitor_min_times_eat(t_rule_info	*rule_info)
{
	if (rule_info->min_times_eat != -1 && rule_info->num_of_philo == \
	rule_info->end_philo_cnt)
	{
		rule_info->end_flag = 1;
		pthread_mutex_unlock(&rule_info->mutex_monitor);
		pthread_mutex_unlock(&rule_info->mutex_end_flag);
		return (-1);
	}
	return (0);
}

int	monitor_die(t_philo_info *philo_info)
{
	int			i;
	long long	now;
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	i = -1;
	while (++i < rule_info->num_of_philo)
	{
		now = get_micro_time();
		if ((now - philo_info[i].prev_eat_start_time) >= \
		rule_info->time_to_die * 1000)
		{
			rule_info->end_flag = 1;
			pthread_mutex_unlock(&rule_info->mutex_monitor);
			pthread_mutex_unlock(&rule_info->mutex_end_flag);
			return (i);
		}
	}
	return (-1);
}
