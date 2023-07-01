/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:21:18 by sdg               #+#    #+#             */
/*   Updated: 2023/07/01 15:49:49 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_state_print(t_rule_info *rule_info, int id, const char*str)
{
	long long	time_stamp;

	pthread_mutex_lock(&rule_info->mutex_print);
	time_stamp = get_milli_time() - rule_info->start_time;
	if (rule_info->end_flag != 1)
		printf("%lld %d %s\n", time_stamp, id + 1, str);
	pthread_mutex_unlock(&rule_info->mutex_print);
}

long long	get_milli_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, 0);
	return ((mytime.tv_sec * 1000000LL + mytime.tv_usec) / 1000);
}

void	mem_release(t_philo_info *philo_info, int i)
{
	t_rule_info		*rule_info;

	rule_info = philo_info->rule;
	pthread_mutex_destroy(&rule_info->mutex_forks[i]);
}
