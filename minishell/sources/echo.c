/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:24:39 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 14:34:20 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_flag(char *str)
{
	int	i;

	i = 0;
	if (str)
		while ((str[i] == '-') && (str[i + 1] == 'n')
			&& ((str[i + 2] == ' ') || (str[i + 2] == 0)))
			i = i + 3;
	return (i);
}

int	check_echo(char *str, int i)
{
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	echo_help(char *str, char	**finalstr, int i, int flag_n)
{
	while (str[i])
	{
		finalstr[0][i - flag_n] = str[i];
		i++;
	}
}

void	ft_echo(char *str)
{
	int		i;
	int		flag_n;
	int		len;
	char	*finalstr;

	i = search_flag(str);
	if ((!str) || ((i == 0) && check_echo(str, i)))
	{
		write(1, "\n", 1);
		exit(0);
	}
	if ((i != 0) && check_echo(str, i))
		exit(0);
	flag_n = i;
	len = ft_strlen(str) - i;
	finalstr = malloc(sizeof(char) * len);
	if (!finalstr)
		exit_clean(str, NULL);
	echo_help(str, &finalstr, i, flag_n);
	write(1, finalstr, len);
	if (!flag_n)
		write(1, "\n", 1);
	free(finalstr);
}
