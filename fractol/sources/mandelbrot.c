#include "fractol.h"

void	mandelbrot(t_fractol *f)
{
	while ((ft_pow(f->z.re, 2.0) + ft_pow(f->z.im, 2.0) <= 4)
		&& (f->iteration < f->max_iteration))
	{
		f->z = init_complex(ft_pow(f->z.re, 2.0)
				- ft_pow(f->z.im, 2.0) + f->c.re, 2.0
				* f->z.re * f->z.im + f->c.im);
		f->iteration++;
	}
}
