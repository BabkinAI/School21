/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_invalid_comands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:25:06 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 14:25:07 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	invalid_minus(char ***env)
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
	}
	if (pwd)
		free(pwd);
	if (oldpwd)
		free(oldpwd);
}

void	invalid_dot(char ***env)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (!pwd)
		pwd = ft_getenv("PWD", env[0]);
	swapenv(env, pwd, pwd);
	if (pwd)
		free(pwd);
}

static void	path_help(char	**newpwd, char	**pwd, char	***env)
{
	newpwd[0] = getcwd(NULL, 1024);
	if (!newpwd[0])
		newpwd[0] = ft_getenv("PWD", env[0]);
	swapenv(env, pwd[0], newpwd[0]);
	free(pwd[0]);
	free(newpwd[0]);
}

void	invalid_path(char ***env, char *newpwd)
{
	char	*pwd;
	char	*relativepwd;

	relativepwd = NULL;
	pwd = getcwd(NULL, 1024);
	if (!pwd)
		pwd = ft_getenv("PWD", env[0]);
	if (chdir(newpwd) == -1)
	{
		relativepwd = ft_strjoin(ft_strjoin(pwd, "/"), newpwd);
		if (chdir(relativepwd) == -1)
		{
			free(relativepwd);
			free(pwd);
		}
	}
	if ((!relativepwd) || (chdir(relativepwd) != -1))
		path_help(&newpwd, &pwd, env);
}
