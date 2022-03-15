/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:45:00 by kmars             #+#    #+#             */
/*   Updated: 2021/04/21 18:22:49 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy (void *destination, const void *source, int x, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
		if (((unsigned char *)source)[i] == (unsigned char)x)
			return ((void *)&destination[i + 1]);
		i++;
	}
	return (NULL);
}
