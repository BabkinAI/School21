/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:36:20 by kmars             #+#    #+#             */
/*   Updated: 2021/08/14 13:03:43 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_str(char *s1, char *s2, char swtch)
{
	if (swtch)
		free(s2);
	else
		free(s1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, char swtch)
{
	char	*copy;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy)
		return (NULL);
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
	free_str(s1, s2, swtch);
	return (copy);
}
