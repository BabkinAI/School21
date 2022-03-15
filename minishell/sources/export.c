/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:45 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 17:55:04 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_dublicates_2(char *str, char **env, t_count counts)
{
	if ((!env[counts.i][counts.j]) && (str[counts.j] == '='))
		return (counts.i);
	if ((env[counts.i][counts.j] == '=')
		&& ((str[counts.j] == '=') || (!str[counts.j])))
	{
		if (str[counts.j] == 0)
			return (-2);
		else
			return (counts.i);
	}
	if (str[counts.j] != env[counts.i][counts.j])
		return (-3);
	return (-4);
}

int	check_dublicates(char *str, char **env)
{
	t_count	counts;
	int		check;

	counts.i = 0;
	while (env[counts.i])
	{
		counts.j = 0;
		while (1)
		{
			check = check_dublicates_2(str, env, counts);
			if (check == -3)
				break ;
			if (check >= 0)
				return (check);
			counts.j++;
			if (((!env[counts.i][counts.j]) && (!str[counts.j])) || check == -2)
				return (-2);
		}
		counts.i++;
	}
	return (-1);
}

int	compare(char **env, char *str, int def, int amount)
{
	int	i;
	int	j;
	int	number;

	number = amount - 1;
	i = amount - 1;
	while (i >= 0)
	{
		if ((i == 0) && (def == 0))
			break ;
		if (i == def)
			i--;
		j = 0;
		while (env[i][j] == str[j])
			j++;
		if (env[i][j] > str[j])
			number--;
		i--;
	}
	return (number);
}

char	**ft_export(char *str, char **env)
{
	char	**newenv;
	int		i;
	int		plus;

	if ((!str) || (str[0] == 0))
	{
		sortenv(env, envlen(env));
		return (env);
	}
	plus = check_plus(&str);
	if ((!ft_isalpha(str[0]) || (swap_export(str, &env, plus) == 1)))
		return (env);
	newenv = malloc(sizeof(char *) * (envlen(env) + 2));
	if (!newenv)
		exit(2);
	newenv[0] = strcopy(str);
	i = 0;
	while (env[i])
	{
		newenv[i + 1] = strcopy(env[i]);
		i++;
	}
	newenv[i + 1] = NULL;
	return (newenv);
}
