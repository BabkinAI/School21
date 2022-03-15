/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:33:54 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 18:33:55 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_plus_help(char *str)
{
	char	*newstr;
	int		i;
	int		j;
	int		swtch;

	swtch = 1;
	newstr = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((swtch) && (str[i] == '+'))
		{
			i++;
			swtch = 0;
		}
		newstr[j] = str[i];
		i++;
		j++;
	}
	newstr[j] = 0;
	return (newstr);
}

int	check_plus(char **str)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (str[0][i])
	{
		if (str[0][i] == '=')
		{
			if (str[0][i - 1] == '+')
			{
				found = 1;
				break ;
			}
			else
				break ;
		}
		i++;
	}
	if (found)
		str[0] = check_plus_help(str[0]);
	return (found);
}

static void	pritnt_sort(char **env, int j)
{
	int		i;
	char	swtch;

	swtch = 1;
	i = 0;
	write(1, "declare -x ", 11);
	while (env[j][i])
	{
		if ((env[j][i - 1] == '=') && swtch)
		{
			write(1, "\"", 1);
			swtch = 0;
		}
		write(1, &env[j][i], 1);
		if ((!swtch) && (env[j][i + 1] == 0))
			write(1, "\"", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	sortenv(char **env, int	amount)
{
	int	indeks[1000];
	int	i;
	int	j;

	i = 0;
	while (i < amount)
	{
		indeks[i] = compare(env, env[i], i, amount);
		i++;
	}
	i = 0;
	while (i < amount)
	{
		j = 0;
		while (indeks[j] != i)
			j++;
		pritnt_sort(env, j);
		i++;
	}
}
