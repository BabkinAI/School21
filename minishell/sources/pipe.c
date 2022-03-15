/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:36 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 19:42:38 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirnpipe(t_commands *cmd, t_opt *opt, int flag, int i)
{
	stdin_dup(cmd, opt, flag, i);
	stdout_dup(cmd, opt->fd_out, opt, i);
}

void	last_pipe(int i, t_opt *opt, t_commands *cmd)
{
	if ((opt->count_pipes > 1 && cmd[i + 1].command == NULL) || cmd[i].fd_in > 0
		|| cmd[i].fd_out > 0)
	{
		opt->fd_in = opt->fd[i][0];
		opt->fd_out = opt->fd[0][1];
		opt->flag_first_pipe = 0;
		allclose(opt, opt->fd[i][0], opt->fd[0][1]);
		redirnpipe(cmd, opt, opt->flag_first_pipe, i);
	}
}

void	dopipes(int i, t_opt *opt, t_commands *cmd)
{
	if (opt->count_pipes > 1 && cmd[i + 1].command != NULL)
	{
		opt->fd_in = opt->fd[i][0];
		opt->fd_out = opt->fd[i + 1][1];
		allclose(opt, opt->fd[i][0], opt->fd[i + 1][1]);
		redirnpipe(cmd, opt, opt->flag_first_pipe, i);
	}
}

void	close_after_cmd(t_commands *cmd, int i)
{
	if (cmd[i].fd_in > 0)
		close(cmd[i].fd_in);
	if (cmd[i].fd_out > 0)
		close(cmd[i].fd_out);
}
