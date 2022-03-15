/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:28:28 by kmars             #+#    #+#             */
/*   Updated: 2021/08/17 15:24:48 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*all_full(void *buf)
{
	int		i;
	t_philo	*philosophers;

	philosophers = (t_philo *)buf;
	i = 0;
	while (i < philosophers[i].amount)
	{
		sem_wait(philosophers[i].meals);
		i++;
	}
	dead(philosophers, philosophers[i - 1].amount);
	return (buf);
}

void	dead(t_philo	*philosophers, int philo_amount)
{
	int		i;
	char	*str;

	i = 0;
	while (i < philo_amount)
	{
		str = ft_strjoin("/", ft_itoa(i), 1);
		sem_unlink(str);
		free(str);
		kill(philosophers[i].pid, SIGUSR1);
		i++;
	}
	unlink_philo();
	exit(0);
}

void	*philo_check_1(void *buf)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)buf;
	usleep(3000);
	while (1)
	{
		if (time_stop(philosopher->dead_incoming)
			>= philosopher->ttd)
		{
			sem_wait(philosopher->talk);
			printf("%ld ms Philo_%d is dead\n", time_stop(philosopher->start),
				philosopher->number);
			exit(0);
		}
		usleep(500);
	}
}

void	*philo_check_2(void *buf)
{
	t_philo	*philosopher;
	int		swtch;

	swtch = 1;
	philosopher = (t_philo *)buf;
	usleep(3000);
	while (1)
	{
		if (time_stop(philosopher->dead_incoming)
			>= philosopher->ttd)
		{
			sem_wait(philosopher->talk);
			printf("%ld ms Philo_%d is dead\n", time_stop(philosopher->start),
				philosopher->number);
			exit(0);
		}
		if ((philosopher->meals_amount == philosopher->amount_meals) && (swtch))
		{
			sem_post(philosopher->meals);
			swtch = 0;
		}
		usleep(500);
	}
}
