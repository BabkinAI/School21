/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:30 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 21:52:18 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_exceptions(char c)
{
	if ((c == '$') || (c == '#') || (c == '?') || (c == '-') || (c == '_'))
		return (1);
	return (0);
}

static int	envlens(char *str, int i)
{
	int	x;
	int	oldlen;

	oldlen = ft_strlen(str);
	str = quotes_trim(str);
	if (ft_strlen(str) < oldlen)
		i--;
	x = 0;
	while ((str[i]) && (symbols(str[i]) == 0))
	{
		x++;
		i++;
	}
	return (x);
}

static char	*givenv(char *str, int i, int x)
{
	char	*env;
	int		j;
	int		oldlen;

	oldlen = ft_strlen(str);
	str = quotes_trim(str);
	if (ft_strlen(str) < oldlen)
		i--;
	env = malloc(sizeof(char) * (x + 1));
	if (!env)
		exit_clean(str, NULL);
	j = 0;
	while (j < x)
	{
		env[j] = str[i];
		i++;
		j++;
	}
	env[j] = 0;
	return (env);
}

static void	transformation_help(char **str, t_count counts,
	char **tenv, char **env)
{
	int	len;

	counts.i++;
	len = envlens(str[0], counts.i);
	env[0] = givenv(str[0], counts.i, len);
	tenv[0] = ft_getenv(env[0], counts.env);
	if (!tenv[0])
		tenv[0] = "";
	free(env[0]);
	str[0] = finalstr(str[0], len + 1, tenv[0]);
}

char	*transformation(char *str, int ret, char **true_env)
{
	char	*env;
	char	*tenv;
	t_count	counts;

	counts.i = 0;
	counts.env = true_env;
	while (str[counts.i])
	{
		counts.i = skip(str, counts.i);
		if ((str[counts.i] == '$') && (!symbols(str[counts.i + 1])))
		{
			if (check_exceptions(str[counts.i + 1]))
			{
				tenv = exceptions(str, counts.i, ret);
				str = finalstr(str, 2, tenv);
				free(tenv);
			}
			else
				transformation_help(&str, counts, &tenv, &env);
			counts.i = 0;
		}
		else
			counts.i++;
	}
	return (str);
}
