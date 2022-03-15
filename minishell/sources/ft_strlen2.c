/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:03 by kmars             #+#    #+#             */
/*   Updated: 2021/10/24 12:25:03 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen2(char *str, int i)
{
	int		len;
	char	quote;

	len = 0;
	while ((str[i] != ' ') && (str[i] != 0) && (str[i] != '|')
		&& (str[i] != '<') && (str[i] != '>'))
	{
		if ((str[i] == 34) || (str[i] == 39))
		{
			quote = str[i];
			i++;
			while (str[i] == quote)
			{
				i++;
				len++;
			}
			i++;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}
