/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:56 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:39:57 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	invalid_input(void)
{
	write(1, "Invalid_input\n", 14);
	exit(1);
}

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}