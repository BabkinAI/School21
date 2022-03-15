/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:27 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:29 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ra(t_stack stacks)
{
	stacks.stack_a = stacks.stack_a->next;
	stacks.str = ft_strjoin(stacks.str, "ra\n");
	return (stacks);
}

t_stack	rb(t_stack stacks)
{
	if (stacks.stack_b->index == 0)
		return (stacks);
	stacks.stack_b = stacks.stack_b->next;
	stacks.str = ft_strjoin(stacks.str, "rb\n");
	return (stacks);
}

t_stack	rr(t_stack stacks)
{
	stacks.stack_a = stacks.stack_a->next;
	stacks.stack_b = stacks.stack_b->next;
	stacks.str = ft_strjoin(stacks.str, "rr\n");
	return (stacks);
}

t_stack	rra(t_stack stacks)
{
	stacks.stack_a = stacks.stack_a->past;
	stacks.str = ft_strjoin(stacks.str, "rra\n");
	return (stacks);
}

t_stack	rrb(t_stack stacks)
{
	if (!stacks.stack_b->index)
		return (stacks);
	stacks.stack_b = stacks.stack_b->past;
	stacks.str = ft_strjoin(stacks.str, "rrb\n");
	return (stacks);
}
