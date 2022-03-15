#include "fractol.h"

int	red (double t, unsigned char r)
{
	return ((int)(9 * (1 - t) * ft_pow(t, 3) * r));
}

int	green (double t, unsigned char g)
{
	return ((int)(15 * ft_pow((1 - t), 2) * ft_pow(t, 2) * g));
}

int	blue (double t, unsigned char b)
{
	return ((int)(8.5 * ft_pow((1 - t), 3) * t * b));
}
