/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:08 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:09 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	push_swap_3(t_stack stacks)
{
	if ((stacks.stack_a->index == 2) && (stacks.stack_a->next->index == 1))
		stacks = case_1(stacks);
	else if ((stacks.stack_a->index == 3) && (stacks.stack_a->next->index == 2))
		stacks = case_2(stacks);
	else if ((stacks.stack_a->index == 3) && (stacks.stack_a->next->index == 1))
		stacks = case_3(stacks);
	else if ((stacks.stack_a->index == 1) && (stacks.stack_a->next->index == 3))
		stacks = case_4(stacks);
	else if ((stacks.stack_a->index == 2) && (stacks.stack_a->next->index == 3))
		stacks = case_5(stacks);
	return (stacks);
}

t_stack	push_swap_5(t_stack stacks)
{
	int	i;

	if (stacks.amount == 4)
		stacks = first_pb(stacks.stack_a, stacks);
	else if (stacks.amount == 5)
	{
		stacks = first_pb(stacks.stack_a, stacks);
		stacks = pb(stacks.stack_a, stacks.stack_b, stacks);
	}
	index_save(stacks.stack_a, 3);
	stack_index(stacks.stack_a, 3);
	stacks = push_swap_3(stacks);
	index_return(stacks.stack_a, 3);
	stacks = crutch(stacks);
	if (stacks.holy_crutch)
		return (final_touch(stacks));
	i = stacks.amount;
	while (i - 3)
	{
		stacks = case_return(stacks);
		i--;
	}
	return (final_touch(stacks));
}

static t_stack	push_swap_help(t_stack stacks, int block)
{
	int	i;

	stacks.block_size = block;
	i = block;
	while (i)
	{
		stacks = case_go_to_stack_b_2(stacks, block);
		i--;
	}
	return (stacks);
}

t_stack	push_swap_100(t_stack stacks)
{
	int	i;
	int	block;

	i = stacks.amount - stacks.amount % 20;
	stacks.max_index = 0;
	stacks.min_index = stacks.amount + 1;
	stacks = push_swap_help(stacks, stacks.amount - i);
	stacks.block_size = 20;
	block = stacks.block_size + stacks.amount % 20;
	while (i)
	{
		stacks = case_go_to_stack_b_2(stacks, block);
		i--;
		if (i % stacks.block_size == 0)
			block = block + stacks.block_size ;
	}
	i = stacks.amount;
	while (i)
	{
		stacks = pa(stacks.stack_a, stacks.stack_b, stacks);
		i--;
	}
	return (final_touch(stacks));
}

t_stack	push_swap_500(t_stack stacks)
{
	int	i;
	int	block;

	i = stacks.amount - stacks.amount % 42;
	stacks.max_index = 0;
	stacks.min_index = stacks.amount + 1;
	stacks = push_swap_help(stacks, stacks.amount - i);
	stacks.block_size = 42;
	block = stacks.block_size + stacks.amount % 42;
	while (i)
	{
		stacks = case_go_to_stack_b_2(stacks, block);
		i--;
		if (i % stacks.block_size == 0)
			block = block + stacks.block_size ;
	}
	i = stacks.amount;
	while (i)
	{
		stacks = pa(stacks.stack_a, stacks.stack_b, stacks);
		i--;
	}
	return (final_touch(stacks));
}
