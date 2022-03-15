/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:16:37 by kmars             #+#    #+#             */
/*   Updated: 2021/04/23 19:46:15 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr (const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (((char *)str)[i])
	{
		if (((char *)str)[i] == ch)
			return (&((char *)str)[i]);
		i++;
	}
	if (((char *)str)[i] == ch)
		return (&((char *)str)[i]);
	return (NULL);
}
