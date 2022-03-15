#include "fractol.h"

double	ft_pow(double x, int y)
{
	double	new_x;

	new_x = 1;
	while (y)
	{
		new_x = new_x * x;
		y--;
	}
	return (new_x);
}

double	ft_abs(double x)
{
	if (x < 0)
		x = x * -1;
	return (x);
}
