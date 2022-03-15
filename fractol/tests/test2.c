#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode)
{
	
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		return(printf("UP\n"));
	if (keycode == 125)
		return(printf("DOWN\n"));
	if (keycode == 124)
		return(printf("RIGHT\n"));
	if (keycode == 123)
		return(printf("LEFT\n"));
	return(printf("%d\n", keycode));
}

int	mouse_hook(int button, int x, int y)
{
	if (button)
		printf("%d", button);
	if (x)
		return (printf("x:%d y:%d\n", x, y));
	return (button);
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
