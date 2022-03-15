/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:21 by kmars             #+#    #+#             */
/*   Updated: 2021/10/25 14:08:53 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirect_2(char *str, t_count c, int j, t_commands	**parse)
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
				parse[0][j].filename_out[c.j] = str[c.i];
				c.j++;
				c.i++;
			}
			c.i++;
		}
		else
		{	
			parse[0][j].filename_out[c.j] = str[c.i];
			c.i++;
			c.j++;
		}
	}
	parse[0][j].filename_out[c.j] = 0;
	return (c.i);
}

int	redirect_default(char *str, int i, int j, t_commands	**parse)
{
	t_count	counts;

	i++;
	if (str[i] == ' ')
		i++;
	parse[0][j].filename_out = malloc(sizeof(char) * (ft_strlen2(str, i) + 1));
	if (!parse[0][j].filename_out)
		exit_clean(str, NULL);
	counts.j = 0;
	counts.i = i;
	i = redirect_2(str, counts, j, parse);
	parse[0][j].fd_out = redirect(parse[0][j].filename_out);
	free(parse[0][j].filename_out);
	return (i - 1);
}
