/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:01 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 14:24:19 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char *str, char ***env)
{
	if ((!str) || (((str[0] == '~') || (str[0] == 0)) && (!str[1])))
		root(env);
	else if ((str[0] == '-') && (!str[1]))
		minus(env);
	else if ((str[0] == '.') && (str[1] == '.') && (!str[2]))
		down(env);
	else if ((str[0] == '.') && (!str[2]))
		dot(env);
	else
		path(env, str);
}

void	invalid_cd(char *str, char ***env)
{
	if ((!str) || (((str[0] == '~') || (str[0] == 0)) && (!str[1])))
		root(env);
	else if ((str[0] == '-') && (!str[1]))
		invalid_minus(env);
	else if ((str[0] == '.') && (str[1] == '.') && (!str[2]))
		down(env);
	else if ((str[0] == '.') && (!str[2]))
		invalid_dot(env);
	else
		invalid_path(env, str);
}
