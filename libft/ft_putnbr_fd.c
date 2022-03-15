/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:38:43 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 18:52:42 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits (int n)
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

void	ft_putnbr_fd(int n, int fd)
{
	int		x;
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		x = digits(n);
		while (x)
		{
			c = ((n / x) + 48);
			write(fd, &c, 1);
			n = n % x;
			x = x / 10;
		}
	}
}
