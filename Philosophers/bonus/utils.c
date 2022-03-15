/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 13:34:02 by kmars             #+#    #+#             */
/*   Updated: 2021/08/17 14:00:17 by kmars            ###   ########.fr       */
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

static void	invalid_input(void)
{
	printf("Invalid input\n");
	exit(0);
}

void	chek_input(int argc, char **argv)
{
	int	i;
	int	j;

	if ((argc < 5 ) || (argc > 6))
		invalid_input();
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]))
				invalid_input();
			i++;
		}
		j++;
	}
	if ((ft_atoi(argv[1]) < 1) || (ft_atoi(argv[2]) < 1)
		|| (ft_atoi(argv[3]) < 1) || (ft_atoi(argv[4]) < 1))
		invalid_input();
	if (argc == 6)
		if ((ft_atoi(argv[5]) < 1))
			invalid_input();
}
