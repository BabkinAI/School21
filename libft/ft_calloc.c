/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:03:15 by kmars             #+#    #+#             */
/*   Updated: 2021/04/21 18:14:29 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	x;

	x = 0;
	p = malloc(size * count);
	if (p == NULL)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}
