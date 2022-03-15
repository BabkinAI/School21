#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>

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

typedef struct s_trgb {
	int			red;
	int			green;
	int			blue;
	double		t;
}				t_trgb;

typedef struct s_fractol {
	void			*mlx;
	void			*mlx_win;
	t_complex		min;
	t_complex		factor;
	t_complex		max;
	t_complex		c;
	t_complex		z;
	t_complex		k;
	int				iteration;
	int				max_iteration;
	int				height;
	int				width;
	double			x;
	double			y;
	t_data			img;
	char			h;
	void			(*formula)(struct s_fractol *f);
	int				(*red)(double t, unsigned char rgb);
	int				(*green)(double t, unsigned char rgb);
	int				(*blue)(double t, unsigned char rgb);
	char			s_rgb;
	unsigned char	s_r;
	unsigned char	s_g;
	unsigned char	s_b;
	char			tab;
	int				cache_color;
	int				choice;
	t_trgb			trgb;
	char			*fractal;
	char			julia_stop;	
	char			ch_i;
	char			inf;	
}				t_fractol;

t_complex	init_complex(double re, double im);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		mandelbrot(t_fractol *f);
int			julia_motion(int x, int y, t_fractol *f);
void		defaults_init(t_fractol *f);
void		draw_fractal(t_fractol *f);
int			key_hook(int keycode, t_fractol *f);
int			mouse_hook(int button, int x, int y, t_fractol *f);
double		ft_pow(double x, int y);
double		ft_abs(double x);
void		julia(t_fractol *f);
int			init_fractals(t_fractol *f, char *fractal);
int			close(void);
void		zoom(int button, int x, int y, t_fractol *f);
void		start_shift(int keycode, t_fractol *f);
int			ft_strncmp(const char *str1, const char *str2, int n);
void		move(int keycode, t_fractol *f);
int			red (double t, unsigned char r);
int			green (double t, unsigned char g);
int			blue (double t, unsigned char b);
void		swap_color(int keycode, t_fractol *f);
void		defaults_color(t_fractol *f);
void		draw_help(t_fractol *f);
void		ft_bzero(void *s, int n);
int			draw_choice(t_fractol *f);
void		burning_ship(t_fractol *f);
void		celtic_mandelbar(t_fractol *f);
void		celtic_mandelbrot(t_fractol *f);
void		celtic_perpendicular(t_fractol *f);
void		perpendicular_buffalo(t_fractol *f);
void		perpendicular_burning_ship(t_fractol *f);
void		perpendicular_mandelbrot(t_fractol *f);
void		choice_hook(int keycode, t_fractol *f);
char		*ft_itoa(int n);
char		*ft_strdup(const char *str);
void		draw_informations(t_fractol *f);
#endif