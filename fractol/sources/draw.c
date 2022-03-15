#include "fractol.h"

void	draw_fractal(t_fractol *f)
{
	f->y = 0;
	f->factor = init_complex((f->max.re - f->min.re)
			/ (f->width - 1), (f->max.im - f->min.im) / (f->height - 1));
	while (f->y < f->height)
	{		
		f->c.im = f->max.im - f->y * f->factor.im;
		f->x = 0;
		while (f->x < f->width)
		{
			f->c.re = f->min.re + f->x * f->factor.re;
			f->z = init_complex(f->c.re, f->c.im);
			f->iteration = 0;
			f->formula(f);
			f->trgb.t = (double)f->iteration / (double)f->max_iteration;
			f->trgb.red = f->red(f->trgb.t, f->s_r);
			f->trgb.green = f->green(f->trgb.t, f->s_g);
			f->trgb.blue = f->blue(f->trgb.t, f->s_b);
			my_mlx_pixel_put(&f->img, f->x, f->y,
				(int)f->trgb.t << 24 | f->trgb.red << 16 | f->trgb.green << 8
				| f->trgb.blue);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
}

static void	more_choice(t_fractol *f)
{
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 250, 0xCCCCCC,
		"Press \"5\" to display the Celtic mandelbrot");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 300, 0xCCCCCC,
		"Press \"6\" to display the Celtic perpendicular");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 350, 0xCCCCCC,
		"Press \"7\" to display the Perpendicular buffalo");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 400, 0xCCCCCC,
		"Press \"8\" to display the Perpendicular burning ship");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 450, 0xCCCCCC,
		"Press \"9\" to display the Perpendicular_mandelbrot");
}

static void	more_help(t_fractol *f)
{
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 300, 0xCCCCCC,
		"If you choose Julia fractal use mouse to change it");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 350, 0xCCCCCC,
		"Click \"Space\" for to turn off mouse changes");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 400, 0xCCCCCC,
		"Use the mouse wheel to zoom in and zoom out");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 450, 0xCCCCCC,
		"Clic \"C\" to change fractal");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 500, 0xCCCCCC,
		"Clic \"I\" and press + or - to change value of iterations");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 550, 0xCCCCCC,
		"Clic \"F1\" to get information about fractal");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height - 300, 0xFF0000, "Press R to choose Red color");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height - 250, 0x00FF00, "Press G to choose Green color");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height - 200, 0x0000FF, "Press B to choose Blue color");
}

void	draw_help(t_fractol *f)
{
	ft_bzero(f->img.addr, f->width * f->height * (f->img.bits_per_pixel / 8));
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
	mlx_string_put(f->mlx, f->mlx_win, f->width / 2,
		f->height / 10, 0xCCCCCC, "Controls");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 50, 0xCCCCCC,
		"Double click on color to display fractal appropriate spectrum");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 100, 0xCCCCCC,
		"Click \"Tab\" and choose two color for shift or \"d\" for default");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 150, 0xCCCCCC,
		"Use \"WASD\" or \"Arrows\" for the movement of the fractal");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 200, 0xCCCCCC,
		"Choose a color and press + or - increase or decrease its saturation");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 5,
		f->height / 10 + 250, 0xCCCCCC,
		"Click \"Backspace\" to exit the help");
	more_help(f);
}

int	draw_choice(t_fractol *f)
{
	f->choice = 1;
	ft_bzero(f->img.addr, f->width * f->height * (f->img.bits_per_pixel / 8));
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height / 6, 0xCCCCCC, "Please choose a fractal");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 50, 0xCCCCCC,
		"Press \"1\" to display the Mendelbrot");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 100, 0xCCCCCC,
		"Press \"2\" to display the Julia");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 150, 0xCCCCCC,
		"Press \"3\" to display the Burning ship");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 200, 0xCCCCCC,
		"Press \"4\" to display the Celtic mandelbar");
	more_choice(f);
	if (!f->choice)
	{
		exit(0);
		return (1);
	}
	return (0);
}
