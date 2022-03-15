/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:26:07 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 15:36:32 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static	char	*trimming_help(char *str)
{
	int		i;
	int		x;
	int		j;
	char	*newstr;

	x = 0;
	i = ft_strlen(str) - 1;
	while (ft_isspace(str[x]))
		x++;
	while (ft_isspace(str[i]))
		i--;
	j = (ft_strlen(str) - 1) - i;
	newstr = malloc(sizeof(char) * (ft_strlen(str) - x - j) + 1);
	if (!newstr)
		exit_clean(str, NULL);
	i = 0;
	while (x < (ft_strlen(str) - j))
	{
		newstr[i] = str[x];
		i++;
		x++;
	}
	newstr[i] = 0;
	free(str);
	return (newstr);
}

char	*trimming(char *str)
{
	char	*newstr;

	if (check_all_space(str))
	{
		newstr = malloc(sizeof(char));
		newstr[0] = 0;
		free(str);
		return (newstr);
	}
	return (trimming_help(str));
}

static int	space_count(char *str)
{
	int		i;
	int		count;
	char	quote;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			quote = str[i];
			i++;
			while ((str[i] != quote) && (str[i]))
				i++;
			i++;
		}
		if ((ft_isspace(str[i - 1])) && (ft_isspace(str[i])))
			count++;
		if (str[i])
			i++;
	}
	return (count);
}

char	*space_delete(char *str)
{
	char	*newstr;
	t_count	counts;

	newstr = malloc(sizeof(char) * (ft_strlen(str) - space_count(str) + 1));
	if (!newstr)
		exit_clean(str, NULL);
	counts.i = 0;
	counts.j = 0;
	while (str[counts.i])
	{
		if ((str[counts.i] == 34) || (str[counts.i] == 39))
			counts = quotes_and_apos_copy_inc(str, &newstr, counts);
		else if ((ft_isspace(str[counts.i - 1]))
			&& (ft_isspace(str[counts.i])))
			counts.i++;
		else if (str[counts.i])
		{
			newstr[counts.j] = str[counts.i];
			counts.i++;
			counts.j++;
		}
	}
	newstr[counts.j] = 0;
	free(str);
	return (newstr);
}
