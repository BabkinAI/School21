/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:06:22 by fcarl             #+#    #+#             */
/*   Updated: 2021/10/28 20:10:22 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		exit(2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		exit(2);
	while (i < len && start <= ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
