/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:08 by kmars             #+#    #+#             */
/*   Updated: 2021/10/24 12:25:09 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strnstr(char *big, char *little)
{
	int	i;
	int	j;

	if (big[0] == little[0])
	{
		i = 0;
		j = 0;
		while (little[j])
		{
			if (!big[i])
				return (0);
			if (big[i] != little[j])
				return (0);
			i++;
			j++;
		}
	}
	else
		return (0);
	return (1);
}
