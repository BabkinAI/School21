/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dor2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:52 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:52 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_spin	spinner_3(t_stack stacks, char direction)
{
	t_spin	spin;

	spin.turns = 0;
	while (stacks.stack_b->index != stacks.max_index)
	{
		if (direction == 'r')
			stacks.stack_b = stacks.stack_b->next;
		else
			stacks.stack_b = stacks.stack_b->past;
		spin.turns++;
	}
	return (spin);
}

static t_spin	spinner_4(t_stack stacks, char direction)
{
	t_spin	spin;
	int		save_index;

	spin.turns = 0;
	spin.i = 1;
	save_index = stacks.stack_b->index;
	while (stacks.stack_b->index != stacks.stack_a->index - spin.i)
	{
		if (direction == 'r')
			stacks.stack_b = stacks.stack_b->next;
		else
			stacks.stack_b = stacks.stack_b->past;
		spin.turns++;
		if (stacks.stack_b->index == save_index)
		{
			spin.i++;
			spin.turns = 0;
		}
	}
	return (spin);
}

static t_spin	spinner_5(t_stack stacks, char direction, int block)
{
	t_spin	spin;

	spin.turns = 0;
	while ((stacks.stack_a->index < block - stacks.block_size)
		|| (stacks.stack_a->index > block))
	{
		if (direction == 'r')
			stacks.stack_a = stacks.stack_a->next;
		else
			stacks.stack_a = stacks.stack_a->past;
		spin.turns++;
	}
	return (spin);
}

t_spin	direction_of_rotation_2(t_stack stacks)
{
	t_spin	spin_1;
	t_spin	spin_2;

	if (stacks.stack_a->index < stacks.min_index)
	{
		spin_1 = spinner_3(stacks, 'r');
		spin_2 = spinner_3(stacks, 'l');
	}
	else
	{
		spin_1 = spinner_4(stacks, 'r');
		spin_2 = spinner_4(stacks, 'l');
	}
	spin_2.turns = spin_2.turns * -1;
	if (spin_1.turns < (spin_2.turns * -1))
		return (spin_1);
	else
		return (spin_2);
}

t_spin	direction_of_rotation_3(t_stack stacks, int block)
{
	t_spin	spin_1;
	t_spin	spin_2;

	spin_1 = spinner_5(stacks, 'r', block);
	spin_2 = spinner_5(stacks, 'l', block);
	spin_2.turns = spin_2.turns * -1;
	if (spin_1.turns < (spin_2.turns * -1))
		return (spin_1);
	else
		return (spin_2);
}
