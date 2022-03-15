/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_dups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:22 by kmars             #+#    #+#             */
/*   Updated: 2021/10/25 14:05:31 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stdin_dup(t_commands *cmd, t_opt *opt, int flag, int i)
{
	if (cmd[i].fd_in > 0)
	{
		close(opt->fd_in);
		dup2(cmd[i].fd_in, STDIN_FILENO);
		close(cmd[i].fd_in);
		opt->fd_in = -1;
	}
	else
	{
		if (flag != 2 && opt->count_pipes > 1)
			dup2(opt->fd_in, STDIN_FILENO);
		close(opt->fd_in);
		opt->fd_in = -1;
	}
}

void	stdout_dup(t_commands *cmd, int fd_out, t_opt *opt, int i)
{
	if (cmd[i].fd_out > 0)
	{
		close(fd_out);
		dup2(cmd[i].fd_out, STDOUT_FILENO);
		close(cmd[i].fd_out);
		fd_out = -1;
	}
	else
	{
		if (cmd[i + 1].command != NULL && opt->count_pipes > 1)
			dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		fd_out = -1;
	}
}
