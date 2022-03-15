/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:36:20 by kmars             #+#    #+#             */
/*   Updated: 2021/10/23 16:53:44 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*copy;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		exit(2);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy)
		exit(2);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = 0;
	return (copy);
}
