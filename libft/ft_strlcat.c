/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:50:21 by kmars             #+#    #+#             */
/*   Updated: 2021/04/22 19:08:44 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	i;
	size_t	srcl;
	size_t	destl;

	srcl = ft_strlen(src);
	if (s == 0)
		return (srcl);
	destl = ft_strlen(dest);
	if (s < destl)
		return (srcl + s);
	i = 0;
	while ((src[i]) && (destl < s - 1))
	{
		dest[destl] = src[i];
		destl++;
		i++;
	}
	dest[destl] = '\0';
	return (destl - i + srcl);
}
