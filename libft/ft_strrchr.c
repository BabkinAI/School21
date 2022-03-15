/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:13:11 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 20:04:58 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr	(const char *str, int ch)
{
	size_t	i;
	char	*p;

	p = NULL;
	i = 0;
	while (((char *)str)[i])
	{
		if (((char *)str)[i] == ch)
			p = &((char *)str)[i];
		i++;
	}
	if (((char *)str)[i] == ch)
		p = &((char *)str)[i];
	return (p);
}
