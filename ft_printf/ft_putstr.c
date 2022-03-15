#include "ft_printf.h"

t_flags	ft_putstr (char *str, t_flags f)
{
	if ((*str == ' ') && (f.faccuracy) && (f.width == 0))
		return (f);
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
		f.print++;
	}
	return (f);
}

t_flags	ft_putstrn (char *str, size_t n, t_flags f)
{
	while (n)
	{
		write(1, &(*str), 1);
		str++;
		f.print++;
		n--;
	}
	return (f);
}
