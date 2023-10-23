/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_up_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:22:17 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/19 13:06:36 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_check_all_walls(t_map *g_map, int y)
{
	int	prout;

	prout = g_map->height * g_map->widht;
	prout++;
	g_map->walls->mx = g_map->walls->cx / 64;
	g_map->walls->my = g_map->walls->cy / 64;
	if (g_map->walls->mx < g_map->widht && g_map->walls->my < g_map->height
		&& g_map->walls->mx > 0 && g_map->walls->my > 0
		&& g_map->int_map[g_map->walls->my][g_map->walls->mx] == 1)
	{
		y = g_map->height;
		return (y);
	}
	else
	{
		ft_printf("up down cmy : %d\n", (int)g_map->walls->cmy);
		ft_printf("up down cmx : %d\n", (int)g_map->walls->cmx);
		g_map->walls->cx += g_map->walls->cmx;
		g_map->walls->cy += g_map->walls->cmy;
		y++;
		return (y);
	}
}

static void	ft_walls_ope(t_map *g_map, double ratan, double ra)
{
	if (ra < PI)
	{
		g_map->walls->cy = (((int)g_map->player->y / 64) * 64) - 0.0001;
		g_map->walls->cx = (g_map->player->y - g_map->walls->cy)
			* ratan + g_map->player->x;
		g_map->walls->cmy = 1;
		g_map->walls->cmx = -g_map->walls->cmy * ratan;
	}
	if (ra > PI)
	{
		g_map->walls->cy = (((int)g_map->player->y / 64) * 64) + 64;
		g_map->walls->cx = (g_map->player->y - g_map->walls->cy)
			* ratan + g_map->player->x;
		g_map->walls->cmy = 64;
		g_map->walls->cmx = -g_map->walls->cmy * ratan;
	}
}

void	ft_check_walls_ud(t_map *g_map)
{
	double		ra;
	double		ratan;
	int			r;
	uint32_t	y;

	r = -1;
	ra = g_map->player->pa;
	ratan = -1 / tan(ra);
	while (++r < 1)
	{
		y = 0;
		if (ra < PI || ra > PI)
			ft_walls_ope(g_map, ratan, ra);
		else if (ra == 0 || ra == PI)
		{
			g_map->walls->cx = g_map->player->x;
			g_map->walls->cy = g_map->player->y;
			y = g_map->height;
		}
		while (y < g_map->height)
			y = ft_check_all_walls(g_map, y);
	}
}
