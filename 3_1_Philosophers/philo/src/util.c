/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:21:18 by sdg               #+#    #+#             */
/*   Updated: 2023/07/03 02:40:00 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_state_print(t_rule_info *rule_info, int id, \
const char*str, int flag)
{
	long long	time_stamp;

	if (id < 0 || (rule_info->end_flag && flag == 0))
		return ;
	pthread_mutex_lock(&rule_info->mutex_print);
	time_stamp = (get_micro_time() - rule_info->start_time) / 1000;
	printf("%lld %d %s\n", time_stamp, id + 1, str);
	pthread_mutex_unlock(&rule_info->mutex_print);
}

long long	get_micro_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, 0);
	return ((mytime.tv_sec * 1000000LL + mytime.tv_usec));
}

void	mem_release(t_philo_info *philo_info, int i)
{
	t_rule_info		*rule_info;

	rule_info = philo_info->rule;
	pthread_mutex_destroy(&rule_info->mutex_forks[i]);
}
