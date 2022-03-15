/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmars <kmars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:27 by kmars             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:30 by kmars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = 0;
	free((void *)s1);
	return (copy);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long int	x;
	int			m;

	i = 0;
	x = 0;
	m = 1;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m = m * -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		x = ((str[i] - 48) + (x * 10));
		i++;
	}
	if (((x * m) > 2147483647) || ((x * m) < -2147483648))
		invalid_input();
	return ((int)x * m);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	x;

	if (s != NULL)
	{
		x = 0;
		while (s[x])
		{
			write(fd, &s[x], 1);
			x++;
		}
	}
}
