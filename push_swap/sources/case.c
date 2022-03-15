/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:17 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:18 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	case_1(t_stack stacks)
{
	stacks = sa(stacks);
	return (stacks);
}

t_stack	case_2(t_stack stacks)
{
	stacks = sa(stacks);
	stacks = rra(stacks);
	return (stacks);
}

t_stack	case_3(t_stack stacks)
{
	stacks = ra(stacks);
	return (stacks);
}

t_stack	case_4(t_stack stacks)
{
	stacks = sa(stacks);
	stacks = ra(stacks);
	return (stacks);
}

t_stack	case_5(t_stack stacks)
{
	stacks = rra(stacks);
	return (stacks);
}
