/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:49:12 by kmars             #+#    #+#             */
/*   Updated: 2021/08/13 13:49:42 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	digits(int n)
{
	int	x;

	x = 1;
	while (n > 9)
	{
		n = n / 10;
		x = x * 10;
	}
	return (x);
}

void	ft_putnbr(int n)
{
	int		x;
	char	c;

	if (n == 0)
		write(1, "0", 1);
	else
	{
		x = digits(n);
		while (x)
		{
			c = ((n / x) + 48);
			write(1, &c, 1);
			n = n % x;
			x = x / 10;
		}
	}
}
