/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_up_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:22:17 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/27 14:17:07 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_dda_comp(t_map *g_map, int *is_wall, int *touched)
{
	if (g_map->map[g_map->walls->my][g_map->walls->mx] == '1')
	{
		*is_wall = 1;
		if (g_map->walls->sdy < g_map->walls->sdx)
			*touched = 0;
		else
			*touched = 1;
	}
}

static void	ft_dda(t_map *g_map)
{
	int	is_wall;
	int	touched;

	is_wall = 0;
	touched = -1;
	while (is_wall == 0)
	{
		if (g_map->walls->sdx < g_map->walls->sdy)
		{
			g_map->walls->sdx += g_map->walls->ddx;
			g_map->walls->mx += g_map->walls->stepx;
		}
		else
		{
			g_map->walls->sdy += g_map->walls->ddy;
			g_map->walls->my += g_map->walls->stepy;
		}
		ft_dda_comp(g_map, &is_wall, &touched);
		if (touched == 1)
			g_map->player->line(g_map->walls->sdy - g_map->player->y);
		else if (touched == 0)
			g_map->player->line(g_map->walls->sdx - g_map->player->x);
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
		g_map->walls->sdx = (g_map->player->x + 1.0 - g_map->walls->mx) * ddx;
	}
	if (g_map->player->diry < 0)
	{
		g_map->walls->stepy = -1;
		g_map->walls->sdy = (g_map->player->y - g_map->walls->my) * ddy;
	}
	else
	{
		g_map->walls->stepy = 1;
		g_map->walls->sdy = (g_map->player->y + 1.0 - g_map->walls->my) * ddy;
	}
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
	return (0);
}
