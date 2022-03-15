/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:22:24 by kmars             #+#    #+#             */
/*   Updated: 2021/08/17 15:26:40 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	help_philo_do(t_philo *philosopher, t_time time)
{
	pthread_mutex_lock(philosopher->first_fork);
	pthread_mutex_lock(philosopher->talk_mutex);
	philo_talk(time, philosopher->talk_fork, philosopher->fork_talk);
	pthread_mutex_unlock(philosopher->talk_mutex);
	pthread_mutex_lock(philosopher->second_fork);
	pthread_mutex_lock(philosopher->talk_mutex);
	philo_talk(time, philosopher->talk_fork, philosopher->fork_talk);
	philo_talk(time, philosopher->talk_eat, philosopher->eat_talk);
	pthread_mutex_unlock(philosopher->talk_mutex);
}

static void	philo_do(t_philo *philosopher)
{
	t_time	time;
	int		eat;
	int		sleep;

	time = time_start();
	while (1)
	{
		help_philo_do(philosopher, time);
		philosopher->dead_incoming = time_start();
		eat = time_stop(time);
		while (time_stop(time) - eat < philosopher->tte)
			usleep(400);
		pthread_mutex_unlock(philosopher->first_fork);
		pthread_mutex_unlock(philosopher->second_fork);
		philosopher->meals_amount++;
		pthread_mutex_lock(philosopher->talk_mutex);
		philo_talk(time, philosopher->talk_sleep, philosopher->sleep_talk);
		pthread_mutex_unlock(philosopher->talk_mutex);
		sleep = time_stop(time);
		while (time_stop(time) - sleep < philosopher->tts)
			usleep(400);
		pthread_mutex_lock(philosopher->talk_mutex);
		philo_talk(time, philosopher->talk_think, philosopher->think_talk);
		pthread_mutex_unlock(philosopher->talk_mutex);
	}
}

void	*philo(void *buf)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)buf;
	philosopher->dead_incoming = time_start();
	philosopher->start = time_start();
	philo_do(philosopher);
	return (buf);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	talk_mutex;
	t_philo			*philosophers;

	if (chek_input(argc, argv))
	{
		printf("Invalid input\n");
		return (0);
	}
	mutex = mutex_init(ft_atoi(argv[1]));
	if (!mutex)
		return (0);
	pthread_mutex_init(&talk_mutex, NULL);
	philosophers = philo_init(argv, mutex, talk_mutex);
	if (!philosophers)
	{
		free(mutex);
		return (0);
	}
	if (argc == 6)
		philo_check_2(philosophers, ft_atoi(argv[1]), ft_atoi(argv[5]));
	else
		philo_check_1(philosophers, ft_atoi(argv[1]));
	philo_join(ft_atoi(argv[1]), philosophers);
	all_free(mutex, philosophers, ft_atoi(argv[1]));
}
