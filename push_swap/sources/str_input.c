/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:23 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:24 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	amount_of_elements(char *str)
{
	int	i;
	int	amount;

	if ((!ft_isdigit(*str)) && (*str != '-'))
		invalid_input();
	i = 0;
	amount = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			invalid_input();
		while ((str[i] != ' ') && (str[i] != 0))
		{
			if (!ft_isdigit(str[i]))
				invalid_input();
			i++;
		}
		if (str[i])
			i++;
		amount++;
	}
	return (amount);
}

static char	**argv_create(char *str, char **argv)
{
	int		i;
	int		j;
	int		strl;

	j = 1;
	strl = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] != ' ') && (str[i] != 0))
		{
			i++;
			strl++;
		}
		argv[j] = malloc(sizeof(char) * strl + 1);
		if (!argv[j])
			error_exit();
		if (str[i])
			i++;
		strl = 0;
		j++;
	}
	return (argv);
}

static char	**argv_initialization(char *str, char **argv)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 1;
	j = 0;
	while (str[i])
	{
		while ((str[i] != ' ') && (str[i] != 0))
		{
			argv[c][j] = str[i];
			i++;
			j++;
		}
		argv[c][j] = 0;
		if (str[i])
			i++;
		c++;
		j = 0;
	}
	return (argv);
}

char	**check_input_str(char *str)
{
	int		amount;
	char	**argv;

	amount = amount_of_elements(str);
	if (!amount)
		invalid_input();
	argv = malloc(sizeof(char **) * amount + 2);
	if (!argv)
		error_exit();
	argv = argv_create(str, argv);
	argv = argv_initialization(str, argv);
	return (argv);
}
