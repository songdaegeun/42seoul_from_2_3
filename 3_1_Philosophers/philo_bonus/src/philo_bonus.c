/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:19 by dasong            #+#    #+#             */
/*   Updated: 2023/07/01 15:49:55 by dasong           ###   ########.fr       */
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
	int	errno;

	rule_info->start_time = get_milli_time();
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
	errno = mutex_set(rule_info);
	if (errno)
		return (errno);
	return (0);
}

int	mutex_set(t_rule_info *rule_info)
{
	int	i;

	if (pthread_mutex_init(&rule_info->mutex_print, 0) == -1)
		return (3);
	rule_info->mutex_forks = (pthread_mutex_t *)malloc(rule_info->num_of_philo \
	* sizeof(pthread_mutex_t));
	if (!rule_info->mutex_forks)
		return (1);
	i = 0;
	while (i < rule_info->num_of_philo)
	{
		if (pthread_mutex_init(&rule_info->mutex_forks[i], 0) == -1)
			return (3);
		i++;
	}
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
		(*philo_info)[i].left_id = i;
		(*philo_info)[i].right_id = (i + 1) % rule_info->num_of_philo;
		(*philo_info)[i].prev_eat_start_time = rule_info->start_time;
		(*philo_info)[i].cnt_eat = 0;
		(*philo_info)[i].rule = rule_info;
		i++;
	}
	return (0);
}
