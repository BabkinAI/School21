/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:40:17 by kmars             #+#    #+#             */
/*   Updated: 2021/08/17 15:10:10 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

sem_t	*meals_init(int i)
{
	char	*str;
	sem_t	*meals;

	str = ft_strjoin("/", ft_itoa(i), 1);
	if (!str)
		exit(0);
	sem_unlink(str);
	meals = sem_open(str, O_CREAT, 0666, 0);
	free(str);
	return (meals);
}

t_philo	*philo_init(char **argv, t_imaphores simaphores, int argc)
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
		if (argc == 6)
			philosophers[i].amount_meals = ft_atoi(argv[5]);
		philosophers[i].meals_amount = 0;
		philosophers[i].etiquette = simaphores.etiquette;
		philosophers[i].sem = simaphores.sem;
		philosophers[i].amount = ft_atoi(argv[1]);
		philosophers[i].meals = meals_init(i);
		philosophers[i].talk = simaphores.talk;
		i++;
	}
	return (philosophers);
}

void	unlink_philo(void)
{
	sem_unlink("/talk");
	sem_unlink("/semaphor");
	sem_unlink("/etiquette");
}

void	waiter_join(pthread_t waiter, t_philo *philosophers, int argc)
{
	if (argc == 6)
	{
		pthread_create(&waiter, NULL, all_full, philosophers);
		pthread_detach(waiter);
		pthread_join(waiter, NULL);
	}
}
