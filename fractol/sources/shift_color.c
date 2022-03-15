#include "fractol.h"

static void	color_shift(t_fractol *f, char swtch)
{
	if (swtch == 'p')
	{
		if ((f->s_rgb == 'r') && (f->s_r < 205))
			f->s_r = f->s_r + 51;
		else if ((f->s_rgb == 'g') && (f->s_g < 205))
			f->s_g = f->s_g + 51;
		else if ((f->s_rgb == 'b') && (f->s_b < 205))
			f->s_b = f->s_b + 51;
	}
	if (swtch == 'm')
	{
		if ((f->s_rgb == 'r') && (f->s_r > 50))
			f->s_r = f->s_r - 51;
		else if ((f->s_rgb == 'g') && (f->s_g > 50))
			f->s_g = f->s_g - 51;
		else if ((f->s_rgb == 'b') && (f->s_b > 50))
			f->s_b = f->s_b - 51;
	}
	draw_fractal(f);
	f->s_rgb = 0;
}

static void	color_filling(t_fractol *f, char color)
{
	if (color == 'r')
	{
		f->s_r = 255;
		f->s_g = 0;
		f->s_b = 0;
	}
	else if (color == 'g')
	{
		f->s_r = 0;
		f->s_g = 255;
		f->s_b = 0;
	}
	else if (color == 'b')
	{
		f->s_r = 0;
		f->s_g = 0;
		f->s_b = 255;
	}
	draw_fractal(f);
}

void	start_shift(int keycode, t_fractol *f)
{
	if (keycode == 15)
	{
		if (f->s_rgb == 'r')
			color_filling(f, 'r');
		else
			f->s_rgb = 'r';
	}
	else if (keycode == 5)
	{
		if (f->s_rgb == 'g')
			color_filling(f, 'g');
		else
			f->s_rgb = 'g';
	}
	else if (keycode == 11)
	{
		if (f->s_rgb == 'b')
			color_filling(f, 'b');
		else
			f->s_rgb = 'b';
	}
	else if ((f->s_rgb != 0) && ((keycode == 69) || (keycode == 24)))
		color_shift(f, 'p');
	else if ((f->s_rgb != 0) && ((keycode == 78) || (keycode == 27)))
		color_shift(f, 'm');
}

void	defaults_color(t_fractol *f)
{
	f->s_r = 255;
	f->s_g = 255;
	f->s_b = 255;
	f->red = &red;
	f->green = &green;
	f->blue = &blue;
	f->tab = 0;
	f->cache_color = 0;
	draw_fractal(f);
}
