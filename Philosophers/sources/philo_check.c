/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:28:28 by kmars             #+#    #+#             */
/*   Updated: 2021/08/16 17:06:55 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	detach(t_philo	*philosophers, int philo_amount, char swtch)
{
	int	i;

	i = 0;
	if (swtch)
	{
		while (i < philo_amount)
		{
			pthread_detach(philosophers[i].thread);
			i++;
		}
	}
	else
	{
		pthread_mutex_lock(philosophers[i].talk_mutex);
		while (i < philo_amount)
		{
			pthread_detach(philosophers[i].thread);
			i++;
		}
	}
}

static int	dead(t_philo	*philosophers, int philo_amount, int i)
{
	if (time_stop(philosophers[i].dead_incoming)
		>= philosophers[i].ttd)
	{
		pthread_mutex_lock(philosophers[i].talk_mutex);
		usleep(200);
		printf("%ld ms Philo_%d is dead\n", time_stop(philosophers[i].start), i);
		detach(philosophers, philo_amount, 1);
		return (1);
	}
	return (0);
}

int	philo_check_1(t_philo	*philosophers, int philo_amount)
{
	int	i;

	usleep(3000);
	while (1)
	{
		i = 0;
		while (i < philo_amount)
		{
			if (dead(philosophers, philo_amount, i))
				return (0);
			i++;
		}
		usleep(500);
	}
}

int	philo_check_2(t_philo	*philosophers, int philo_amount, int meals_amount)
{
	int		i;
	char	all_full;

	usleep(3000);
	while (1)
	{
		i = 0;
		all_full = 1;
		while (i < philo_amount)
		{
			if (dead(philosophers, philo_amount, i))
				return (0);
			if (philosophers[i].meals_amount < meals_amount)
				all_full = 0;
			i++;
		}
		if (all_full)
		{
			detach(philosophers, philo_amount, 0);
			return (0);
		}
		usleep(500);
	}
}
