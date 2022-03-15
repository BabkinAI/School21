/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:36 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:36 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		if (((unsigned char *)str1)[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

static t_stack	repeater(t_stack stacks, char *str)
{
	if (!ft_strncmp("sa", str, 2))
		stacks = sa(stacks);
	else if (!ft_strncmp("sb", str, 2))
		stacks = sb(stacks);
	else if (!ft_strncmp("ss", str, 2))
		stacks = ss(stacks);
	else if (!ft_strncmp("pa", str, 2))
		stacks = pa(stacks.stack_a, stacks.stack_b, stacks);
	else if ((!ft_strncmp("pb", str, 2)) && (stacks.stack_b->next == NULL))
		stacks = first_pb(stacks.stack_a, stacks);
	else if (!ft_strncmp("pb", str, 2))
		stacks = pb(stacks.stack_a, stacks.stack_b, stacks);
	else if (!ft_strncmp("ra", str, 2))
		stacks = ra(stacks);
	else if (!ft_strncmp("rb", str, 2))
		stacks = rb(stacks);
	else if (!ft_strncmp("rra", str, 3))
		stacks = rra(stacks);
	else if (!ft_strncmp("rrb", str, 3))
		stacks = rrb(stacks);
	else if (!ft_strncmp("rrr", str, 3))
		stacks = rrr(stacks);
	else if (!ft_strncmp("rr", str, 2))
		stacks = rr(stacks);
	return (stacks);
}

static t_stack	comander(t_stack stacks)
{
	char	**str;
	int		i;
	int		j;

	str = malloc(sizeof(char **) * 100000);
	i = 0;
	j = 0;
	str[j] = malloc(4);
	while (read(0, &str[j][i], 1))
	{
		i++;
		if ((str[j][i - 1] == '\n') || (str[j][i - 1] == 0))
		{
			str[j][i] = 0;
			stacks = repeater(stacks, str[j]);
			i = 0;
			free(str[j]);
			j++;
			str[j] = malloc(4);
		}
	}
	free(str[j]);
	free(str);
	return (stacks);
}

static void	answer(t_stack stacks, int amount)
{
	if (check_for_sorting(stacks.stack_a, amount))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		argc = amount_of_elements (argv[1]) + 1;
		argv = check_input_str(argv[1]);
		if ((!argv) || (!argc))
			return (1);
	}
	check_input(argc, argv);
	stacks = create(argc, argv);
	stack_index(stacks.stack_a, argc - 1);
	stacks = comander(stacks);
	answer(stacks, argc - 1);
}
