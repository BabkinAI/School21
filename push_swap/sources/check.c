/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:24 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:24 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_sorting(t_list *stack, int amount)
{
	while (amount - 1)
	{
		if (stack->index != (stack->next->index - 1))
		{
			return (0);
		}
		stack = stack->next;
		amount--;
	}
	return (1);
}

int	check_repeat(t_list *stack, int amount)
{
	int		i;
	t_list	*stack_save;

	while (amount - 1)
	{
		i = amount - 1;
		stack_save = stack;
		while (i)
		{
			stack = stack->next;
			if (stack->number == stack_save->number)
				return (1);
			i--;
		}
		stack = stack_save->next;
		amount--;
	}
	return (0);
}

void	check_input(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				invalid_input();
			j++;
		}
		i++;
	}
}
