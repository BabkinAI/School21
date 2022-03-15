/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:26 by kmars             #+#    #+#             */
/*   Updated: 2021/10/28 20:27:21 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*dot_slash(char *cmd)
{
	if (my_access(cmd) != -1)
		return (cmd);
	write(2, cmd, ft_strlen(cmd));
	ft_putendl_fd(": No such file or directory", 2);
	return (NULL);
}

static char	*getpath_help(char **dirs_path, char *cmd)
{
	char	*path;
	char	*join;
	int		i;

	i = 0;
	while (dirs_path[i])
	{
		join = ft_strjoin(dirs_path[i], "/");
		path = ft_strjoin(join, cmd);
		if (my_access(path) != -1)
		{
			free(join);
			return (path);
		}
		else
			free(path);
		i++;
		free(join);
	}
	return (NULL);
}

char	*getpath(char *cmd, char **env)
{
	char	*line;
	char	**dirs_path;
	char	*path;

	if (!access(cmd, 1))
		return (cmd);
	line = ft_getenv("PATH", env);
	if (line == NULL)
	{
		write(2, cmd, ft_strlen(cmd));
		ft_putendl_fd(": No such file or directory", 2);
		return (NULL);
	}
	dirs_path = ft_split(line, ':');
	if (cmd[0] == '.' && cmd[1] == '/')
		return (dot_slash(cmd));
	else
	{
		path = getpath_help(dirs_path, cmd);
		if (path)
			return (path);
	}
	write(2, cmd, ft_strlen(cmd));
	ft_putendl_fd(": command not found", 2);
	exit(127);
}
