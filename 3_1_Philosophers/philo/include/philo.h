/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:15 by dasong            #+#    #+#             */
/*   Updated: 2023/07/05 21:29:22 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <libft.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_rule_info {
	long long		start_time;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_times_eat;
	int				end_philo_cnt;
	int				end_flag;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_end_flag;
	pthread_mutex_t	mutex_monitor;
	pthread_mutex_t	*mutex_forks;
}	t_rule_info;

typedef struct s_philo_info {
	int			id;
	int			left_id;
	int			right_id;
	long long	prev_eat_start_time;
	long long	prev_sleep_start_time;
	int			cnt_eat;
	pthread_t	tid;
	t_rule_info	*rule;
}	t_philo_info;

int			rule_init(int argc, char **argv, t_rule_info *rule_info);
int			mutex_set(t_rule_info *rule_info);
int			philo_init(t_rule_info *rule_info, t_philo_info **philo_info);
int			simul_start(t_rule_info *rule_info, t_philo_info *philo_info);
void		*philo_thread(void *init_param);
int			mornitoring(t_rule_info *rule_info, t_philo_info *philo_info);
void		philo_eating(t_philo_info *philo_info);
void		wait_duration(long long duration, t_philo_info *philo_info, \
int flag);
void		philo_state_print(t_rule_info *rule_info, int id, \
const char*str, int flag);
long long	get_micro_time(void);
void		mem_release(t_philo_info *philo_info);
void		even_eating(t_philo_info *philo_info);
void		odd_eating(t_philo_info *philo_info);
void		philo_thread_loop(t_rule_info *rule_info, t_philo_info *philo_info);
int			monitor_min_times_eat(t_rule_info	*rule_info);
int			monitor_die(t_philo_info *philo_info);

#endif