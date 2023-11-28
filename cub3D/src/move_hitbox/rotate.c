/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:28:58 by aabel             #+#    #+#             */
/*   Updated: 2023/11/27 13:39:23 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	mouse_hook(t_map *g_map)
{
	int	old_x;
	int	old_y;

	old_x = WW / 2;
	old_y = 0;
	mlx_get_mouse_pos(g_map->mlx, &old_x, &old_y);
	mouse_on_off(g_map);
	if (g_map->mouse == 1)
	{
		if (old_x > (WW / 2) + 20)
		{
			rotate_right(g_map, ((double)old_x - (WW / 2)));
			g_map->mouse_moved = 1;
		}
		if (old_x < (WW / 2) - 20)
		{
			rotate_left(g_map, ((double)old_x - (WW / 2)));
			g_map->mouse_moved = 1;
		}
	}
}

void	mouse_on_off(t_map *g_map)
{
	if (mlx_is_key_down(g_map->mlx, MLX_KEY_M))
		g_map->mouse = 1;
	if (mlx_is_key_down(g_map->mlx, MLX_KEY_N))
		g_map->mouse = 0;
	if (g_map->mouse == 1)
	{
		mlx_set_cursor_mode(g_map->mlx, MLX_MOUSE_HIDDEN);
		mlx_set_mouse_pos(g_map->mlx, WW / 2, WH / 2);
	}
	else
		mlx_set_cursor_mode(g_map->mlx, MLX_MOUSE_NORMAL);
}

void	rotate_left(t_map *g_map, double rotspeed)
{
	g_map->player->pa -= 0.025;
	rotspeed = rotspeed / 20;
	if (g_map->player->pa < 0 && rotspeed <= 0)
		g_map->player->pa += 2 * PI;
	if (g_map->player->pa < 0 && rotspeed > 0)
		g_map->player->pa += rotspeed;
	g_map->player->dirx = cos(g_map->player->pa);
	g_map->player->diry = sin(g_map->player->pa);
}

void	rotate_right(t_map *g_map, double rotspeed)
{
	g_map->player->pa += 0.025;
	rotspeed = rotspeed / 20;
	if (g_map->player->pa > 2 * PI && rotspeed <= 0)
		g_map->player->pa -= 2 * PI;
	if (g_map->player->pa > 2 * PI && rotspeed > 0)
		g_map->player->pa -= rotspeed;
	g_map->player->dirx = cos(g_map->player->pa);
	g_map->player->diry = sin(g_map->player->pa);
}
