/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_comands3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:25:09 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 14:30:13 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minus_help(char	*oldpwd)
{
	ft_putstr_fd("cd ", 2);
	ft_putstr_fd(oldpwd, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	minus(char ***env)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = ft_getenv("OLDPWD", env[0]);
	pwd = getcwd(NULL, 1024);
	if (!pwd)
		pwd = ft_getenv("PWD", env[0]);
	if (oldpwd && pwd && access(pwd, F_OK) != -1 && access(oldpwd, F_OK) != -1)
	{
		chdir(oldpwd);
		swapenv(env, pwd, oldpwd);
		ft_putendl_fd(oldpwd, 2);
	}
	else if (oldpwd)
		minus_help(oldpwd);
	if (pwd)
		free(pwd);
	if (oldpwd)
		free(oldpwd);
}
