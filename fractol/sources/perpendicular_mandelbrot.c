#include "fractol.h"

void	perpendicular_mandelbrot(t_fractol *f)
{
	f->iteration = 0;
	f->z = init_complex(f->c.re, f->c.im);
	while (ft_pow(f->z.re, 2.0) + ft_pow(f->z.im, 2.0) <= 4
		&& f->iteration < f->max_iteration)
	{
		f->z = init_complex(
				ft_pow(f->z.re, 2.0) - ft_pow(f->z.im, 2.0) + f->c.re,
				-2.0 * ft_abs(f->z.re) * f->z.im + f->c.im);
		f->iteration++;
	}
}
