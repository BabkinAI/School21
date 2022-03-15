/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dublicate_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:36:09 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 16:37:46 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	help_exit(char *str, int i)
{
	if (!ft_isdigit(str[i]))
	{
		write(1, "exit\n", 5);
		printf("exit: %s: numeric argument required\n", str);
		free(str);
		exit(255);
	}
	i++;
}

void	dublicate_exit(char *str)
{
	int	i;
	int	digit;

	i = 0;
	if (!str)
		exit(0);
	while (str[i])
	{
		help_exit(str, i);
		i++;
	}
	digit = ft_atoi(str);
	if (digit > 255)
	{
		while (digit > 255)
			digit = digit - 256;
	}
	write(1, "exit\n", 5);
	free(str);
	exit(digit);
}
