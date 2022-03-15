/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say_my_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:58 by kmars             #+#    #+#             */
/*   Updated: 2021/10/24 12:25:59 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*say_my_name(char *str)
{
	char	*name;
	int		i;

	name = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!name)
		exit(2);
	if (!name)
		exit(0);
	i = 2;
	while (str[i])
	{
		name[i - 2] = str[i];
		i++;
	}
	name[i - 2] = ':';
	name[i - 1] = ' ';
	name[i] = 0;
	return (name);
}
