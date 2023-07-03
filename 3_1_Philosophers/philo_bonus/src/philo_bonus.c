/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:19 by dasong            #+#    #+#             */
/*   Updated: 2023/07/03 23:51:44 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int				errno;
	t_rule_info		rule_info;
	t_philo_info	*philo_info;

	if (!(argc == 5 || argc == 6))
	{
		printf("format error\n");
		return (0);
	}
	errno = rule_init(argc, argv, &rule_info);
	if (errno)
	{
		if (errno != 5)
			printf("[%d]error\n", errno);
		return (0);
	}
	if (philo_init(&rule_info, &philo_info) || \
	simul_start(&rule_info, philo_info))
	{
		printf("error\n");
		return (0);
	}
	return (0);
}

int	rule_init(int argc, char **argv, t_rule_info *rule_info)
{
	rule_info->start_time = get_micro_time();
	rule_info->end_philo_cnt = 0;
	rule_info->end_flag = 0;
	rule_info->num_of_philo = ft_atoi(argv[1]);
	rule_info->time_to_die = ft_atoi(argv[2]);
	rule_info->time_to_eat = ft_atoi(argv[3]);
	rule_info->time_to_sleep = ft_atoi(argv[4]);
	rule_info->min_times_eat = -1;
	if (argc == 6)
	{
		rule_info->min_times_eat = ft_atoi(argv[5]);
		if (rule_info->min_times_eat < 0)
			return (2);
		else if (rule_info->min_times_eat == 0)
			return (5);
	}
	if (rule_info->num_of_philo <= 0 || rule_info->time_to_die < 0 || \
	rule_info->time_to_eat < 0 || rule_info->time_to_sleep < 0)
		return (2);
	if (sem_set(rule_info))
		return (7);
	return (0);
}

int	philo_init(t_rule_info *rule_info, t_philo_info **philo_info)
{
	int	i;

	*philo_info = (t_philo_info *)malloc(rule_info->num_of_philo * \
	sizeof(t_philo_info));
	if (!*philo_info)
	{
		printf("memory allocation fail\n");
		return (1);
	}
	i = 0;
	while (i < rule_info->num_of_philo)
	{
		(*philo_info)[i].id = i;
		(*philo_info)[i].cnt_eat = 0;
		(*philo_info)[i].rule = rule_info;
		(*philo_info)[i].prev_eat_start_time = rule_info->start_time;
		i++;
	}
	return (0);
}

int	sem_set(t_rule_info *rule_info)
{
	sem_unlink("sem_lock");
	rule_info->sem_lock = sem_open("sem_lock", O_CREAT | O_EXCL, \
	000000644, rule_info->num_of_philo);
	if (rule_info->sem_lock == SEM_FAILED)
		return (7);
	sem_unlink("sem_monitor");
	rule_info->sem_monitor = sem_open("sem_monitor", O_CREAT | O_EXCL, \
	000000644, 1);
	if (rule_info->sem_monitor == SEM_FAILED)
		return (7);
	sem_unlink("sem_end_flag");
	rule_info->sem_end_flag = sem_open("sem_end_flag", O_CREAT | O_EXCL, \
	000000644, 1);
	if (rule_info->sem_end_flag == SEM_FAILED)
		return (7);
	return (0);
}