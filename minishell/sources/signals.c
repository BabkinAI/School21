/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:26:01 by kmars             #+#    #+#             */
/*   Updated: 2021/10/24 12:26:02 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_quit(int sig)
{
	ft_putendl_fd("Quit: 3", 2);
	(void)sig;
	signal(SIGINT, SIG_IGN);
}

static void	signal_cmd_pipe(int sig)
{
	write(1, "\n", 1);
	(void)sig;
	signal(SIGINT, SIG_IGN);
}

static void	signal_ctrl_c(int signal)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)signal;
}

void	signal_cmd(void)
{
	signal(SIGINT, signal_cmd_pipe);
	signal(SIGQUIT, signal_quit);
}

void	signals(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_ctrl_c);
}
