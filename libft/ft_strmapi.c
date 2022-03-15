/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:40:47 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 15:28:46 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	size_t	x;

	if (s == NULL)
		return (NULL);
	copy = malloc((ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	x = 0;
	while (s[x])
	{
		copy[x] = f(x, s[x]);
		x++;
	}
	copy[x] = 0;
	return (copy);
}
