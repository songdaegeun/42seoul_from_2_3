/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:18:57 by sdg               #+#    #+#             */
/*   Updated: 2023/07/03 22:53:17 by dasong           ###   ########.fr       */
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
		else
			philo_info[i].pid = pid;
		i++;
	}
	wait_kill_sig(philo_info);
	sem_close(rule_info->sem_lock);
	sem_unlink("sem_fork");
	free(philo_info);
	return (0);
}

void	*philo_routine(void *init_param)
{
	t_philo_info	*philo_info;
	t_rule_info		*rule_info;
	long long		prev_eat_start_time;
	int				end_flag;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;
	rule_info->end_flag = &end_flag;
	*(rule_info->end_flag) = 0;
	philo_info->prev_eat_start_time = &prev_eat_start_time;
	*(philo_info->prev_eat_start_time) = rule_info->start_time;
	if (pthread_create(&philo_info->tid, 0, mornitoring, (void *)philo_info))
		return (0);
	if (rule_info->num_of_philo == 1)
	{
		sem_wait(rule_info->sem_lock);
		philo_state_print(rule_info, philo_info->id, "has taken a fork");
		while (!*(rule_info->end_flag))
			;
	}
	else
		philo_routine_loop(rule_info, philo_info);
	exit(philo_info->id);
	return (0);
}

void	*mornitoring(void *init_param)
{
	long long		now;
	t_rule_info		*rule_info;
	t_philo_info	*philo_info;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;
	while (!*(rule_info->end_flag))
	{
		now = get_micro_time();
		if ((now - *(philo_info->prev_eat_start_time)) >= \
		rule_info->time_to_die * 1000)
		{
			*(rule_info->end_flag) = 1;
		}
		usleep(1000);
	}
	return (0);
}

void	philo_routine_loop(t_rule_info *rule_info, t_philo_info *philo_info)
{
	if (philo_info->id % 2 || (philo_info->id + 1) == rule_info->num_of_philo)
	{
		usleep(100);
		if ((philo_info->id + 1) == rule_info->num_of_philo)
			usleep(100);
	}
	while (!*(rule_info->end_flag))
	{
		philo_eating(philo_info);
		philo_state_print(rule_info, philo_info->id, "is sleeping");
		philo_info->prev_sleep_start_time = get_micro_time();
		wait_duration(rule_info->time_to_sleep * 1000LL, philo_info, 2);
		philo_state_print(rule_info, philo_info->id, "is thinking");
		if (rule_info->min_times_eat == philo_info->cnt_eat)
		{
			exit(255);
		}
		usleep(100);
	}
}

void	wait_kill_sig(t_philo_info *philo_info)
{	
	int			sig;
	int			status;
	int			i;
	t_rule_info	*rule_info;

	rule_info = philo_info->rule;
	i = -1;
	while (++i < rule_info->num_of_philo)
	{
		if (waitpid(-1, &status, 0) < 0)
			return ;
		sig = WEXITSTATUS(status);
		if (sig != 255)
			break ;
	}
	if (sig != 255)
	{
		i = -1;
		while (++i < rule_info->num_of_philo)
			kill(philo_info[i].pid, 15);
		i = -1;
		while (++i < rule_info->num_of_philo)
			waitpid(philo_info[i].pid, 0, 0);
		philo_state_print(rule_info, sig, "died");
	}
}
