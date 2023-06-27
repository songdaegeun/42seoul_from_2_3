/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:19 by dasong            #+#    #+#             */
/*   Updated: 2023/06/23 14:06:20 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

#include "philo.h"

void error_exit(const char *str) {
    printf(str);
    exit(1);
}
void init(int argc, char **argv, t_philo_info *philo_info) {
    philo_info->num_of_philo = ft_atoi(argv[1]);
    philo_info->time_to_die = ft_atoi(argv[2]);
    philo_info->time_to_eat = ft_atoi(argv[3]);
    philo_info->time_to_sleep = ft_atoi(argv[4]);
    if(argc == 6) {
        philo_info->min_times_eat = ft_atoi(argv[5]);
    }
    philo_state *state = (philo_state *)malloc(num_of_philo * sizeof(philo_state));
    if(!state) {
        error_exit("memory allocation fail\n");
    }
    pthread_cond_t *cond_vars = (pthread_cond_t *)malloc(num_of_philo * sizeof(pthread_cond_t));
    if(!cond_vars) {
        error_exit("memory allocation fail\n");
    }

    for (int i = 0; i < num_of_philo; i++)
    {
        state[i] = THINK;
    }

    pthread_mutex_t = mutex_lock;

}

int main(int argc, char **argv)
{
    if (!(argc == 5 || argc == 6)) {
        error_exit("format error\n");
    }
    t_philo_info philo_info;
    pthread_t = tid;
    init(argc, argv, &philo_info);
    for (size_t i = 0; i < count; i++)
    {
        tid
        // philo thread create 
    }
    for (size_t i = 0; i < count; i++)
    {
        // philo thread join
    }
    
    
    // getFork();
    // eating();
    // putFork();
    // sleeping();
    // thinking();

    return (0);
}