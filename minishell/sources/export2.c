/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:13:50 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 18:28:45 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	envlen(char **env)
{
	int	len;

	len = 0;
	while (env[len])
		len++;
	return (len);
}

char	*strcopy(char *str)
{
	char	*newstr;
	int		i;

	newstr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!newstr)
		exit(2);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}

static t_count	swap_dublicate_2(char *str, t_count counts, char **newenv)
{
	newenv[0][counts.j] = str[counts.i];
	counts.j++;
	counts.i++;
	return (counts);
}

static void	swap_dublicate(char *str, char ***env, int	swap)
{
	t_count	counts;
	char	*newenv;	

	counts.i = 0;
	counts.j = 0;
	newenv = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!newenv)
		exit(2);
	while (str[counts.i])
		counts = swap_dublicate_2(str, counts, &newenv);
	newenv[counts.j] = 0;
	env[0][swap] = newenv;
}

int	swap_export(char *str, char ***env, int plus)
{	
	int			swap;

	if (!ft_isalpha(str[0]))
	{
		printf("%s: not a valid identifier\n", str);
		return (1);
	}
	swap = check_dublicates(str, env[0]);
	if (swap == -2)
		return (1);
	if (swap == -1)
		return (0);
	if (swap >= 0)
	{
		free(env[0][swap]);
		if (plus)
			concatenation_dublicate(str, env, swap);
		else
			swap_dublicate(str, env, swap);
		return (1);
	}
	return (0);
}
