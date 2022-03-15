/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:12 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:13 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_putnbr_fd(int n, int fd)
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

void	show_stack(t_list *select, int i)
{
	while (i)
	{
		ft_putnbr_fd(select->number, 1);
		write(1, " ", 1);
		ft_putnbr_fd(select->index, 1);
		write(1, "\n", 1);
		select = select->next;
		i--;
	}
}
