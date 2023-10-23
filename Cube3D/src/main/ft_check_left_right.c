/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_left_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:18:21 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/19 13:13:23 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_check_all_walls(t_map *g_map, int y)
{
	int	prout;

	prout = g_map->height * g_map->widht;
	prout++;
	g_map->walls->mx = (int)g_map->walls->cx / 64;
	g_map->walls->my = (int)g_map->walls->cy / 64;
	if (g_map->walls->mx < g_map->widht && g_map->walls->my < g_map->height
		&& g_map->walls->mx > 0 && g_map->walls->my > 0
		&& g_map->int_map[g_map->walls->my][g_map->walls->mx] == 1)
	{
		y = g_map->height;
		return (y);
	}
	else
	{
		g_map->walls->cx += g_map->walls->cmx;
		g_map->walls->cy += g_map->walls->cmy;
		y++;
		return (y);
	}
}

static void	ft_walls_ope(t_map *g_map, double negtan, double ra)
{
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		g_map->walls->cx = (((int)g_map->player->x / 64) * 64) - 0.0001;
		g_map->walls->cy = (g_map->player->x - g_map->walls->cx)
			* negtan + g_map->player->y;
		g_map->walls->cmx = 1;
		g_map->walls->cmy = -g_map->walls->cmx * negtan;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		g_map->walls->cx = (((int)g_map->player->x / 64) * 64) + 64;
		g_map->walls->cy = (g_map->player->x - g_map->walls->cx)
			* negtan + g_map->player->y;
		g_map->walls->cmx = 64;
		g_map->walls->cmy = -g_map->walls->cmx * negtan;
	}
}

void	ft_check_walls_lr(t_map *g_map)
{
	double		ra;
	double		negtan;
	int			r;
	uint32_t	y;

	r = -1;
	ra = g_map->player->pa;
	negtan = -tan(ra);
	while (++r < 1)
	{
		y = 0;
		if ((ra > (PI / 2) && ra < (3 * PI / 2))
			|| ra < (PI / 2) || ra > (3 * PI / 2))
			ft_walls_ope(g_map, negtan, ra);
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

void	ft_lowest(t_map *g_map)
{
	double	tempx;
	double	tempy;
	double	kimjongun;

	g_map->walls->northkorea = 1000000;
	ft_check_walls_ud(g_map);
	ft_printf("ud my : %d\n", g_map->walls->my);
	ft_printf("ud mx : %d\n", g_map->walls->mx);
	tempx = g_map->walls->cx;
	tempy = g_map->walls->cy;
	g_map->walls->northkorea = sqrt(
			((g_map->player->x - tempx) * (g_map->player->x - tempx))
			+ ((g_map->player->y - tempy) * (g_map->player->y - tempy)));
	ft_check_walls_lr(g_map);
	ft_printf("lr my : %d\n", g_map->walls->my);
	ft_printf("lr mx : %d\n", g_map->walls->mx);
	kimjongun = sqrt(((g_map->player->x - g_map->walls->cx)
				* (g_map->player->x - g_map->walls->cx))
			+ ((g_map->player->y - g_map->walls->cy)
				* (g_map->player->y - g_map->walls->cy)));
	if (g_map->walls->northkorea < kimjongun)
	{
		g_map->walls->cx = tempx;
		g_map->walls->cy = tempy;
	}
}
