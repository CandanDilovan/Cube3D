/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:20:57 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/27 14:11:31 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t	ft_get_colors(int *rgb)
{
	uint32_t	colors;
	int			a;

	a = 255;
	colors = (rgb[0] << 24);
	colors = colors | (rgb[1] << 16);
	colors = colors | (rgb[2] << 8);
	colors = colors | (a << 0);
	return (colors);
}

static double	ft_final_touch(t_map *g_map, t_walls *walls)
{
	double	a;

	a = walls->line;
	walls->x = g_map->player->x * TILE_SIZE;
	walls->y = g_map->player->y * TILE_SIZE;
	walls->wx = walls->x + (walls->anglex * a * TILE_SIZE);
	walls->wy = walls->y + (walls->angley * a * TILE_SIZE);
	a = sqrt(((walls->wx - walls->x) * (walls->wx - walls->x))
			+ ((walls->wy - walls->y) * (walls->wy - walls->y)));
	walls->lx = (walls->wx - walls->x) / a;
	walls->ly = (walls->wy - walls->y) / a;
	return (a);
}

static void	ft_draw_game(t_map *g_map, t_walls *walls, double a, int r)
{
	int	dstart;
	int	dend;
	int	y;

	y = -1;
	a = (int)(WH / walls->line);
	dstart = (-a / 2) + (WH / 2);
	if (dstart < 0)
		dstart = 0;
	dend = (a / 2) + (WH / 2);
	if (dend >= WH)
		dend = WH - 1;
	ft_draw_walls(g_map, dstart, a);
	y = -1;
	while (++y < WH)
	{
		if (y >= dstart && y <= dend)
			mlx_put_pixel(g_map->player->ray, r, y, ft_get_pixel(g_map));
		else
			mlx_put_pixel(g_map->player->ray, r, y, 0);
	}
}

void	ft_paint_ray(t_map *g_map, t_walls *walls)
{
	uint32_t		r;
	double			a;
	double			ra;

	r = -1;
	a = 0.0;
	ra = g_map->player->pa - (DR * 30);
	while (++r < WW)
	{
		ft_check_walls_ud(g_map, ra);
		ft_final_touch(g_map, walls);
		ft_draw_game(g_map, g_map->walls, a, r);
		ra += DR / 20;
	}
}

void	init_player(t_map *g_map)
{
	int	y;
	int	x;

	find_spawn(g_map->map, &y, &x);
	g_map->player->x = x + 0.5;
	g_map->player->y = y + 0.5;
	setup_start_dir(g_map, g_map->map[y][x]);
	g_map->player->dirx = cos(g_map->player->pa);
	g_map->player->diry = sin(g_map->player->pa);
	g_map->texture->time = 2.0;
	g_map->texture->flag = 0;
}
