/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:21:33 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 16:38:50 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	int		i;

	if (s == NULL)
		return (NULL);
	if ((int)((ft_strlen(s) - start)) <= 0)
	{
		copy = ft_calloc(1, 1);
		return (copy);
	}
	if ((int)len < (int)((ft_strlen(s) - start)))
		copy = malloc(len + 1);
	else
		copy = malloc((int)((ft_strlen(s) - start)) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while ((s[start]) && (i < (int)len))
	{
		copy[i] = s[start];
		i++;
		start++;
	}
	copy[i] = 0;
	return (copy);
}
