#include "fractol.h"

static void	more_draw_informations(t_fractol *f)
{
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height / 6 + 200, f->s_r << 16, "Red");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height / 6 + 250, f->s_g << 8, "Green");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height / 6 + 300, f->s_b, "Blue");
}

void	draw_informations(t_fractol *f)
{
	char	*max_iteration;

	max_iteration = ft_itoa(f->max_iteration);
	if (!max_iteration)
		exit(1);
	f->inf = 1;
	ft_bzero(f->img.addr, f->width * f->height * (f->img.bits_per_pixel / 8));
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
	mlx_string_put(f->mlx, f->mlx_win, f->width / 2.5,
		f->height / 8, 0xCCCCCC, "Informations");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 50, 0xCCCCCC, "Selected fractal");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 2,
		f->height / 6 + 50, 0xFF8000, f->fractal);
	mlx_string_put(f->mlx, f->mlx_win, f->width / 4,
		f->height / 6 + 100, 0xCCCCCC, "Max_iteration");
	mlx_string_put(f->mlx, f->mlx_win, f->width / 2,
		f->height / 6 + 100, 0xFF8000, max_iteration);
	mlx_string_put(f->mlx, f->mlx_win, f->width / 3,
		f->height / 6 + 150, 0xCCCCCC, "Brightness of colors");
	free(max_iteration);
	more_draw_informations(f);
}
