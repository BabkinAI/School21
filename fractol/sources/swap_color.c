#include "fractol.h"

static void	swap_red(int keycode, t_fractol *f)
{
	if (keycode == 5)
	{
		f->red = &green;
		f->green = &red;
	}
	else if (keycode == 11)
	{
		f->red = &blue;
		f->blue = &red;
	}
}

static void	swap_green(int keycode, t_fractol *f)
{
	if (keycode == 15)
	{
		f->red = &green;
		f->green = &red;
	}
	else if (keycode == 11)
	{
		f->green = &blue;
		f->blue = &green;
	}	
}

static void	swap_blue(int keycode, t_fractol *f)
{
	if (keycode == 5)
	{
		f->blue = &green;
		f->green = &blue;
	}
	else if (keycode == 11)
	{
		f->red = &blue;
		f->blue = &red;
	}	
}

void	swap_color(int keycode, t_fractol *f)
{
	if (f->cache_color == 15)
		swap_red(keycode, f);
	else if (f->cache_color == 5)
		swap_green(keycode, f);
	else if (f->cache_color == 11)
		swap_blue(keycode, f);
	f->tab = 0;
	f->cache_color = 0;
	draw_fractal(f);
}
