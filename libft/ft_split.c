/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:38:02 by kmars             #+#    #+#             */
/*   Updated: 2021/04/25 13:41:20 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	centr(char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == 0)))
			j++;
		i++;
	}
	return (j);
}

static size_t	count(char const *s, char c, size_t i)
{
	size_t	x;

	x = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (x);
		x++;
		i++;
	}
	return (x);
}

static size_t	check(char **copy, size_t x)
{
	if (!copy[x])
	{
		x--;
		while (x >= 0)
		{
			free(copy[x]);
			x--;
		}
		free(copy);
		return (1);
	}
	return (0);
}

static char	**create(char const *s, char c, char **copy)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			copy[x] = ft_substr(s, i, count(s, c, i));
			if (check(copy, x))
				return (NULL);
			i = i + count(s, c, i);
			x++;
		}
	}
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**copy;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (s == NULL)
		return (NULL);
	copy = malloc(sizeof(char *) * (centr(s, c) + 1));
	if (!copy)
		return (NULL);
	copy[centr(s, c)] = NULL;
	copy = create(s, c, copy);
	if (!copy)
		return (NULL);
	return (copy);
}
