/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:47:56 by kmars             #+#    #+#             */
/*   Updated: 2021/08/13 13:48:40 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*copystr;

	i = 0;
	while (str[i])
		i++;
	copystr = malloc(i + 1);
	if (!copystr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copystr[i] = str[i];
		i++;
	}
	copystr[i] = 0;
	return (copystr);
}

static int	numberlen(int n)
{
	size_t	x;

	x = 0;
	while (n)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

static void	helpitoa(char *c, size_t x, int n)
{
	c[x] = 0;
	x--;
	while (n)
	{
		c[x] = ((n % 10) + 48);
		n = n / 10;
		x--;
	}
}

char	*ft_itoa(int n)
{
	int		m;
	size_t	x;
	char	*c;

	if (n == 0)
		return (ft_strdup("0"));
	m = n;
	x = 0;
	x = x + numberlen(m);
	c = malloc(x + 1);
	if (!c)
		return (NULL);
	helpitoa(c, x, n);
	return (c);
}
