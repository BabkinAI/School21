/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:18 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:19 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*stack_create(int amount)
{
	t_list	*tmp;
	t_list	*select;
	t_list	*new_stack;

	new_stack = (t_list *)malloc(sizeof(t_list));
	if (!new_stack)
		error_exit();
	select = new_stack;
	while (amount - 1)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			error_exit();
		select->next = tmp;
		tmp->past = select;
		select = tmp;
		amount--;
	}
	select->next = new_stack;
	new_stack->past = select;
	return (new_stack);
}

void	stack_init(int amount, int numbers[amount], t_list *stack)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		stack->number = numbers[i];
		stack = stack->next;
		i++;
	}
}

t_stack	create(int argc, char **argv)
{
	t_stack	stacks;
	int		i;

	stacks.stack_a = stack_create(argc - 1);
	if (!stacks.stack_a)
		error_exit();
	stacks.stack_b = (t_list *)malloc(sizeof(t_list));
	if (!stacks.stack_b)
	{
		error_exit();
	}
	stacks.stack_b->index = 0;
	stacks.amount = argc - 1;
	stacks.str = malloc(0);
	if (stacks.str == NULL)
		error_exit();
	i = 1;
	while (i < argc)
	{
		stacks.stack_a->number = ft_atoi(argv[i]);
		stacks.stack_a = stacks.stack_a->next;
		i++;
	}
	return (stacks);
}
