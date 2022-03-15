#include "ft_printf.h"

void	*ft_memset(void *src, int c, size_t x)
{
	size_t	y;

	y = 0;
	while (y < x)
	{
		((char *)src)[y] = c;
		y++;
	}
	return (src);
}
