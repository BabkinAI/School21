#include "fractol.h"

static int	moree_fractals(t_fractol *f, char *fractal)
{
	if ((!ft_strncmp(fractal, "perpendicular_buffalo", 21))
		|| (!ft_strncmp(fractal, "Perpendicular_buffalo", 21)))
	{
		f->formula = &celtic_mandelbrot;
		return (0);
	}
	else if ((!ft_strncmp(fractal, "perpendicular_burning_ship", 26))
		|| (!ft_strncmp(fractal, "Perpendicular_burning_ship", 26)))
	{
		f->formula = &perpendicular_burning_ship;
		return (0);
	}
	else if ((!ft_strncmp(fractal, "perpendicular_mandelbrot", 24))
		|| (!ft_strncmp(fractal, "Perpendicular_mandelbrot", 24)))
	{
		f->formula = &perpendicular_mandelbrot;
		return (0);
	}
	return (1);
}

static int	more_fractals(t_fractol *f, char *fractal)
{
	int	x;

	x = 1;
	if ((!ft_strncmp(fractal, "celtic_mandelbar", 16))
		|| (!ft_strncmp(fractal, "Celtic_mandelbar", 16)))
	{
		f->formula = &celtic_mandelbar;
		return (0);
	}
	else if ((!ft_strncmp(fractal, "celtic_mandelbrot", 17))
		|| (!ft_strncmp(fractal, "Celtic_mandelbrot", 17)))
	{
		f->formula = &celtic_mandelbrot;
		return (0);
	}
	else if ((!ft_strncmp(fractal, "celtic_perpendicular", 20))
		|| (!ft_strncmp(fractal, "Celtic_perpendicular", 20)))
	{
		f->formula = &celtic_perpendicular;
		return (0);
	}
	else
		x = moree_fractals(f, fractal);
	return (x);
}

int	init_fractals(t_fractol *f, char *fractal)
{
	int	x;

	x = 1;
	if ((!ft_strncmp(fractal, "Mandelbrot", 10))
		|| (!ft_strncmp(fractal, "mandelbrot", 10)))
	{
		f->formula = &mandelbrot;
		return (0);
	}
	else if ((!ft_strncmp(fractal, "Julia", 5))
		|| (!ft_strncmp(fractal, "julia", 5)))
	{
		f->formula = &julia;
		return (0);
	}
	else if ((!ft_strncmp(fractal, "burning_ship", 12))
		|| (!ft_strncmp(fractal, "Burning_ship", 12)))
	{
		f->formula = &burning_ship;
		return (0);
	}
	else
		x = more_fractals(f, fractal);
	return (x);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	defaults_init(t_fractol *f)
{
	f->ch_i = -1;
	f->julia_stop = -1;
	f->choice = 0;
	f->tab = 0;
	f->cache_color = 0;
	f->red = &red;
	f->green = &green;
	f->blue = &blue;
	f->s_rgb = 0;
	f->s_r = 255;
	f->s_g = 255;
	f->s_b = 255;
	f->h = -1;
	f->height = 1000;
	f->width = 1000;
	f->max_iteration = 50;
	f->min = init_complex(-2.0, -2.0);
	f->max.re = 2.0;
	f->max.im = f->min.im + (f->max.re - f->min.re)
		* f->height / f->width;
	f->k = init_complex(-0.4, 0.6);
}
