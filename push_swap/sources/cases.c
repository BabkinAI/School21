/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:07 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:41:43 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	case_return(t_stack stacks)
{
	t_spin	spin;

	spin = direction_of_rotation(stacks);
	if (spin.turns > 0)
	{
		while (spin.turns > 0)
		{
			stacks = ra(stacks);
			spin.turns--;
		}
	}
	else if (spin.turns < 0)
	{
		while (spin.turns < 0)
		{
			stacks = rra(stacks);
			spin.turns++;
		}
	}
	stacks = pa(stacks.stack_a, stacks.stack_b, stacks);
	return (stacks);
}

t_stack	final_touch(t_stack stacks)
{
	int	turns;

	turns = direction_of_rotation_final(stacks);
	if (turns > 0)
	{
		while (turns)
		{
			stacks = ra(stacks);
			turns--;
		}
	}
	else if (turns < 0)
	{
		while (turns)
		{
			stacks = rra(stacks);
			turns++;
		}
	}
	return (stacks);
}

t_stack	case_go_to_stack_b(t_stack stacks)
{
	t_spin	spin;

	spin = direction_of_rotation_2(stacks);
	if (spin.turns > 0)
	{
		while (spin.turns > 0)
		{
			stacks = rb(stacks);
			spin.turns--;
		}
	}
	else if (spin.turns < 0)
	{
		while (spin.turns < 0)
		{
			stacks = rrb(stacks);
			spin.turns++;
		}
	}
	return (stacks);
}

t_stack	case_go_to_stack_b_2(t_stack stacks, int i)
{
	t_spin	spin;

	spin = direction_of_rotation_3(stacks, i);
	if (spin.turns > 0)
	{
		while (spin.turns > 0)
		{
			stacks = ra(stacks);
			spin.turns--;
		}
	}
	else if (spin.turns < 0)
	{
		while (spin.turns < 0)
		{
			stacks = rra(stacks);
			spin.turns++;
		}
	}
	stacks = case_go_to_stack_b(stacks);
	if (!stacks.stack_b->index)
		stacks = first_pb(stacks.stack_a, stacks);
	else
		stacks = pb(stacks.stack_a, stacks.stack_b, stacks);
	return (stacks);
}

t_stack	crutch(t_stack stacks)
{
	if ((stacks.stack_b->index == 4) && (stacks.stack_b->next->index == 5))
	{
		stacks = rb(stacks);
		stacks = pa(stacks.stack_a, stacks.stack_b, stacks);
		stacks = pa(stacks.stack_a, stacks.stack_b, stacks);
		stacks.holy_crutch = 1;
	}
	else
		stacks.holy_crutch = 0;
	return (stacks);
}
