/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:33 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:34 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	rrr(t_stack stacks)
{
	stacks.stack_a = stacks.stack_a->past;
	stacks.stack_b = stacks.stack_b->past;
	stacks.str = ft_strjoin(stacks.str, "rrr\n");
	return (stacks);
}

t_stack	first_pb(t_list *stack_a, t_stack stacks)
{
	stacks = min_and_max_index(stacks, stacks.stack_a->index);
	stack_a->past->next = stack_a->next;
	stack_a->next->past = stack_a->past;
	stacks.stack_a = stack_a->next;
	stacks.stack_b = stack_a;
	stack_a->next = stack_a;
	stack_a->past = stack_a;
	stacks.str = ft_strjoin(stacks.str, "pb\n");
	return (stacks);
}
