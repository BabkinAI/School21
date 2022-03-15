/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:49:21 by kmars             #+#    #+#             */
/*   Updated: 2021/08/16 20:36:20 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*mutex_init(int forks_amount)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc(sizeof(pthread_mutex_t) * forks_amount);
	if (!mutex)
		return (NULL);
	i = 0;
	while (i < forks_amount)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

static void	philo_talk_init(t_philo	*philosophers, int i)
{
	philosophers[i].talk_eat = ft_strjoin(ft_strjoin(" ms Philo_",
				ft_itoa(i), 1), " is eating\n", 0);
	philosophers[i].eat_talk = ft_strlen(philosophers[i].talk_eat);
	philosophers[i].talk_fork = ft_strjoin(ft_strjoin(" ms Philo_",
				ft_itoa(i), 1), " has taken a fork\n", 0);
	philosophers[i].fork_talk = ft_strlen(philosophers[i].talk_fork);
	philosophers[i].talk_sleep = ft_strjoin(ft_strjoin(" ms Philo_",
				ft_itoa(i), 1), " is sleeping\n", 0);
	philosophers[i].sleep_talk = ft_strlen(philosophers[i].talk_sleep);
	philosophers[i].talk_think = ft_strjoin(ft_strjoin(" ms Philo_",
				ft_itoa(i), 1), " is thinking\n", 0);
	philosophers[i].think_talk = ft_strlen(philosophers[i].talk_think);
}

static void	philo_fork_init(t_philo	*philosophers, int i,
	int philo_amount, pthread_mutex_t *mutex)
{
	if (philo_amount == 1)
	{
		philosophers[i].first_fork = &mutex[0];
		philosophers[i].second_fork = &mutex[0];
	}
	else if (i == philo_amount - 1)
	{
		philosophers[i].first_fork = &mutex[i];
		philosophers[i].second_fork = &mutex[0];
	}
	else if (i % 2)
	{
		philosophers[i].first_fork = &mutex[i];
		philosophers[i].second_fork = &mutex[i + 1];
	}
	else
	{
		philosophers[i].first_fork = &mutex[i - 1];
		philosophers[i].second_fork = &mutex[i];
	}
}

t_philo	*philo_init(char **argv, pthread_mutex_t *mutex,
	pthread_mutex_t talk_mutex)
{
	t_philo			*philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philosophers[i].number = i;
		philosophers[i].ttd = ft_atoi(argv[2]);
		philosophers[i].tte = ft_atoi(argv[3]);
		philosophers[i].tts = ft_atoi(argv[4]);
		philosophers[i].meals_amount = 0;
		philosophers[i].talk_mutex = &talk_mutex;
		philo_fork_init(philosophers, i, ft_atoi(argv[1]), mutex);
		philo_talk_init(philosophers, i);
		pthread_create(&philosophers[i].thread, NULL,
			philo, &philosophers[i]);
		i++;
	}
	return (philosophers);
}

void	philo_join(int philo_amount, t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < philo_amount)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}
