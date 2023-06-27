#include "philo.h"

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

int	simul_start(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int			i;

	i = 0;
	while (i < rule_info->num_of_philo)
	{
		if (pthread_create(&philo_info[i].tid, 0, philo_thread, \
		(void *)&(philo_info[i])))
			return (4);
		i++;
	}
	mornitoring(rule_info, philo_info);
	i = 0;
	// 모든 philo가 died를 출력할때까지 join으로 기다린다.
	while (i < rule_info->num_of_philo)
		pthread_join(philo_info[i++].tid, 0);
	pthread_mutex_destroy(&rule_info->mutex_print);
	i = 0;
	while (i < rule_info->num_of_philo)
		mem_release(&philo_info[i], i);
	free(philo_info);
	free(rule_info->mutex_forks);
	return (0);
}

void	mem_release(t_philo_info *philo_info, int i)
{
	t_rule_info		*rule_info;

	rule_info = philo_info->rule;
	pthread_mutex_destroy(&rule_info->mutex_forks[i]);
}

void	mornitoring(t_rule_info *rule_info, t_philo_info *philo_info)
{
	int	i;
	int	now;

	while (!rule_info->end_flag)
	{
		if (rule_info->min_times_eat != -1 && rule_info->num_of_philo == rule_info->end_philo_cnt)
			rule_info->end_flag = 1;
		i = 0;
		while (i < rule_info->num_of_philo)
		{
			now = get_milli_time();
			if ((now - philo_info[i].prev_eat_start_time) >= rule_info->time_to_die)
			{
				philo_state_print(rule_info, i, "died");
				rule_info->end_flag = 1;
			}
			i++;
		}
		// usleep(10)?
	}
}

void	*philo_thread(void *init_param)
{
	t_philo_info	*philo_info;
	t_rule_info		*rule_info;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;
	while (!rule_info->end_flag)
	{
		philo_eating(philo_info);
		// philo가 식사한 횟수가 최소 식사횟수 조건에 도달하면 해당 philo는 종료조건 충족.
		if (rule_info->min_times_eat == philo_info->cnt_eat)
		{
			rule_info->end_philo_cnt++;
		}
		philo_state_print(rule_info, philo_info->id, "sleeping");
		// wait(rule_info->time_to_eat + rule_info->time_to_sleep, philo_info);
		usleep(rule_info->time_to_sleep * 1000);
		philo_state_print(rule_info, philo_info->id, "thinking");
	}
}

int	get_milli_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, 0);
	return (mytime.tv_usec / 1000);
}
