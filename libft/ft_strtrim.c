/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:57:28 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 20:21:39 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	twin(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static size_t	size(char const *s1, char const *set)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = ft_strlen(s1);
	while ((x > 0) && (twin(s1[x - 1], set)))
		x--;
	while ((x > 0) && (twin(s1[i], set)))
	{
		i++;
		x--;
	}
	return (x);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	x;
	char	*prototype;

	if (s1 == NULL || set == NULL)
		return (NULL);
	x = 0;
	while (twin(s1[x], set))
		x++;
	prototype = ft_substr(s1, x, size(s1, set));
	return (prototype);
}
