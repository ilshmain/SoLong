#include "../include/so_long.h"

void	move_1(t_vars *vars, int move, int x, int y)
{
	if (move == 125)
	{
		x = vars->person_x;
		y = vars->person_y + 1;
		move_robots(vars, vars->var_map[y][x], x, y);
	}
	else if (move == 126)
	{
		x = vars->person_x;
		y = vars->person_y - 1;
		move_robots(vars, vars->var_map[y][x], x, y);
	}
	if (vars->sum_goals == 0 && x == vars->eva_x && vars->eva_y == y)
	{
		printf("<<<YOU WIN>>>\n");
		exit(0);
	}
}

// Движение
void	move(t_vars *vars, int move)
{
	int	x;
	int	y;

	x = vars->person_x;
	y = vars->person_y;
	if (move == 123)
	{
		x = vars->person_x - 1;
		y = vars->person_y;
		move_robots(vars, vars->var_map[y][x], x, y);
	}
	else if (move == 124)
	{
		x = vars->person_x + 1;
		y = vars->person_y;
		move_robots(vars, vars->var_map[y][x], x, y);
	}
	move_1(vars, move, x, y);
}
//