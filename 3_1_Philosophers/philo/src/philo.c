/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:19 by dasong            #+#    #+#             */
/*   Updated: 2023/06/27 18:25:47 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
// ./philo 5 1 1 1 1  

#include "philo.h"

int rule_init(int argc, char **argv, t_rule_info *rule_info) {
    struct timeval mytime;
	
    gettimeofday(&mytime, 0);
    rule_info->start_time = mytime.tv_usec / 1000;
    rule_info->num_of_philo = ft_atoi(argv[1]);
    rule_info->time_to_die = ft_atoi(argv[2]);
    rule_info->time_to_eat = ft_atoi(argv[3]);
    rule_info->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
	{
        rule_info->min_times_eat = ft_atoi(argv[5]);
        if (rule_info->min_times_eat < 0)
		{
            return (2);
        }
    }
    if (rule_info->num_of_philo <= 0 || rule_info->time_to_die < 0 || rule_info->time_to_eat < 0 || rule_info->time_to_sleep < 0)
	{
		return (2);
	}
   
    // mutex_lock초기화해야함
    // pthread_mutex_t = mutex_lock;    
    return (0);
}

int philo_init(t_rule_info *rule_info, t_philo_info **philo_info)
{
	int	i;

    *philo_info = (t_philo_info *)malloc(rule_info->num_of_philo * sizeof(t_philo_info));
    if(!*philo_info) {
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

int main(int argc, char **argv)
{
    int errno;
    t_rule_info rule_info;
    t_philo_info *philo_info;

    if (!(argc == 5 || argc == 6)) {
        printf("format error\n");
        return (0);
    }

    
    errno = rule_init(argc, argv, &rule_info);
    if (errno) {
        printf("[%d]error\n", errno);
        return (0);
    }
    errno = philo_init(&rule_info, &philo_info);
    if (errno) {
        printf("[%d]error\n", errno);
        return (0);
    }
    // simul_start();

    return (0);
}

// void simul_start(t_rule_info rule_info, t_philo_info *philo_info) {
//     pthread_t = tid;

//     for (int i = 0; i < philo_info.num_of_philo; i++)
//     {
//         pthread_create(&tid, 0, philo_thread, (void *)&(philo_info[i]));
//     }

//     for (int i = 0; i < philo_info.num_of_philo; i++)
//     {
//         pthread_join(tid, 0);
//     }

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


// void *philo_thread(void *init_param) {


//     while(1) {
//         philo_act();
//     }
    
// }



// // timestamp_in_ms X died

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
