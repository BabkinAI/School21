#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void static	start(t_fractol *f, int argc, char *str)
{
	if ((argc != 2) || (init_fractals(f, str)))
	{
		f->choice = 1;
		draw_choice(f);
	}
	else
		f->fractal = str;
	if (!f->choice)
	{
		draw_fractal(f);
		if ((!ft_strncmp(f->fractal, "Julia", 5))
			|| (!ft_strncmp(f->fractal, "julia", 5)))
			mlx_hook(f->mlx_win, 6, 0L, julia_motion, f);
	}
	mlx_loop(f->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(sizeof(t_fractol));
	f->mlx = mlx_init();
	defaults_init(f);
	f->mlx_win = mlx_new_window(f->mlx, f->width,
			f->height, "Fractol");
	f->img.img = mlx_new_image(f->mlx, f->width,
			f->height);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
			&f->img.line_length, &f->img.endian);
	mlx_key_hook(f->mlx_win, key_hook, f);
	mlx_mouse_hook(f->mlx_win, mouse_hook, f);
	mlx_hook(f->mlx_win, 17, 0, close, f);
	start(f, argc, argv[1]);
	return (0);
}
