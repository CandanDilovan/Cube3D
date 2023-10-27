/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_up_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:22:17 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/27 17:00:38 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_dda_comp(t_map *g_map, int *is_wall, int touched)
{
	if (g_map->map[g_map->walls->my][g_map->walls->mx] == '1')
	{
		*is_wall = 1;
		if (touched == 0)
			g_map->player->line = (g_map->walls->sdy - g_map->walls->ddy);
		else
			g_map->player->line = (g_map->walls->sdx - g_map->walls->ddx);
	}
}

static void	ft_dda(t_map *g_map)
{
	int	is_wall;
	int	touched;

	is_wall = 0;
	while (is_wall == 0)
	{
		if (g_map->walls->sdx < g_map->walls->sdy)
		{
			g_map->walls->sdx += g_map->walls->ddx;
			g_map->walls->mx += g_map->walls->stepx;
			touched = 1;
		}
		else
		{
			g_map->walls->sdy += g_map->walls->ddy;
			g_map->walls->my += g_map->walls->stepy;
			touched = 0;
		}
		ft_dda_comp(g_map, &is_wall, touched);
	}
}

static void	ft_find_wall(t_map *g_map, double ddx, double ddy)
{
	if (g_map->player->dirx < 0)
	{
		g_map->walls->stepx = -1;
		g_map->walls->sdx = (g_map->player->x - g_map->walls->mx) * ddx;
	}
	else
	{
		g_map->walls->stepx = 1;
		g_map->walls->sdx = (g_map->walls->mx + 1.0 - g_map->player->x) * ddx;
	}
	if (g_map->player->diry < 0)
	{
		g_map->walls->stepy = -1;
		g_map->walls->sdy = (g_map->player->y - g_map->walls->my) * ddy;
	}
	else
	{
		g_map->walls->stepy = 1;
		g_map->walls->sdy = (g_map->walls->my + 1.0 - g_map->player->y) * ddy;
	}
	printf("dirx : %f\n", g_map->player->dirx);
	printf("diry : %f\n", g_map->player->diry);
}

int	ft_check_walls_ud(t_map *g_map)
{
	int			r;

	r = -1;
	while (++r < 1)
	{
		g_map->walls->mx = (int)g_map->player->x;
		g_map->walls->my = (int)g_map->player->y;
		g_map->walls->ddx = sqrt(1 + (g_map->player->diry
					* g_map->player->diry)
				/ (g_map->player->dirx * g_map->player->dirx));
		g_map->walls->ddy = sqrt(1 + (g_map->player->dirx
					* g_map->player->dirx)
				/ (g_map->player->diry * g_map->player->diry));
		ft_find_wall(g_map, g_map->walls->ddx, g_map->walls->ddy);
		ft_dda(g_map);
	}
	printf("sdy : %f\n", g_map->walls->sdy - g_map->walls->ddy);
	printf("sdx : %f\n", g_map->walls->sdx - g_map->walls->ddx);
	printf("mapx : %d\n", g_map->walls->mx);
	printf("mapy : %d\n", g_map->walls->my);
	return (0);
}
