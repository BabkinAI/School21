#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(int button, int x, int y, t_fractol *f)
{
	t_complex	all;
	double		interpolation;
	double		zoom;

	if ((button == 4) || (button == 5))
	{
		all = init_complex(
				(double)x / (f->width / (f->max.re - f->min.re)) + f->min.re,
				(double)y / (f->height / (f->max.im - f->min.im))
				* -1 + f->max.im);
		if (button == 5)
			zoom = 0.80;
		else
			zoom = 1.20;
		interpolation = 1.0 / zoom;
		f->min.re = interpolate(all.re, f->min.re, interpolation);
		f->min.im = interpolate(all.im, f->min.im, interpolation);
		f->max.re = interpolate(all.re, f->max.re, interpolation);
		f->max.im = interpolate(all.im, f->max.im, interpolation);
		draw_fractal(f);
	}
}

void	move(int keycode, t_fractol *f)
{
	t_complex	modul;

	modul = init_complex(ft_abs(f->max.re - f->min.re),
			ft_abs(f->max.im - f->min.im));
	if ((keycode == 126) || (keycode == 13))
	{
		f->min.im += modul.im * 0.05;
		f->max.im += modul.im * 0.05;
	}
	if ((keycode == 125) || (keycode == 1))
	{
		f->min.im -= modul.im * 0.05;
		f->max.im -= modul.im * 0.05;
	}
	if ((keycode == 124) || (keycode == 2))
	{
		f->min.re += modul.re * 0.05;
		f->max.re += modul.re * 0.05;
	}
	if ((keycode == 123) || (keycode == 0))
	{
		f->min.re -= modul.re * 0.05;
		f->max.re -= modul.re * 0.05;
	}
	draw_fractal(f);
}
