/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:36:32 by fcarl             #+#    #+#             */
/*   Updated: 2021/10/25 11:58:47 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	int		len;

	len = ft_strlen((char *)s1);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
