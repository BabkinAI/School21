/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_transformation_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:27 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 22:15:41 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skips(char *str, int i, char tenv)
{
	if ((str[i] == '$') && ((str[i + 1] == '$') || (str[i + 1] == '#')
			|| (str[i + 1] == '@') || (str[i + 1] == '?')))
		i = i + 2;
	else if ((str[i] == '$') && ((str[i] == '-') || (str[i] == '_')))
		i = i + 5;
	else if (str[i] == '$')
	{
		i++;
		while ((symbols(str[i]) == 0) && (str[i] != '$') && (str[i] != '#')
			&& (str[i] != '@') && (str[i] != '?') && (str[i] != '^')
			&& (str[i] != '*'))
			i++;
	}
	if ((tenv == 0) && (str[i] == ' '))
		i++;
	return (i);
}

char	*exceptions(char *str, int i, int ret)
{
	char	*tenv;

	tenv = NULL;
	if (str[i + 1] == '?')
		tenv = ft_itoa(WEXITSTATUS(ret));
	else if (str[i + 1] == '#')
	{
		tenv = malloc(sizeof(char) * 2);
		if (!tenv)
			exit_clean(str, NULL);
		tenv[0] = 48;
		tenv[1] = 0;
	}
	else if ((str[i + 1] == '-') || (str[i + 1] == '_'))
		tenv = ft_strdup("himBH");
	else if (str[i + 1] == '$')
		tenv = ft_itoa(getpid());
	if (!tenv)
		exit_clean(str, NULL);
	return (tenv);
}

static char	*finalstr_help(char *str, int dl, char *tenv)
{
	char	*fstr;

	fstr = malloc(sizeof(char) * ((ft_strlen(str) - dl) + ft_strlen(tenv) + 1));
	if (!fstr)
		exit_clean(str, tenv);
	return (fstr);
}

static char	*helpfinal(char *str, char *fstr, char *tenv, t_count counts)
{
	int	y;

	if (symbols(str[counts.i + 1]))
		counts.i = counts.i + 2;
	else
		counts.i = skips(str, counts.i, tenv[0]);
	y = 0;
	while (tenv[y])
	{
		fstr[counts.j] = tenv[y];
		counts.j++;
		y++;
	}
	while (str[counts.i])
	{
		fstr[counts.j] = str[counts.i];
		counts.i++;
		counts.j++;
	}
	fstr[counts.j] = 0;
	free(str);
	return (fstr);
}

char	*finalstr(char *str, int dl, char *tenv)
{
	char	*fstr;
	t_count	counts;

	fstr = finalstr_help(str, dl, tenv);
	counts.j = 0;
	counts.i = 0;
	while ((str[counts.i] != '$') && (str[counts.i]))
	{
		if (str[counts.i] == 39)
			counts = quotes_copy_inc(str, &fstr, counts);
		if (str[counts.i] == 34)
			counts.i++;
		if ((str[counts.i]) && (str[counts.i] != '$'))
		{
			fstr[counts.j] = str[counts.i];
			counts.i++;
			counts.j++;
		}
		else if (str[counts.i] == 0)
		{
			fstr[counts.j] = 0;
			return (fstr);
		}
	}
	return (helpfinal(str, fstr, tenv, counts));
}
