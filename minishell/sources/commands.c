/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:12 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 19:42:26 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prepare_execve(t_commands *parse, char **env, int i)
{
	char	*path;
	char	*joinstr;
	char	*joinspace;
	char	**spliter;

	path = getpath(parse[i].command, env);
	joinspace = NULL;
	if (path == NULL)
		return ;
	if (parse[i].string)
	{
		joinspace = ft_strjoin(" ", parse[i].string);
		joinstr = ft_strjoin(parse[i].command, joinspace);
	}
	else
		joinstr = ft_strdup(parse[i].command);
	if (joinspace)
		free(joinspace);
	spliter = ft_split(joinstr, ' ');
	if (!spliter)
		return ;
	if ((joinstr) && (execve(path, spliter, env) == -1))
		free(joinstr);
	if ((joinstr) && (!check_echo(joinstr, 0)))
		free(joinstr);
}

void	commands(char ***env, int i, t_opt *opt, t_commands **parse)
{
	last_pipe(i, opt, parse[0]);
	dopipes(i, opt, parse[0]);
	if ((!ft_strncmp(parse[0][i].command, "echo", 5)))
		ft_echo(parse[0][i].string);
	else if ((!ft_strncmp(parse[0][i].command, "pwd", 4)))
		pwd();
	else if ((!ft_strncmp(parse[0][i].command, "cd", 3)))
		cd(parse[0][i].string, env);
	else if ((!ft_strncmp(parse[0][i].command, "env", 4)))
		do_env(env[0]);
	else if ((!ft_strncmp(parse[0][i].command, "export", 7)))
		env[0] = ft_export(parse[0][i].string, env[0]);
	else if ((!ft_strncmp(parse[0][i].command, "unset", 6)))
		env[0] = unset(env[0], parse[0][i].string);
	else if ((!ft_strncmp(parse[0][i].command, "exit", 5)))
		ft_exit(parse[0][i].string);
	else
		prepare_execve(parse[0], env[0], i);
	exit(0);
}

void	repeat_commands(char ***env, int i, t_commands **parse)
{
	if (!ft_strncmp(parse[0][i].command, "export", 6))
		env[0] = invalid_export(parse[0][i].string, env[0]);
	else if (!ft_strncmp(parse[0][i].command, "cd", 2))
		invalid_cd(parse[0][i].string, env);
	else if (!ft_strncmp(parse[0][i].command, "unset", 5))
		env[0] = unset(env[0], parse[0][i].string);
	else if (!ft_strncmp(parse[0][i].command, "exit", 4))
		dublicate_exit(parse[0][i].string);
}
