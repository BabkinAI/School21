/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:04:07 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 16:37:59 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	commands_clean(t_commands *parse)
{
	int	i;

	i = 0;
	while (parse[i].command)
	{
		free(parse[i].command);
		parse[i].command = NULL;
		i++;
	}
	i = 0;
	while (i < parse[0].i_exist)
	{
		if (parse[i].str)
		{
			free(parse[i].string);
			parse[i].string = NULL;
		}
		i++;
	}
}

void	exit_clean(char *str, char *str2)
{
	if (str)
		free(str);
	if (str2)
		free(str2);
	ft_exit("2");
}

static void	exit_help(int digit)
{
	if (digit > 255)
	{
		while (digit > 255)
			digit = digit - 256;
	}
	exit(digit);
}

void	ft_exit(char *str)
{
	int	i;
	int	digit;

	if (!str)
		exit(0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			free(str);
			exit(255);
		}
		i++;
	}
	digit = ft_atoi(str);
	if (digit == 2)
		exit(digit);
	free(str);
	exit_help(digit);
}
