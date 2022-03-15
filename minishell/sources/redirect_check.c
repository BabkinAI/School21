/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:49 by kmars             #+#    #+#             */
/*   Updated: 2021/10/24 12:25:50 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_check(char c)
{
	if ((c == ' ') || (c == 0) || (c == '|') || (c == '<') || (c == '>'))
		return (0);
	return (1);
}

int	redirect_presence(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '>') || (str[i] == '<'))
			return (0);
		i++;
	}
	return (1);
}
