/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:15 by dasong            #+#    #+#             */
/*   Updated: 2023/07/03 06:12:23 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <libft.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>        
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
	int				*end_flag;
	sem_t			*sem_lock;
}	t_rule_info;

typedef struct s_philo_info {
	int			id;
	long long	*prev_eat_start_time;
	long long	*prev_sleep_start_time;
	int			cnt_eat;
	pthread_t	tid;
	t_rule_info	*rule;
}	t_philo_info;

int			rule_init(int argc, char **argv, t_rule_info *rule_info);
int			philo_init(t_rule_info *rule_info, t_philo_info **philo_info);
int			simul_start(t_rule_info *rule_info, t_philo_info *philo_info);
void		*philo_routine(void *init_param);
void		*mornitoring(void *init_param);
void		philo_routine_loop(t_rule_info *rule_info, \
t_philo_info *philo_info);
void		wait_kill_sig(t_rule_info *rule_info);
void		philo_state_print(t_rule_info *rule_info, int id, const char*str);
long long	get_micro_time(void);
void		mem_release(t_philo_info *philo_info, int i);
void		philo_eating(t_philo_info *philo_info);
void		wait_duration(long long duration, t_philo_info \
*philo_info, int flag);
void		odd_eating(t_philo_info *philo_info);
void		even_eating(t_philo_info *philo_info);

#endif
