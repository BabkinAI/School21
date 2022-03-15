/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_comands2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:23:54 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 21:47:06 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	help_down(char **str, char ***env)
{
	int	i;

	str[0] = getcwd(NULL, 1024);
	if (!str[0])
		str[0] = ft_getenv("PWD", env[0]);
	i = ft_strlen(str[0]) - 1;
	while (str[0][i] != '/')
		i--;
	if (i == 0)
		i++;
	return (i);
}

void	down(char ***env)
{
	char	*newpwd;
	char	*pwd;
	int		i;
	char	*str;

	i = help_down(&str, env);
	newpwd = malloc(sizeof(char) * i);
	if (!newpwd)
		exit(2);
	newpwd[i] = 0;
	i--;
	while (i >= 0)
	{
		newpwd[i] = str[i];
		i--;
	}
	pwd = getcwd(NULL, 1024);
	if (!pwd)
		pwd = ft_getenv("PWD", env[0]);
	chdir(newpwd);
	swapenv(env, pwd, newpwd);
	free(str);
	free(pwd);
	free(newpwd);
}

void	dot(char ***env)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (!pwd)
		pwd = ft_getenv("PWD", env[0]);
	swapenv(env, pwd, pwd);
	if (access(pwd, F_OK) == -1)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: ", 2);
		ft_putstr_fd("cannot access parent directories: ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
	}
	if (pwd)
		free(pwd);
}

char	*ft_getenv(char *str, char **env)
{
	t_count	counts;
	char	*meaning;

	counts.i = 0;
	while (env[counts.i])
	{
		counts.j = 0;
		while (counts.j < ft_strlen(str))
		{
			if (env[counts.i][counts.j] != str[counts.j])
				break ;
			if (env[counts.i][counts.j + 1] == '=')
			{
				meaning = ft_substr(env[counts.i], counts.j + 2,
						ft_strlen(env[counts.i]) - counts.j - 2);
				return (meaning);
			}
			counts.j++;
		}
		counts.i++;
	}
	return (NULL);
}
