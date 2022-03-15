/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:29:17 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 15:06:16 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy (char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	x;

	if (dest == NULL || src == NULL)
		return (0);
	x = 0;
	while (src[x])
		x++;
	i = 0;
	if (n == 0)
		return (x);
	while ((i < n - 1) && (src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (x);
}
