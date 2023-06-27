#include "philo.h"

void	simul_start(t_rule_info *rule_info, t_philo_info *philo_info)
{
	pthread_t	tid;
	int			i;

	i = 0;
	while (i < rule_info->num_of_philo)
	{
        pthread_create(&tid, 0, philo_thread, (void *)&(philo_info[i]));
		i++;
	}
	
	i = 0;
    while (i < rule_info->num_of_philo)
    {
        pthread_join(tid, 0);
		i++;
    }
}


void	simul_end(t_rule_info *rule_info, t_philo_info *philo_info)
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
