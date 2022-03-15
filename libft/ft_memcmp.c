/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:09:51 by kmars             #+#    #+#             */
/*   Updated: 2021/04/25 15:29:36 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp (const void *arr1, const void *arr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)arr1)[i] != ((unsigned char *)arr2)[i])
			return (((unsigned char *)arr1)[i] - ((unsigned char *)arr2)[i]);
		i++;
	}
	return (0);
}
