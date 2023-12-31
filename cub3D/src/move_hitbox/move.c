/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:46:42 by aabel             #+#    #+#             */
/*   Updated: 2023/11/27 14:42:31 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_move(void *param)
{
	t_map		*g_map;
	mlx_t		*m;

	g_map = (t_map *)param;
	m = g_map->mlx;
	if (mlx_is_key_down(m, MLX_KEY_ESCAPE))
		mlx_close_window(m);
	if (g_map)
	{
		mouse_hook(g_map);
		if (mlx_is_key_down(m, MLX_KEY_A) && !mlx_is_key_down(m, MLX_KEY_D))
			go_left(g_map);
		if (mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A))
			go_right(g_map);
		if (mlx_is_key_down(m, MLX_KEY_S) && !mlx_is_key_down(m, MLX_KEY_W))
			go_back(g_map);
		if (mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S))
			go_front(g_map);
		if (mlx_is_key_down(m, MLX_KEY_LEFT))
			rotate_left(g_map, 0);
		if (mlx_is_key_down(m, MLX_KEY_RIGHT))
			rotate_right(g_map, 0);
	}
	ft_check_doors(g_map);
	(ft_paint_ray(g_map, g_map->walls), ft_minimap(g_map));
}

void	go_front(t_map *g_map)
{
	if (!check_hitbox(g_map,
			((g_map->player->x) + ((g_map->player->dirx / 4))),
			((g_map->player->y) + ((g_map->player->diry / 4)))))
	{
		g_map->player->x += g_map->player->dirx / 64;
		g_map->player->y += g_map->player->diry / 64;
	}
}

void	go_back(t_map *g_map)
{
	if (!check_hitbox(g_map,
			((g_map->player->x) - (g_map->player->dirx / 4)),
			((g_map->player->y) - (g_map->player->diry / 4))))
	{
		g_map->player->x -= g_map->player->dirx / 64;
		g_map->player->y -= g_map->player->diry / 64;
	}
}

void	go_left(t_map *g_map)
{
	if (!check_hitbox(g_map,
			((g_map->player->x)
				+ ((cos(g_map->player->pa - (2 * PI / 4)) / 2))),
			((g_map->player->y)
				+ ((sin(g_map->player->pa - (PI / 2)) / 2)))))
	{
		g_map->player->x += ((cos(g_map->player->pa - (PI / 2))) / 64);
		g_map->player->y += ((sin(g_map->player->pa - (2 * PI / 4))) / 64);
	}
}

void	go_right(t_map *g_map)
{
	if (!check_hitbox(g_map,
			((g_map->player->x)
				+ ((cos(g_map->player->pa + (2 * PI / 4)) / 2))),
			((g_map->player->y)
				+ ((sin(g_map->player->pa + (PI / 2)) / 2)))))
	{
		g_map->player->x += ((cos(g_map->player->pa + (PI / 2))) / 64);
		g_map->player->y += ((sin(g_map->player->pa + (2 * PI / 4))) / 64);
	}
}
