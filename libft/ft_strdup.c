/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:02:01 by kmars             #+#    #+#             */
/*   Updated: 2021/04/21 18:46:48 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*copystr;

	i = 0;
	while (str[i])
		i++;
	copystr = malloc(i + 1);
	if (!copystr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copystr[i] = str[i];
		i++;
	}
	copystr[i] = 0;
	return (copystr);
}
