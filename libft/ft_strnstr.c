/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:46:37 by kmars             #+#    #+#             */
/*   Updated: 2021/04/25 15:21:06 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr (const char *big, const char *little, size_t len)
{
	size_t	lenlittle;

	if (*little)
	{
		lenlittle = ft_strlen(little);
		while ((*big) && (len >= lenlittle))
		{
			if (*big == *little && ft_memcmp(big, little, lenlittle) == 0)
				return ((char *)big);
			len--;
			big++;
		}
		return (NULL);
	}
	return (&((char *)big)[0]);
}
