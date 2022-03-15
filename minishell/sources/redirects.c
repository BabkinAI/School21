/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:25:56 by kmars             #+#    #+#             */
/*   Updated: 2021/10/25 13:41:13 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	rev_redirect(char *line)
{
	int		fd;

	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		write(1, "No such file or directory\n",
			ft_strlen("No such file or directory\n"));
		return (fd);
	}
	return (fd);
}

int	double_rev_redirect(char *stop_str)
{
	char	*line;
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	line = NULL;
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			line = readline("> ");
			if (!ft_strncmp(line, stop_str, ft_strlen(line)))
				exit(0);
			line = ft_strjoin(line, "\n");
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
		waitpid(-1, 0, 0);
	if (line)
		free(line);
	close(fd[1]);
	return (fd[0]);
}

int	double_redirect(char *line)
{
	int		fd;

	fd = open(line, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd < 0)
	{
		write(1, "No such file or directory\n",
			ft_strlen("No such file or directory\n"));
		return (fd);
	}
	return (fd);
}

int	redirect(char *line)
{
	int		fd;

	fd = open(line, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd < 0)
	{
		write(1, "No such file or directory\n",
			ft_strlen("No such file or directory\n"));
		return (fd);
	}
	return (fd);
}
