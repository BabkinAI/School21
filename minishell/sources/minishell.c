/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:19 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 21:10:50 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_commands	*mi_end(t_commands *parse, t_opt *opt, t_count *counts)
{
	int	i;

	i = 0;
	allcloser(parse, opt);
	counts[0].i = -1;
	while (++counts[0].i < opt[0].count_pipes)
		waitpid(-1, &(counts[0].j), 0);
	if (opt->count_pipes > 0)
	{
		while (i < opt->count_pipes)
		{
			if (opt->fd[i])
				free(opt->fd[i]);
			i++;
		}
		free(opt->fd);
	}
	opt->count_pipes = 0;
	return (parse);
}

static t_commands	*mi_help(char ***env, t_count *counts,
	t_opt *opt, t_commands *parse)
{
	pid_t	pid;

	while (parse[counts[0].i].command)
	{
		signal_cmd();
		pid = fork();
		if (pid == 0)
			commands(env, counts[0].i, opt, &parse);
		repeat_commands(env, counts[0].i, &parse);
		opt[0].flag_first_pipe = 1;
		close_after_cmd(parse, counts[0].i);
		counts[0].i++;
	}
	return (parse);
}

static void	minishell(char *argv, char ***env, char *str)
{
	t_count		counts;
	t_opt		opt;
	t_commands	*parse;

	parse = NULL;
	counts.env = env[0];
	counts.j = 0;
	while (1)
	{
		counts.i = 0;
		signals();
		parse = parser(&str, parse, argv, counts);
		opt.count_pipes = lencmd(parse);
		initpipes(&opt);
		opt.flag_first_pipe = 2;
		parse = mi_help(env, &counts, &opt, parse);
		parse = mi_end(parse, &opt, &counts);
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*str;

	(void)argc;
	str = NULL;
	argv[0] = say_my_name(argv[0]);
	minishell(argv[0], &env, str);
	free(argv[0]);
}
