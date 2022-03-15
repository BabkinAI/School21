/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:16:42 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 19:31:18 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if ((src == NULL) && (dest == NULL))
		return (dest);
	while (n > 0)
	{
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
	return (dest);
}
