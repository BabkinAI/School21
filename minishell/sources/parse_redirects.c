/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:33 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 19:48:47 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_skip(char *str, int i)
{
	char	quote;

	i = i + 1;
	if (str[i] == ' ')
		i++;
	while (redirect_check(str[i]))
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
				i++;
		}
		else
			i++;
	}
	if (str[i] == ' ')
		i++;
	return (i);
}

int	redirectlen(char *str)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			len = len + quotes_skip(str, i);
			i = i + len + 2;
		}
		if ((str[i] == '<') || (str[i] == '>'))
		{
			if (((str[i] == '<') && (str[i] == '<'))
				|| ((str[i] == '>') && (str[i] == '>')))
				i = i + 2;
			else if ((str[i] == '<') || (str[i] == '>'))
				i = i + 1;
			i = redirect_skip(str, i);
		}
		i++;
		len++;
	}
	return (len);
}

static int	spreader(char *str, int i, int j, t_commands **parse)
{
	if ((str[i] == '<') && (str[i + 1] == '<'))
		i = double_back(str, i, j, parse);
	else if (str[i] == '<')
		i = back_redirect(str, i, j, parse);
	else if ((str[i] == '>') && (str[i + 1] == '>'))
		i = dd_redirect(str, i, j, parse);
	else if (str[i] == '>')
		i = redirect_default(str, i, j, parse);
	return (i);
}

static void	null_all(t_commands	**parse, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		parse[0][i].string = NULL;
		parse[0][i].command = NULL;
		parse[0][i].flygegeheim = NULL;
		parse[0][i].filename_out = NULL;
		parse[0][i].filename_in = NULL;
		parse[0][i].fd_in = -1;
		parse[0][i].fd_out = -1;
		i++;
	}
}

char	*parse_redirects(char *str, t_commands	**parse, int i)
{
	t_count	counts;

	counts.i = 0;
	counts.j = 0;
	null_all(parse, i);
	if (redirect_presence(str))
		return (str);
	while (str[counts.i])
	{
		if ((str[counts.i] == 34) || (str[counts.i] == 39))
			counts.i = (counts.i + quotes_skip(str, counts.i) + 2);
		if (str[counts.i] == '|')
			counts.j++;
		counts.i = spreader(str, counts.i, counts.j, parse);
		if (str[counts.i])
			counts.i++;
	}
	str = redirect_copy(str);
	return (str);
}
