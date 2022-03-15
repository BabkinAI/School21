/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:04:25 by kmars             #+#    #+#             */
/*   Updated: 2021/10/26 11:04:25 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_commands	*save_str(t_commands *parse, int len)
{
	int	i;

	parse[0].i_exist = len;
	i = 0;
	while (i < len)
	{
		parse[i].str = 0;
		i++;
	}
	return (parse);
}
