/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:46:42 by aabel             #+#    #+#             */
/*   Updated: 2023/11/08 14:49:04 by dilovancand      ###   ########.fr       */
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
		if (mlx_is_key_down(m, MLX_KEY_A) && !mlx_is_key_down(m, MLX_KEY_D))
			go_left(g_map);
		if (mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A))
			go_right(g_map);
		if (mlx_is_key_down(m, MLX_KEY_S) && !mlx_is_key_down(m, MLX_KEY_W))
			go_back(g_map);
		if (mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S))
			go_front(g_map);
		if (mlx_is_key_down(m, MLX_KEY_LEFT))
		{
			g_map->player->pa -= 0.025;
			if (g_map->player->pa < 0)
				g_map->player->pa += 2 * PI;
			g_map->player->dirx = cos(g_map->player->pa);
			g_map->player->diry = sin(g_map->player->pa);
		}
		if (mlx_is_key_down(m, MLX_KEY_RIGHT))
		{
			g_map->player->pa += 0.025;
			if (g_map->player->pa > 2 * PI)
				g_map->player->pa -= 2 * PI;
			g_map->player->dirx = cos(g_map->player->pa);
			g_map->player->diry = sin(g_map->player->pa);
		}
	}
	ft_paint_ray(g_map, g_map->walls);
}

void	go_front(t_map *g_map)
{
	if (!check_hitbox(g_map,
			(g_map->player->x + (g_map->player->dirx)),
			(g_map->player->y + (g_map->player->diry))))
	{
		g_map->player->x += g_map->player->dirx / 32;
		g_map->player->y += g_map->player->diry / 32;
	}
}

void	go_back(t_map *g_map)
{
	if (!check_hitbox(g_map,
			(g_map->player->x - (g_map->player->dirx)),
			(g_map->player->y - (g_map->player->diry))))
	{
		g_map->player->x -= g_map->player->dirx / 32;
		g_map->player->y -= g_map->player->diry / 32;
	}
}

void	go_left(t_map *g_map)
{
	if (!check_hitbox(g_map,
			(g_map->player->x + ((sin(g_map->player->pa - (2 * PI / 4))))),
			(g_map->player->y + ((cos(g_map->player->pa - (PI / 2)))))))
	{
		g_map->player->x += ((cos(g_map->player->pa - (PI / 2))) / 32);
		g_map->player->y += ((sin(g_map->player->pa - (2 * PI / 4))) / 32);
	}
}

void	go_right(t_map *g_map)
{
	if (!check_hitbox(g_map,
			(g_map->player->x + ((sin(g_map->player->pa + (2 * PI / 4))))),
			(g_map->player->y + ((cos(g_map->player->pa + (PI / 2)))))))
	{
		g_map->player->x += ((cos(g_map->player->pa + (PI / 2))) / 32);
		g_map->player->y += ((sin(g_map->player->pa + (2 * PI / 4))) / 32);
	}
}
