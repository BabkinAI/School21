/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:42 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 21:36:12 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quotes_skip(char *str, int i)
{
	int		len;
	char	quote;

	len = 0;
	quote = str[i];
	i++;
	while (str[i] != quote)
	{
		i++;
		len++;
	}
	return (len);
}

static int	quotes_amount(char *str)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (str[i])
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			i = (i + quotes_skip(str, i) + 1);
			amount = amount + 2;
		}
		i++;
	}
	return (amount);
}

static char	*quotes_trim_help(char *str, int i, int j, char	*newstr)
{
	char	quote;

	while (str[i])
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
			{
				newstr[j] = str[i];
				i++;
				j++;
			}
		}
		else
		{
			newstr[j] = str[i];
			j++;
		}
		if (str[i])
			i++;
	}
	return (newstr);
}

char	*quotes_trim(char *str)
{
	char	*newstr;
	int		len;

	len = ft_strlen(str) - quotes_amount(str) + 1;
	newstr = malloc(sizeof(char) * len);
	if (!newstr)
		exit(2);
	newstr[len - 1] = 0;
	newstr = quotes_trim_help(str, 0, 0, newstr);
	return (newstr);
}
