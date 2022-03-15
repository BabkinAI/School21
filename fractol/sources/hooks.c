#include "fractol.h"

void	more_hooks(int keycode, t_fractol *f)
{
	if ((f->tab) && ((keycode == 15) || (keycode == 5)
			|| (keycode == 11) || (keycode == 2)))
	{
		if (keycode == 2)
			defaults_color(f);
		else if (f->cache_color)
			swap_color(keycode, f);
		else
			f->cache_color = keycode;
	}	
	else if ((keycode == 34) && (!f->tab))
	{
		f->ch_i = f->ch_i * -1;
		if (f->ch_i < 0)
			draw_fractal(f);
	}
	else if ((f->ch_i > 0) && ((keycode == 69) || (keycode == 24)))
		f->max_iteration++;
	else if ((f->ch_i > 0) && ((keycode == 78) || (keycode == 27)))
		if (f->max_iteration > 0)
			f->max_iteration--;
}

static void	defaults_hook(int keycode, t_fractol *f)
{
	if (((!f->tab) && (f->ch_i < 0)) && ((keycode == 126) || (keycode == 13)
			|| (keycode == 125) || (keycode == 1) || (keycode == 124)
			|| (keycode == 2) || (keycode == 123) || (keycode == 0)))
		move(keycode, f);
	else if (((!f->tab) && (f->ch_i < 0)) && ((keycode == 15) || (keycode == 5)
			|| (keycode == 11)))
		start_shift(keycode, f);
	else if (((!f->tab) && (f->ch_i < 0)) && (f->s_rgb != 0) && ((keycode == 69)
			|| (keycode == 24) || (keycode == 78) || (keycode == 27)))
		start_shift(keycode, f);
	else if (((!f->tab) && (f->ch_i < 0)) && (keycode == 49))
		f->julia_stop = f->julia_stop * -1;
	else if ((keycode == 48) && (f->ch_i < 0))
		f->tab = 1;
	else if (keycode == 122)
		draw_informations(f);
	else
		more_hooks(keycode, f);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 4)
		draw_help(f);
	else if (keycode == 51)
	{
		if (f->choice)
			draw_choice(f);
		else
			draw_fractal(f);
	}
	else if (keycode == 8)
	{
		defaults_init(f);
		draw_choice(f);
		f->choice = 1;
	}
	else if (f->choice)
		choice_hook(keycode, f);
	else
		defaults_hook(keycode, f);
	return (keycode);
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if ((!f->choice) && ((button == 4) || (button == 5)))
		zoom(button, x, y, f);
	return (button);
}
