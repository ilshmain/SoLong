#include "../include/so_long.h"

void	move_robots_2(t_vars *vars, char s)
{
	if (s == 'G')
	{
		vars->sum_goals--;
		if (vars->sum_goals == 0)
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_eva_white, \
			&vars->img_width, &vars->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
			vars->eva_x * 64, vars->eva_y * 64);
		}
	}
}

void	PechatNaStdout(t_vars *vars, char s)
{
	if (s != '1')
	{
		vars->count++;
		printf("Step: %d\n", vars->count);
	}
}

void	move_robots_1(t_vars *vars, char s, int x, int y)
{
	if (s == '0' || s == 'G' || s == 'V')
	{
		if (vars->var_map[y][x] == 'V')
		{
			printf("<<<YOU LOSE>>>\n");
			exit(1);
		}
		PechatNaStdout(vars, s);
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_person, \
		&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img, x * 64, y * 64);
		vars->var_map[y][x] = 'P';
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_space, \
		&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
		vars->person_x * 64, vars->person_y * 64);
		move_robots_2(vars, s);
		vars->var_map[vars->person_y][vars->person_x] = '0';
		vars->person_x = x;
		vars->person_y = y;
	}
}

// Движение вправо
void	move_robots(t_vars *vars, char s, int x, int y)
{
	static char	*step;

	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_cub, \
	 &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
	1.2 * 64, vars->height * 65);
	move_robots_1(vars, s, x, y);
	step = ft_itoa(vars->count);
	mlx_string_put(vars->mlx, vars->win, 80, vars->height * 65, \
				0x00FFFFFF, step);
	free(step);
}
//

// Передвижение персонажа
void	move_person(t_vars *vars, int keycode)
{
	if (keycode == 123)
		move(vars, 123);
	else if (keycode == 124)
		move(vars, 124);
	else if (keycode == 125)
		move(vars, 125);
	else if (keycode == 126)
		move(vars, 126);
}	
//
