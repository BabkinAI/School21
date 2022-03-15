/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:00 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:01 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_index(t_list *stack, int	amount)
{
	int		fewest;
	int		i;
	int		j;

	j = amount;
	while (j)
	{
		fewest = stack->number;
		stack = stack->next;
		i = amount;
		while (stack->number != fewest)
		{
			if (stack->number > fewest)
				i--;
			stack = stack->next;
		}
		stack->index = i;
		stack = stack->next;
		j--;
	}
}

void	index_save(t_list *stack, int amount)
{
	while (amount)
	{
		stack->save_index = stack->index;
		stack = stack->next;
		amount--;
	}
}

void	index_return(t_list *stack, int	amount)
{
	while (amount)
	{
		stack->index = stack->save_index;
		stack = stack->next;
		amount--;
	}
}

t_stack	min_and_max_index(t_stack stacks, int selected_index)
{
	if (selected_index > stacks.max_index)
		stacks.max_index = selected_index;
	if (selected_index < stacks.min_index)
		stacks.min_index = selected_index;
	return (stacks);
}
