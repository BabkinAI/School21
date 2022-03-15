/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_cut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:09 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 19:58:05 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cutcommand(char *str, int i)
{
	char	*command;
	t_count	counts;

	counts.i = i;
	command = malloc(sizeof(char) * (ministrlen(str, counts.i) + 1));
	if (!command)
		exit_clean(str, NULL);
	counts.j = 0;
	while ((ft_isascii(str[counts.i]) || str[counts.i] == 34
			|| str[counts.i] == 39 ) && (str[counts.i] != '|')
		&& (str[counts.i] != 0) && (str[counts.i] != ' '))
	{
		if ((str[counts.i] == 34) || (str[counts.i] == 39))
			counts = quotes_and_apos_copy(str, &command, counts);
		else
		{
			command[counts.j] = str[counts.i];
			counts.j++;
			counts.i++;
		}
	}
	command[counts.j] = 0;
	return (command);
}

static char	*cutstring(char *str, int i)
{
	char	*string;
	t_count	counts;

	counts.i = i;
	string = malloc(sizeof(char) * (ministrlen_string(str, counts.i) + 1));
	if (!string)
		exit_clean(str, NULL);
	counts.j = 0;
	while ((str[counts.i] != '|') && (str[counts.i] != 0))
	{
		if ((str[counts.i] == 34) || (str[counts.i] == 39))
			counts = quotes_and_apos_copy(str, &string, counts);
		else
		{
			if ((str[counts.i] == ' ') && ((str[counts.i + 1] == '|')
					|| (str[counts.i + 1] == 0)))
				break ;
			string[counts.j] = str[counts.i];
			counts.j++;
			counts.i++;
		}
	}
	string[counts.j] = 0;
	return (string);
}

static t_commands	*cut_help(char *str, t_commands *commands, t_count counts)
{
	while (str[counts.i])
	{
		if (str[counts.i] == ' ')
			counts.i++;
		commands[counts.j].command = cutcommand(str, counts.i);
		counts.i = ministrlen2(str, counts.i);
		if (str[counts.i] == ' ')
			counts.i++;
		if ((str[counts.i] != '|') && (str[counts.i]))
		{
			commands[counts.j].string = cutstring(str, counts.i);
			if (commands[counts.j].string)
				commands[counts.j].str = 1;
			counts.i = ministrlen_string2(str, counts.i);
		}
		if (str[counts.i] == ' ')
			counts.i++;
		if ((str[counts.i] == '|') || (str[counts.i] == 0))
			counts.j++;
		if (str[counts.i])
			counts.i++;
	}
	commands[counts.j].command = 0;
	return (commands);
}

t_commands	*cut(char *str, t_commands	*parse)
{
	t_count		counts;

	counts.j = 0;
	counts.i = 0;
	parse = cut_help(str, parse, counts);
	return (parse);
}
