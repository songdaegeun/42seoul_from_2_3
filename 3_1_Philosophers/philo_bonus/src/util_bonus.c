/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:21:18 by sdg               #+#    #+#             */
/*   Updated: 2023/07/03 15:02:21 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_state_print(t_rule_info *rule_info, int id, const char*str)
{
	long long	time_stamp;

	if (id < 0)
		return ;
	time_stamp = (get_micro_time() - rule_info->start_time) / 1000;
	printf("%lld %d %s\n", time_stamp, id + 1, str);
}

long long	get_micro_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, 0);
	return ((mytime.tv_sec * 1000000LL + mytime.tv_usec));
}
