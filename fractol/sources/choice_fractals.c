#include "fractol.h"

static void	moree_choice_hook(int keycode, t_fractol *f)
{
	if (keycode == 26)
	{
		f->formula = &perpendicular_buffalo;
		f->choice = 0;
		f->fractal = "perpendicular_buffalo";
		draw_fractal(f);
	}
	else if (keycode == 28)
	{
		f->formula = &perpendicular_burning_ship;
		f->choice = 0;
		f->fractal = "perpendicular_burning_ship";
		draw_fractal(f);
	}
	else if (keycode == 25)
	{
		f->formula = &perpendicular_mandelbrot;
		f->choice = 0;
		f->fractal = "perpendicular_mandelbrot";
		draw_fractal(f);
	}	
}

static void	more_choice_hook(int keycode, t_fractol *f)
{
	if (keycode == 21)
	{
		f->formula = &celtic_mandelbar;
		f->choice = 0;
		f->fractal = "celtic_mandelbar";
		draw_fractal(f);
	}
	else if (keycode == 23)
	{
		f->formula = &celtic_mandelbrot;
		f->choice = 0;
		f->fractal = "celtic_mandelbrot";
		draw_fractal(f);
	}
	else if (keycode == 22)
	{
		f->formula = &celtic_perpendicular;
		f->choice = 0;
		f->fractal = "celtic_perpendicular";
		draw_fractal(f);
	}
	else
		moree_choice_hook(keycode, f);
}

void	choice_hook(int keycode, t_fractol *f)
{
	if (keycode == 18)
	{
		f->formula = &mandelbrot;
		f->choice = 0;
		f->fractal = "mandelbrot";
		draw_fractal(f);
	}
	else if (keycode == 19)
	{
		f->formula = &julia;
		f->choice = 0;
		f->fractal = "julia";
		draw_fractal(f);
		mlx_hook(f->mlx_win, 6, 0L, julia_motion, f);
	}
	else if (keycode == 20)
	{
		f->formula = &burning_ship;
		f->choice = 0;
		f->fractal = "burning_ship";
		draw_fractal(f);
	}
	else
		more_choice_hook(keycode, f);
}
