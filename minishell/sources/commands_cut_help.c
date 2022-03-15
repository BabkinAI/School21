/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_cut_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:05 by kmars             #+#    #+#             */
/*   Updated: 2021/10/26 12:34:36 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	comamount(char *str)
{
	int	amount;
	int	i;

	amount = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == 34) || (str[i] == 39))
			i = (i + quotes_skip(str, i) + 1);
		if (str[i])
			if ((str[i] == '|') || (str[i + 1] == 0))
				amount++;
		if (str[i])
			i++;
	}
	return (amount);
}

int	ministrlen(char *str, int i)
{
	int	len;

	len = 0;
	if ((str[i] == 34) || (str[i] == 39))
	{
		len = quotes_skip(str, i);
		i = (i + quotes_skip(str, i) + 2);
	}
	while ((ft_isascii(str[i])) && (str[i] != '|') && (str[i] != 0)
		&& (str[i] != ' '))
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			len = quotes_skip(str, i);
			i = (i + quotes_skip(str, i) + 2);
		}
		else if (str[i])
		{		
			len++;
			i++;
		}
	}
	return (len);
}

int	ministrlen2(char *str, int i)
{
	int	len;

	len = 0;
	if ((str[i] == 34) || (str[i] == 39))
	{
		len = quotes_skip(str, i);
		i = (i + quotes_skip(str, i) + 2);
	}
	while ((ft_isascii(str[i])) && (str[i] != '|') && (str[i] != 0)
		&& (str[i] != ' '))
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			len = quotes_skip(str, i);
			i = (i + quotes_skip(str, i) + 2);
		}
		else if (str[i])
		{		
			len++;
			i++;
		}
	}
	return (i);
}

int	ministrlen_string(char *str, int i)
{
	int	len;

	len = 0;
	if ((str[i] == 34) || (str[i] == 39))
	{
		len = quotes_skip(str, i);
		i = (i + quotes_skip(str, i) + 2);
	}
	while ((str[i] != '|') && (str[i] != 0))
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			len = quotes_skip(str, i);
			i = (i + quotes_skip(str, i) + 2);
		}
		else if (str[i])
		{		
			len++;
			i++;
		}
	}
	return (len);
}

int	ministrlen_string2(char *str, int i)
{
	int	len;

	len = 0;
	if ((str[i] == 34) || (str[i] == 39))
	{
		len = quotes_skip(str, i);
		i = (i + quotes_skip(str, i) + 2);
	}
	while ((str[i] != '|') && (str[i] != 0))
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			len = quotes_skip(str, i);
			i = (i + quotes_skip(str, i) + 2);
		}
		else if (str[i])
		{		
			len++;
			i++;
		}
	}
	return (i);
}
