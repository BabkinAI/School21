/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:29 by kmars             #+#    #+#             */
/*   Updated: 2021/10/25 15:31:15 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freeder(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	initpipes(t_opt *opt)
{
	int	len;

	if (opt->count_pipes > 0 || opt->flag_redir == 1)
	{
		opt->fd = malloc(sizeof(int *) * opt->count_pipes);
		if (!opt->fd)
			exit(2);
		len = 0;
		while (opt->count_pipes > len)
		{
			opt->fd[len] = malloc(sizeof(int) * opt->count_pipes);
			if (!opt->fd[len])
				exit(2);
			len++;
		}
		len = 0;
		while (len < opt->count_pipes)
		{
			pipe(opt->fd[len]);
			len++;
		}
	}
}

void	allclose(t_opt *opt, int fd_in, int fd_out)
{
	int	len;

	len = 0;
	while (len < opt->count_pipes)
	{
		if (opt->fd[len][0] == fd_in)
		{
			len++;
			continue ;
		}
		close(opt->fd[len][0]);
		len++;
	}
	len = 0;
	while (len < opt->count_pipes)
	{
		if (opt->fd[len][1] == fd_out)
		{
			len++;
			continue ;
		}
		close(opt->fd[len][1]);
		len++;
	}
}

void	allcloser(t_commands *cmd, t_opt *opt)
{
	int		len;

	len = 0;
	while (cmd[len].command)
	{
		if (cmd[len].fd_in > 0)
			close(cmd[len].fd_in);
		if (cmd[len].fd_out > 0)
			close(cmd[len].fd_out);
		len++;
	}
	len = 0;
	while (len < opt->count_pipes)
	{
		close(opt->fd[len][0]);
		len++;
	}
	len = 0;
	while (len < opt->count_pipes)
	{
		close(opt->fd[len][1]);
		len++;
	}
}

int	my_access(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY, S_IXUSR);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}
