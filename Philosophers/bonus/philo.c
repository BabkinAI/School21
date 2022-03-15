/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:00:11 by kmars             #+#    #+#             */
/*   Updated: 2021/08/17 15:10:29 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	help_philo_do(t_philo *philosopher, t_time time)
{
	int	eat;

	sem_wait(philosopher->etiquette);
	sem_wait(philosopher->sem);
	sem_wait(philosopher->talk);
	printf("%ld ms Philo_%d has taken a fork\n",
		time_stop(time), philosopher->number);
	sem_post(philosopher->talk);
	sem_wait(philosopher->sem);
	sem_wait(philosopher->talk);
	printf("%ld ms Philo_%d has taken a fork\n",
		time_stop(time), philosopher->number);
	printf("%ld ms Philo_%d is eating\n",
		time_stop(time), philosopher->number);
	sem_post(philosopher->talk);
	philosopher->dead_incoming = time_start();
	eat = time_stop(time);
	while (time_stop(time) - eat < philosopher->tte)
		usleep(400);
	sem_post(philosopher->sem);
	sem_post(philosopher->sem);
	sem_post(philosopher->etiquette);
	philosopher->meals_amount++;
}

static void	philo_do(t_philo *philosopher)
{
	t_time	time;
	int		sleep;

	time = time_start();
	philosopher->start = time_start();
	while (1)
	{
		help_philo_do(philosopher, time);
		sem_wait(philosopher->talk);
		printf("%ld ms Philo_%d is sleeping\n",
			time_stop(time), philosopher->number);
		sem_post(philosopher->talk);
		sleep = time_stop(time);
		while (time_stop(time) - sleep < philosopher->tts)
			usleep(400);
		sem_wait(philosopher->talk);
		printf("%ld ms Philo_%d is thinking\n",
			time_stop(time), philosopher->number);
		sem_post(philosopher->talk);
	}
}

void	philo(t_philo	*philosopher, int argc)
{
	usleep((philosopher->amount - philosopher->number) * 150);
	if (argc == 6)
		pthread_create(&philosopher->thread, NULL, philo_check_2, philosopher);
	else
		pthread_create(&philosopher->thread, NULL, philo_check_1, philosopher);
	philosopher->dead_incoming = time_start();
	philo_do(philosopher);
	pthread_join(philosopher->thread, NULL);
}

static void	start(t_philo *philosophers, char **argv, int argc)
{
	int			i;
	int			pid;
	pthread_t	waiter;

	i = 0;
	pid = 1;
	waiter = NULL;
	while ((i < ft_atoi(argv[1])) && (pid))
	{
		i++;
		philosophers[i - 1].start = time_start();
		philosophers[i - 1].pid = fork();
		pid = philosophers[i - 1].pid;
	}
	if (!pid)
		philo(&philosophers[i - 1], argc);
	else
	{
		waiter_join(waiter, philosophers, argc);
		waitpid(-1, NULL, 0);
		dead(philosophers, ft_atoi(argv[1]));
	}
}

int	main(int argc, char **argv)
{
	t_philo			*philosophers;
	t_imaphores		simaphores;

	chek_input(argc, argv);
	unlink_philo();
	simaphores.sem = sem_open("/semaphor", O_CREAT, 0666, ft_atoi(argv[1]));
	simaphores.talk = sem_open("/talk", O_CREAT, 0666, 1);
	if (ft_atoi(argv[1]) % 2)
		simaphores.etiquette = sem_open("/etiquette", O_CREAT, 0666,
				(ft_atoi(argv[1]) / 2 + 1));
	else
		simaphores.etiquette = sem_open("/etiquette", O_CREAT, 0666,
				(ft_atoi(argv[1]) / 2));
	if ((simaphores.sem == SEM_FAILED) || (simaphores.etiquette == SEM_FAILED)
		|| (simaphores.talk == SEM_FAILED))
		return (0);
	philosophers = philo_init(argv, simaphores, argc);
	if (!philosophers)
		return (0);
	start(philosophers, argv, argc);
}
