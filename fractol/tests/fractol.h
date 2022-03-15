#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex {
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractol {
	void		*mlx;
	void		*mlx_win;
	t_complex	min;
	t_complex	factor;
	t_complex	max;
	t_complex	c;
	t_complex	z;
	t_complex	k;
	int			iteration;
	int			max_iteration;
	int			height;
	int			width;
	double		x;
	double		y;
	t_data		img;
}				t_fractol;

typedef struct s_trgb {
	int			red;
	int			green;
	int			blue;
	double		t;
}				t_trgb;

t_complex	init_complex(double re, double im);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		mandelbrot(t_fractol *f);
int			julia_motion(int x, int y, t_fractol *f);
void		defaults_init(t_fractol *f);
void		draw_fractal(t_fractol *f);
int			key_hook(int keycode);
int			mouse_hook(int button, int x, int y, t_fractol *f);
double		ft_pow(double x, int y);
void		ft_putnbr_fd(int n, int fd);
void		julia(t_fractol *f);

#endif