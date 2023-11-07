/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_up_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:22:17 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/05 14:32:29 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_dda_comp(t_map *g_map, t_walls *walls, int *is_wall, int touched)
{
	if (g_map->map[walls->my][walls->mx] == '1')
	{
		*is_wall = 1;
		if (touched == 0)
			walls->line = (walls->sdy - walls->ddy);
		else
			walls->line = (walls->sdx - walls->ddx);
	}
}

static void	ft_dda(t_map *g_map, t_walls *walls)
{
	int	is_wall;
	int	touched;

	is_wall = 0;
	while (is_wall == 0)
	{
		if (walls->sdx < walls->sdy)
		{
			walls->sdx += walls->ddx;
			walls->mx += walls->stepx;
			touched = 1;
		}
		else
		{
			walls->sdy += walls->ddy;
			walls->my += walls->stepy;
			touched = 0;
		}
		ft_dda_comp(g_map, walls, &is_wall, touched);
	}
}

static void	ft_find_wall(t_map *g_map, t_walls *walls, double ddx, double ddy)
{
	if (walls->anglex < 0)
	{
		walls->stepx = -1;
		walls->sdx = (g_map->player->x - walls->mx) * ddx;
	}
	else
	{
		walls->stepx = 1;
		walls->sdx = (walls->mx + 1.0 - g_map->player->x) * ddx;
	}
	if (walls->angley < 0)
	{
		walls->stepy = -1;
		walls->sdy = (g_map->player->y - walls->my) * ddy;
	}
	else
	{
		walls->stepy = 1;
		walls->sdy = (walls->my + 1.0 - g_map->player->y) * ddy;
	}
	printf("dirx : %f\n", g_map->player->dirx);
	printf("diry : %f\n", g_map->player->diry);
}

int	ft_check_walls_ud(t_map *g_map, double ra)
{
	g_map->walls->anglex = cos(ra);
	g_map->walls->angley = sin(ra);
	g_map->walls->mx = (int)g_map->player->x;
	g_map->walls->my = (int)g_map->player->y;
	g_map->walls->ddx = sqrt(1 + (g_map->walls->angley
				* g_map->walls->angley)
			/ (g_map->walls->anglex * g_map->walls->anglex));
	g_map->walls->ddy = sqrt(1 + (g_map->walls->anglex
				* g_map->walls->anglex)
			/ (g_map->walls->angley * g_map->walls->angley));
	ft_find_wall(g_map, g_map->walls,
		g_map->walls->ddx, g_map->walls->ddy);
	ft_dda(g_map, g_map->walls);
	return (0);
}
