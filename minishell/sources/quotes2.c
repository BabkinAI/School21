/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:46 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 22:06:33 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_count	quotes_copy_inc(char *str, char **newstr, t_count counts)
{
	newstr[0][counts.j] = str[counts.i];
	counts.i++;
	counts.j++;
	while (str[counts.i] != 39)
	{
		newstr[0][counts.j] = str[counts.i];
		counts.i++;
		counts.j++;
	}
	newstr[0][counts.j] = str[counts.i];
	counts.i++;
	counts.j++;
	return (counts);
}

t_count	quotes_and_apos_copy_inc(char *str, char **newstr, t_count counts)
{
	char	quote;

	quote = str[counts.i];
	newstr[0][counts.j] = str[counts.i];
	counts.i++;
	counts.j++;
	while (str[counts.i] != quote)
	{
		newstr[0][counts.j] = str[counts.i];
		counts.i++;
		counts.j++;
	}
	newstr[0][counts.j] = str[counts.i];
	counts.i++;
	counts.j++;
	return (counts);
}

t_count	quotes_and_apos_copy(char *str, char **newstr, t_count counts)
{
	char	quote;

	quote = str[counts.i];
	counts.i++;
	while (str[counts.i] != quote)
	{
		newstr[0][counts.j] = str[counts.i];
		counts.i++;
		counts.j++;
	}
	counts.i++;
	return (counts);
}
