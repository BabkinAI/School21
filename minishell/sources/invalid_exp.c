/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:13 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 17:55:08 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lencmd(t_commands *parse)
{
	int	i;

	i = 0;
	while (parse[i].command)
		i++;
	return (i);
}

char	**invalid_export(char *str, char **env)
{
	char	**newenv;
	int		i;
	int		plus;

	if ((!str) || (str[0] == 0))
		return (env);
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
