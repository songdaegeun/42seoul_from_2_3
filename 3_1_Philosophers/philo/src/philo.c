/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:19 by dasong            #+#    #+#             */
/*   Updated: 2023/06/27 20:58:22 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
// ./philo 5 1 1 1 1  

#include "philo.h"

int	mutex_set(t_rule_info *rule_info)
{
	int	i;

	if (pthread_mutex_init(&rule_info->mutex_print, 0) == -1)
		return (3);
	rule_info->mutex_forks = (pthread_mutex_t *)malloc(rule_info->num_of_philo * sizeof(pthread_mutex_t));
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
	}
	if (rule_info->num_of_philo <= 0 || rule_info->time_to_die < 0 || \
	rule_info->time_to_eat < 0 || rule_info->time_to_sleep < 0)
		return (2);
	errno = mutex_set(rule_info);
	if (errno)
		return (errno);
    return (0);
}

int	philo_init(t_rule_info *rule_info, t_philo_info **philo_info)
{
	int	i;

	*philo_info = (t_philo_info *)malloc(rule_info->num_of_philo * sizeof(t_philo_info));
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
		(*philo_info)[i].prev_eat_start_time = 0;
		(*philo_info)[i].cnt_eat = 0;
		i++;
	}
	return (0);
}

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
		printf("[%d]error\n", errno);
		return (0);
	}
	errno = philo_init(&rule_info, &philo_info);
	if (errno)
	{
		printf("[%d]error\n", errno);
		return (0);
	}
	simul_start(&rule_info, philo_info);
	return (0);
}


// int	ft_philo_start(t_arg *arg, t_philo *philo)
// {
// 	int		i;

// 	i = 0;
// 	while (i < arg->philo_num)
// 	{	
// 		philo[i].last_eat_time = ft_get_time();
// 		if (pthread_create(&(philo[i].thread), NULL, ft_thread, &(philo[i])))
// 			return (1);
// 		i++;
// 	}
// 	ft_philo_check_finish(arg, philo);
// 	i = 0;
// 	while (i < arg->philo_num)
// 		pthread_join(philo[i++].thread, NULL);
// // 조인을 안하면 프로그램이 먼저 종료되서 쓰레드가 진행되지 않는다.
// 	ft_free_thread(arg, philo);
// 	return (0);
// }


// void	*ft_thread(void *argv)
// {
// 	t_arg		*arg;
// 	t_philo		*philo;

// 	philo = argv;
// 	arg = philo->arg;
// 	if (philo->id % 2)
// 		usleep(1000);
// 	while (!arg->finish)
// 	{
// 		ft_philo_action(arg, philo);
// 		if (arg->eat_times == philo->eat_count)
// 		{
// 			arg->finished_eat++;
// 			break ;
// 		}
// 		ft_philo_printf(arg, philo->id, "is sleeping");
// 		ft_pass_time((long long)arg->time_to_sleep, arg);
// 		ft_philo_printf(arg, philo->id, "is thinking");
// 	}
// 	return (0);
// }


void	*philo_thread(void *init_param)
{
	t_philo_info	*philo_info;

	philo_info = (t_philo_info *)init_param;
    while (1)
	{
        philo_act();
    }
    
}


// void thinking() {
//     printf("%d %d is thinking\n", timestamp_in_ms, id);
// }

// void eating() {
//     printf("%d %d is eating\n", timestamp_in_ms, id);
// }

// void sleeping() {
//     printf("%d %d is sleeping\n", timestamp_in_ms, id);
// }

// void getFork() {
//     // left_getFork
//     // right_getFork
// }


// void left_getFork() {
//     printf("%d %d has taken a fork\n", timestamp_in_ms, id);
// }

// void right_getFork() {
//     printf("%d %d has taken a fork\n", timestamp_in_ms, id);
// }
