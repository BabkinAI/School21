#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	x;

	x = 0;
	p = malloc(size * count);
	if (p == NULL)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}

t_flags	cleaner(t_flags	f, char	*s,	char *str, char swtch)
{
	if (swtch == 1)
		if (!s)
			f.print = -1;
	if (swtch == 2)
	{
		if (!str)
		{
			f.print = -1;
			free(s);
		}
	}
	if (swtch == 3)
	{
		free(s);
		free(str);
	}
	return (f);
}
