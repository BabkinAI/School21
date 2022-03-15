#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	x;

	x = 0;
	c = (char *)s;
	while (x < n)
	{
		c[x] = 0;
		x++;
	}
}
