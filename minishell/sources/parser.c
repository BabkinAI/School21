/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:58:34 by kmars             #+#    #+#             */
/*   Updated: 2021/10/29 21:22:01 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_commands	*parser(char **str, t_commands *parse, char *argv, t_count counts)
{
	str[0] = readline(argv);
	if (!str[0])
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	if (str[0][0] != '\0')
		add_history(str[0]);
	str[0] = trimming(str[0]);
	str[0] = space_delete(str[0]);
	str[0] = transformation(str[0], counts.j, counts.env);
	if (parse)
	{
		commands_clean(parse);
		free(parse);
		parse = NULL;
	}
	parse = malloc(sizeof(t_commands) * (comamount(str[0]) + 1));
	if (!parse)
		exit_clean(str[0], argv);
	parse = save_str(parse, comamount(str[0]));
	str[0] = parse_redirects(str[0], &parse, comamount(str[0]));
	parse = cut(str[0], parse);
	free(str[0]);
	return (parse);
}
