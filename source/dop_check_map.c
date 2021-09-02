#include "../include/so_long.h"

void	init_parametrs(t_map *lst)
{
	lst->sum_enemy = 0;
	lst->sum_barrier = 0;
	lst->sum_exit = 0;
	lst->sum_goal = 0;
	lst->sum_player = 0;
}

void	check_map_parametrs(t_map *lst)
{
	init_parametrs(lst);
	checkFirstAndLastLine(lst, 0);
	checkFirstAndLastLine(lst, lst->height - 1);
	check_other_wall(lst);
	check_all_other(lst, 1, 1);
}
