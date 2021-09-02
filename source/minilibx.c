#include "../include/so_long.h"

int	ft_close_window(void)
{
	exit(0);
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		move_person(vars, keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	work_minilib(t_map *lst)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, lst->width * 64, \
	 lst->height * 75, "so_long");
	image_position(lst, &vars);
	mlx_hook(vars.win, 2, 0, ft_close, &vars);
	mlx_hook(vars.win, 17, 1L << 2, ft_close_window, &vars);
	mlx_loop(vars.mlx);
}
