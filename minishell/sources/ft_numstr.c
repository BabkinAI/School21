/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:34:39 by fcarl             #+#    #+#             */
/*   Updated: 2021/10/21 19:03:14 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	numstr(char *s, char c)
{
	unsigned int	i;
	int				pass;

	pass = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			pass++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (pass);
}
