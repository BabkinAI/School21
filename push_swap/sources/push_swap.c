/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:04 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:05 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	push_swap(t_stack stacks)
{
	if (check_repeat(stacks.stack_a, stacks.amount))
	{
		stacks.str = "Некорректный стек";
		return (stacks);
	}
	stack_index(stacks.stack_a, stacks.amount);
	if (check_for_sorting(stacks.stack_a, stacks.amount))
		exit(0);
	else if (stacks.amount == 2)
		stacks = sa(stacks);
	else if (stacks.amount == 3)
		stacks = push_swap_3(stacks);
	else if (stacks.amount < 6)
		stacks = push_swap_5(stacks);
	else if (stacks.amount < 102)
	{
		stacks = push_swap_100(stacks);
	}
	else
		stacks = push_swap_500(stacks);
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc == 1)
	{
		ft_putstr_fd("Введите /push_swap 2 1 3 6 5 8\n", 1);
		ft_putstr_fd("Или любые другую последовательность чисел в ", 1);
		ft_putstr_fd("пределах int, без повторов.\n", 1);
		exit(1);
	}
	if (argc == 2)
	{
		argc = amount_of_elements (argv[1]) + 1;
		argv = check_input_str(argv[1]);
		if ((!argv) || (!argc))
			return (1);
	}
	check_input(argc, argv);
	stacks = create(argc, argv);
	stacks = push_swap(stacks);
	ft_putstr_fd(stacks.str, 1);
}
