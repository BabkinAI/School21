/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:47 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:47 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_spin	spinner_1(t_stack stacks, char direction)
{
	t_spin	spin;
	int		save_index;

	spin.turns = 0;
	spin.i = 1;
	save_index = stacks.stack_a->index;
	while (stacks.stack_a->index != spin.i)
	{
		if (direction == 'r')
			stacks.stack_a = stacks.stack_a->next;
		else
			stacks.stack_a = stacks.stack_a->past;
		spin.turns++;
		if (stacks.stack_a->index == save_index)
		{
			spin.i++;
			spin.turns = 0;
		}
	}
	return (spin);
}

static t_spin	spinner_2(t_stack stacks, char direction)
{
	t_spin	spin;
	int		save_index;

	spin.turns = 0;
	spin.i = 1;
	save_index = stacks.stack_a->index;
	while (stacks.stack_a->index != (stacks.stack_b->index + spin.i))
	{
		if (direction == 'r')
			stacks.stack_a = stacks.stack_a->next;
		else
			stacks.stack_a = stacks.stack_a->past;
		spin.turns++;
		if (stacks.stack_a->index == save_index)
		{
			spin.i++;
			spin.turns = 0;
		}
	}
	return (spin);
}

t_spin	direction_of_rotation(t_stack stacks)
{
	t_spin	spin_1;
	t_spin	spin_2;

	if (stacks.stack_b->index == stacks.amount)
	{
		spin_1 = spinner_1(stacks, 'r');
		spin_2 = spinner_1(stacks, 'l');
	}
	else
	{
		spin_1 = spinner_2(stacks, 'r');
		spin_2 = spinner_2(stacks, 'l');
	}
	spin_2.turns = spin_2.turns * -1;
	if (spin_1.turns < (spin_2.turns * -1))
		return (spin_1);
	else
		return (spin_2);
}

int	direction_of_rotation_final(t_stack stacks)
{
	int		spin_sum_1;
	int		spin_sum_2;
	t_list	*stack_save;

	spin_sum_1 = 0;
	spin_sum_2 = 0;
	stack_save = stacks.stack_a;
	while (stacks.stack_a->index != 1)
	{
		stacks.stack_a = stacks.stack_a->next;
		spin_sum_1++;
	}
	stacks.stack_a = stack_save;
	while (stacks.stack_a->index != 1)
	{
		stacks.stack_a = stacks.stack_a->past;
		spin_sum_2--;
	}
	if (spin_sum_1 < (spin_sum_2 * -1))
		return (spin_sum_1);
	else
		return (spin_sum_2);
}
