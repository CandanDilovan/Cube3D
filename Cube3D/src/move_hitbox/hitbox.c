/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:22:25 by aabel             #+#    #+#             */
/*   Updated: 2023/10/27 15:44:09 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_hitbox(t_map *g_map, double player_x, double player_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g_map->map[y])
	{
		while (g_map->map[y][x])
		{
			if (g_map->map[y][x] == '1')
			{
				ft_printf("x : %d, y : %d\n", x, y);
				if (player_x < (x * TILE_SIZE + TILE_SIZE)
					&& (player_x) > (x * TILE_SIZE)
					&& (player_y) < (y * TILE_SIZE + TILE_SIZE)
					&& player_y > (y * TILE_SIZE))
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
