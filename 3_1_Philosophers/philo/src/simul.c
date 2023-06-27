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
        if (pthread_create(&philo_info[i].tid, 0, philo_thread, (void *)&(philo_info[i])))
			return (4);
		i++;
	}
	simul_end_check(rule_info, philo_info);
	i = 0;
    while (i < rule_info->num_of_philo)
        pthread_join(philo_info[i++].tid, 0);
	i = 0;
	while (i < rule_info->num_of_philo)

}


void	simul_end_check(t_rule_info *rule_info, t_philo_info *philo_info)
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
				philo_state_print(timestamp, i, "died");
				rule_info->end_flag = 1;
			}
			i++;
		}
	}
}

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
	t_rule_info		*rule_info;

	philo_info = (t_philo_info *)init_param;
	rule_info = philo_info->rule;
    while (!rule_info->end_flag)
	{
		// mutex
        philo_act(philo_info);
		//mutex
		// philo가 식사한 횟수가 최소 식사횟수 조건에 도달하면 해당 philo는 종료조건 충족.
		if (rule_info->min_times_eat == philo_info->cnt_eat)
		{
			rule_info->end_philo_cnt++;
		}
		philo_state_print(timestamp, philo_info->id, "sleeping");
		// sleeping
		sleeping(rule_info);
		philo_state_print(timestamp, philo_info->id, "thinking");
		
    }
    
}
void	ft_pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (!(arg->finish))
	{
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}


void	sleeping(t_rule_info *rule_info)
{
	int	now;
	int	start;

	start = get_milli_time();
	while (!rule_info->end_flag)
	{
		now = get_milli_time();
		if ((now - start) >= rule_info->time_to_sleep)
			break;
		usleep();
	}
}

// void thinking() {
//     printf("%d %d is thinking\n", timestamp_in_ms, id);
// }

// void eating() {
//     printf("%d %d is eating\n", timestamp_in_ms, id);
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



// void thinking() {
//     printf("%d %d is thinking\n", timestamp_in_ms, id);
// }

void	philo_state_print(int timestamp, int id, const char*str)
{
	printf("%d %d is %s\n", timestamp, id, str);
}

int	get_milli_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, 0);
	return (mytime.tv_usec / 1000);
}
// void	ft_philo_check_finish(t_arg *arg, t_philo *philo)
// {
// 	int			i;
// 	long long	now;

// 	while (!arg->finish)
// 	{
// 		if ((arg->eat_times != 0) && (arg->philo_num == arg->finished_eat))
// 		{
// 			arg->finish = 1;
// 			break ;
// 		}
// 		i = 0;
// 		while (i < arg->philo_num)
// 		{
// 			now = ft_get_time();
// 			if ((now - philo[i].last_eat_time) >= arg->time_to_die)
// 			{
// 				ft_philo_printf(arg, i, "died");
// 				arg->finish = 1;
// 				break ;
// 			}
// 			i++;
// 		}
// 	}
// }
