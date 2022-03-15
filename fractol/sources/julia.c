#include "fractol.h"

int	julia_motion(int x, int y, t_fractol *f)
{
	if (f->julia_stop > 0)
	{
		f->k = init_complex(
				4 * ((double)x / f->width - 0.5),
				4 * ((double)(f->height - y) / f->height - 0.5));
		draw_fractal(f);
	}
	return (0);
}

void	julia(t_fractol *f)
{
	f->iteration = 0;
	while (ft_pow(f->z.re, 2.0) + ft_pow(f->z.im, 2.0) <= 4
		&& f->iteration < f->max_iteration)
	{
		f->z = init_complex(
				ft_pow(f->z.re, 2.0) - ft_pow(f->z.im, 2.0) + f->k.re,
				2.0 * f->z.re * f->z.im + f->k.im);
		f->iteration++;
	}
}
