/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:49:17 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 19:27:55 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr (const void *arr, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)arr)[i] == c)
			return (&((char *)arr)[i]);
		i++;
	}
	return (NULL);
}
