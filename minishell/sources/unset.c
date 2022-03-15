/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:26:11 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 16:34:50 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	comparison(char	*str, char *mystr)
{
	int	i;

	i = 0;
	while ((str[i] != '=') && (str[i]) && (mystr[i]))
	{
		if (str[i] != mystr[i])
			return (0);
		i++;
	}
	return (1);
}

static int	check(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (comparison(env[i], str))
			return (0);
		i++;
	}
	return (1);
}

static char	**unset_help(char **env, char *str, int i, int j)
{
	int		swtch;
	char	**newenv;

	swtch = 1;
	newenv = malloc(sizeof(char *) * (envlen(env)));
	if (!newenv)
		exit(2);
	while (env[i])
	{
		if ((swtch) && (comparison(env[i], str)))
		{
			swtch = 0;
			i++;
		}
		newenv[j] = strcopy(env[i]);
		i++;
		j++;
	}
	newenv[j] = NULL;
	return (newenv);
}

char	**unset(char **env, char *str)
{
	if (!str)
		return (env);
	if (check(env, str))
		return (env);
	return (unset_help(env, str, 0, 0));
}
