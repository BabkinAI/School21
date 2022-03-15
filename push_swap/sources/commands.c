/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:42 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:43 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sa(t_stack stacks)
{
	int	copy;

	copy = stacks.stack_a->number;
	stacks.stack_a->number = stacks.stack_a->next->number;
	stacks.stack_a->next->number = copy;
	copy = stacks.stack_a->index;
	stacks.stack_a->index = stacks.stack_a->next->index;
	stacks.stack_a->next->index = copy;
	copy = stacks.stack_a->save_index;
	stacks.stack_a->save_index = stacks.stack_a->next->save_index;
	stacks.stack_a->next->save_index = copy;
	stacks.str = ft_strjoin(stacks.str, "sa\n");
	return (stacks);
}

t_stack	sb(t_stack stacks)
{
	int	copy;

	copy = stacks.stack_b->number;
	stacks.stack_b->number = stacks.stack_b->next->number;
	stacks.stack_b->next->number = copy;
	copy = stacks.stack_b->index;
	stacks.stack_b->index = stacks.stack_b->next->index;
	stacks.stack_b->next->index = copy;
	copy = stacks.stack_b->save_index;
	stacks.stack_b->save_index = stacks.stack_b->next->save_index;
	stacks.stack_b->next->save_index = copy;
	stacks.str = ft_strjoin(stacks.str, "sb\n");
	return (stacks);
}

t_stack	ss(t_stack stacks)
{
	int	copy;

	copy = stacks.stack_a->number;
	stacks.stack_a->number = stacks.stack_a->next->number;
	stacks.stack_a->next->number = copy;
	copy = stacks.stack_a->index;
	stacks.stack_a->index = stacks.stack_a->next->index;
	stacks.stack_a->next->index = copy;
	copy = stacks.stack_b->number;
	stacks.stack_b->number = stacks.stack_b->next->number;
	stacks.stack_b->next->number = copy;
	copy = stacks.stack_b->index;
	stacks.stack_b->index = stacks.stack_b->next->index;
	stacks.stack_b->next->index = copy;
	copy = stacks.stack_a->save_index;
	stacks.stack_a->save_index = stacks.stack_a->next->save_index;
	stacks.stack_a->next->save_index = copy;
	copy = stacks.stack_b->save_index;
	stacks.stack_b->save_index = stacks.stack_b->next->save_index;
	stacks.stack_b->next->save_index = copy;
	stacks.str = ft_strjoin(stacks.str, "ss\n");
	return (stacks);
}

t_stack	pa(t_list *stack_a, t_list *stack_b, t_stack stacks)
{
	stack_b->past->next = stack_b->next;
	stack_b->next->past = stack_b->past;
	stacks.stack_b = stack_b->next;
	stack_b->next = stack_a;
	stack_b->past = stack_a->past;
	stack_b->past->next = stack_b;
	stack_a->past = stack_b;
	stacks.stack_a = stack_b;
	stacks.str = ft_strjoin(stacks.str, "pa\n");
	return (stacks);
}

t_stack	pb(t_list *stack_a, t_list *stack_b, t_stack stacks)
{
	stacks = min_and_max_index(stacks, stacks.stack_a->index);
	stack_a->past->next = stack_a->next;
	stack_a->next->past = stack_a->past;
	stacks.stack_a = stack_a->next;
	stack_a->next = stack_b;
	stack_a->past = stack_b->past;
	stack_a->past->next = stack_a;
	stack_b->past = stack_a;
	stacks.stack_b = stack_a;
	stacks.str = ft_strjoin(stacks.str, "pb\n");
	return (stacks);
}
