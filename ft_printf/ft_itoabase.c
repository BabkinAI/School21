#include "ft_printf.h"

static size_t	digits(unsigned long long n, int f)
{
	size_t	x;

	if (n == 0)
		return (1);
	x = 0;
	while (n)
	{
		n = n / f;
		x++;
	}
	return (x);
}

char	*ft_itoabase(unsigned long long n, int f, int g)
{
	size_t					x;
	char					*str;
	unsigned long long		scale;

	scale = 7;
	if ((f == 16) || (f == 10))
		scale = 9;
	x = digits(n, f);
	str = malloc (x + 1);
	if (!str)
		return (NULL);
	str[x] = 0;
	if (n == 0)
		str[0] = '0';
	while (x)
	{
		if ((n % f) > scale)
			str[x - 1] = ((n % f) + g);
		else
			str[x - 1] = ((n % f) + 48);
		n = n / f;
		x--;
	}
	return (str);
}
