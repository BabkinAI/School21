/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:49:35 by kmars             #+#    #+#             */
/*   Updated: 2021/08/14 20:17:38 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	time_start(void)
{
	t_time	time;

	gettimeofday(&time.tv, &time.tz);
	return (time);
}

long	time_stop(t_time time)
{
	struct timeval	tv;
	struct timezone	tz;
	long			sec;
	long			usec;

	gettimeofday(&tv, &tz);
	sec = tv.tv_sec - time.tv.tv_sec;
	usec = tv.tv_usec - time.tv.tv_usec;
	if (usec < 0)
	{
		sec--;
		usec += 1000000;
	}
	return ((sec * 1000) + (usec * 0.001));
}
