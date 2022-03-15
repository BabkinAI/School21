/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:23:42 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 19:31:31 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	back_redirect_2(char *str, t_count c, int j, t_commands	**parse)
{
	char	quote;

	while (redirect_check(str[c.i]))
	{
		if ((str[c.i] == 34) || (str[c.i] == 39))
		{
			quote = str[c.i];
			c.i++;
			while (str[c.i] != quote)
			{
				parse[0][j].filename_in[c.j] = str[c.i];
				c.j++;
				c.i++;
			}
			c.i++;
		}
		else
		{	
			parse[0][j].filename_in[c.j] = str[c.i];
			c.i++;
			c.j++;
		}
	}
	parse[0][j].filename_in[c.j] = 0;
	return (c.i);
}

int	back_redirect(char *str, int i, int j, t_commands	**parse)
{
	t_count	counts;

	i = i + 1;
	if (str[i] == ' ')
		i++;
	parse[0][j].filename_in = malloc(sizeof(char) * (ft_strlen2(str, i) + 1));
	if (!parse[0][j].filename_in)
		exit_clean(str, NULL);
	counts.j = 0;
	counts.i = i;
	i = back_redirect_2(str, counts, j, parse);
	parse[0][j].fd_in = rev_redirect(parse[0][j].filename_in);
	free(parse[0][j].filename_in);
	return (i - 1);
}
