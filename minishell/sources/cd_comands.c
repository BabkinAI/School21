/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:23:51 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 14:23:00 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	swapenv(char ***env, char *oldpwd, char *pwd)
{
	int		i;

	i = 0;
	while ((env[0][i]) && (!ft_strnstr(env[0][i], "PWD")))
		i++;
	env[0][i] = ft_strjoin("PWD=", pwd);
	i = 0;
	while ((env[0][i]) && (!ft_strnstr(env[0][i], "OLDPWD")))
		i++;
	env[0][i] = ft_strjoin("OLDPWD=", oldpwd);
}

void	root(char ***env)
{
	char	*newpwd;
	char	*pwd;

	newpwd = ft_getenv("HOME", env[0]);
	pwd = getcwd(NULL, 1024);
	if (!pwd)
		pwd = ft_getenv("PWD", env[0]);
	chdir(newpwd);
	swapenv(env, pwd, newpwd);
	if (pwd)
		free(pwd);
	if (newpwd)
		free(newpwd);
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

void	path(char ***env, char *newpwd)
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
			printf("No such file or directory\n");
		}
	}
	if ((!relativepwd) || (chdir(relativepwd) != -1))
		path_help(&newpwd, &pwd, env);
}
