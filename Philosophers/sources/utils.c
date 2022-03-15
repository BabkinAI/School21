/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 13:34:02 by kmars             #+#    #+#             */
/*   Updated: 2021/08/14 13:06:17 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	x;
	size_t	m;

	i = 0;
	x = 0;
	m = 1;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m = m * -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		x = ((str[i] - 48) + (x * 10));
		i++;
	}
	return (x * m);
}

static int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

size_t	chek_input(int argc, char **argv)
{
	int	i;
	int	j;

	if ((argc < 5 ) || (argc > 6))
		return (1);
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	if ((ft_atoi(argv[1]) < 1) || (ft_atoi(argv[2]) < 1)
		|| (ft_atoi(argv[3]) < 1) || (ft_atoi(argv[4]) < 1))
		return (1);
	if (argc == 6)
		if ((ft_atoi(argv[5]) < 1))
			return (1);
	return (0);
}

void	all_free(pthread_mutex_t *mutex,
	t_philo *philosophers, int	philo_amount)
{
	int	i;

	i = 0;
	while (i < philo_amount)
	{
		free(philosophers[i].talk_fork);
		free(philosophers[i].talk_eat);
		free(philosophers[i].talk_sleep);
		free(philosophers[i].talk_think);
		if (i % 2)
			pthread_mutex_destroy(philosophers[i].first_fork);
		else if (i == (philo_amount - 1))
			pthread_mutex_destroy(philosophers[i].second_fork);
		else
			pthread_mutex_destroy(philosophers[i].second_fork);
		i++;
	}
	i = 0;
	pthread_mutex_destroy(philosophers[i].talk_mutex);
	free(mutex);
	free(philosophers);
}
