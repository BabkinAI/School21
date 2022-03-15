/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:34:36 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 19:33:32 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove (void *destination, const void *source, size_t n)
{
	size_t	x;

	x = 0;
	if ((destination == NULL) && (source == NULL))
		return (destination);
	if (destination < source)
	{
		while (x < n)
		{
			((char *)destination)[x] = ((char *)source)[x];
			x++;
		}
		return (destination);
	}
	while (n)
	{
		n--;
		((char *)destination)[n] = ((char *)source)[n];
	}
	return (destination);
}
