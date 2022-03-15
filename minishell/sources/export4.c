/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:33:58 by kmars             #+#    #+#             */
/*   Updated: 2021/10/30 18:33:59 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	envlens(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && (str[i] != '='))
		i++;
	if (str[i])
		i++;
	while (str[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	*plus_copy(char *str)
{
	char	*plusstr;
	int		i;
	int		j;

	plusstr = malloc(sizeof(char) * (envlens(str) + 1));
	if (!plusstr)
		exit(2);
	i = 0;
	j = 0;
	while (str[i] && (str[i] != '='))
		i++;
	if (str[i])
		i++;
	while (str[i])
	{
		plusstr[j] = str[i];
		j++;
		i++;
	}
	plusstr[j] = 0;
	return (plusstr);
}

void	concatenation_dublicate(char *str, char ***env, int	swap)
{
	t_count	counts;
	char	*newenv;	
	char	*plusstr;

	counts.i = 0;
	counts.j = 0;
	plusstr = plus_copy(str);
	newenv = ft_strjoin(str, plusstr);
	if (!newenv)
		exit(2);
	env[0][swap] = newenv;
	free(str);
	str = NULL;
	free(plusstr);
	plusstr = NULL;
}
