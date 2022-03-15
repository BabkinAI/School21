/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:52 by kmars             #+#    #+#             */
/*   Updated: 2021/10/25 15:21:35 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_count	redirect_copy_quote(char *str, char **newstr, t_count counts)
{
	char	quote;

	quote = str[counts.i];
	newstr[0][counts.j] = str[counts.i];
	counts.i++;
	counts.j++;
	newstr[0][counts.j] = str[counts.i];
	while (str[counts.i] != quote)
	{
		newstr[0][counts.j] = str[counts.i];
		counts.i++;
		counts.j++;
	}
	newstr[0][counts.j] = str[counts.i];
	counts.j++;
	counts.i++;
	if (str[counts.i] == ' ')
		counts.i++;
	return (counts);
}

static t_count	copy_help(char *str, t_count counts)
{
	if (((str[counts.i] == '<') && (str[counts.i] == '<'))
		|| ((str[counts.i] == '>') && (str[counts.i] == '>')))
		counts.i = counts.i + 2;
	else if ((str[counts.i] == '<') || (str[counts.i] == '>'))
		counts.i = counts.i + 1;
	counts.i = redirect_skip(str, counts.i);
	return (counts);
}

char	*redirect_copy(char *str)
{
	t_count	counts;
	char	*newstr;

	newstr = malloc(sizeof(char) * (redirectlen(str) + 1));
	if (!newstr)
		exit_clean(str, NULL);
	counts.i = 0;
	counts.j = 0;
	while (str[counts.i])
	{
		if ((str[counts.i] == 34) || (str[counts.i] == 39))
			counts = redirect_copy_quote(str, &newstr, counts);
		else if ((str[counts.i] == '<') || (str[counts.i] == '>'))
			counts = copy_help(str, counts);
		else
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
