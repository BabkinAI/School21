/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:47:56 by kmars             #+#    #+#             */
/*   Updated: 2021/10/25 11:58:16 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*exception(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
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

	m = n;
	x = 0;
	if ((n == -2147483648) || (n == 0))
		return (exception(n));
	if (n < 0)
	{
		m = m * -1;
		x++;
	}
	x = x + numberlen(m);
	c = malloc(x + 1);
	if (!c)
		return (NULL);
	if (n < 0)
	{
		c[0] = '-';
		n = n * -1;
	}
	helpitoa(c, x, n);
	return (c);
}
