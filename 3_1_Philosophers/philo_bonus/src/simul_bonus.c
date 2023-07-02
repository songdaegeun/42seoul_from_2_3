/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:18:57 by sdg               #+#    #+#             */
/*   Updated: 2023/07/03 04:31:50 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	simul_start(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int			i;
	pid_t		pid;

	i = 0;
	while (i < rule_info->num_of_philo)
	{
		pid = fork();
		if (pid < 0)
			return (6);
		if (pid == 0)
			philo_routine(&philo_info[i]);
		i++;
	}
	wait_kill_sig(rule_info);
	sem_close(rule_info->sem_lock);
	sem_unlink("sem_fork");
	free(philo_info);
	return (0);
}

void	*philo_routine(void *init_param)
{
	t_philo_info	*philo_info;
	t_rule_info		*rule_info;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;
	if (rule_info->num_of_philo == 1)
	{
		sem_wait(rule_info->sem_lock);
		philo_state_print(rule_info, philo_info->id, "has taken a fork");
		while (!rule_info->end_flag)
			;
	}
	else
		philo_routine_loop(rule_info, philo_info);
	if (rule_info->min_times_eat != -1 && rule_info->num_of_philo == \
		rule_info->end_philo_cnt) {
		exit(-1);
	}
	else
		exit(philo_info->id);
	return (0);
}

void	*mornitoring(void *init_param)
{
	int				i;
	long long		now;
	t_rule_info		*rule_info;
	t_philo_info	*philo_info;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;

	while (!rule_info->end_flag)
	{
		if (rule_info->min_times_eat != -1 && rule_info->num_of_philo == \
		rule_info->end_philo_cnt)
			rule_info->end_flag = 1;
		i = -1;
		while (++i < rule_info->num_of_philo)
		{
			now = get_micro_time();
			if ((now - philo_info[i].prev_eat_start_time) >= \
			rule_info->time_to_die * 1000)
				rule_info->end_flag = 1;
		}
		usleep(1000);
	}
	return (0);
}

void	philo_routine_loop(t_rule_info *rule_info, t_philo_info *philo_info)
{
	if (pthread_create(&philo_info->tid, 0, mornitoring, (void *)philo_info))
		return ;
	if (philo_info->id % 2 || (philo_info->id + 1) == rule_info->num_of_philo)
	{
		usleep(100);
		if ((philo_info->id + 1) == rule_info->num_of_philo)
			usleep(50);
	}
	while (!rule_info->end_flag)
	{
		philo_eating(philo_info);
		if (rule_info->min_times_eat == philo_info->cnt_eat)
		{
			rule_info->end_philo_cnt++;
		}
		philo_state_print(rule_info, philo_info->id, "is sleeping");
		philo_info->prev_sleep_start_time = get_micro_time();
		wait_duration(rule_info->time_to_sleep * 1000LL, philo_info, 2);
		philo_state_print(rule_info, philo_info->id, "is thinking");
		usleep(100);
	}
}

void	wait_kill_sig(t_rule_info *rule_info)
{
	int	sig;

	sig = wait(0);
	printf("sig: %d\n", sig);
	if(sig == -1)
	{
		// 모든 process kill
		// kill();
		printf("times of philo eat\n");
	}
	else
	{
		// 모든 process kill
		// kill();
		printf("philo die\n");
		// 모든 process가 kill되었다면
		philo_state_print(rule_info, sig, "died");
	}
}