/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:12:44 by aabel             #+#    #+#             */
/*   Updated: 2023/11/27 14:28:39 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t	ft_colors(uint32_t colors)
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	a = colors >> 24;
	r = colors >> 16;
	g = colors >> 8;
	b = colors;
	return (r << 8 | g << 16 | b << 24 | a << 0);
}

void	ft_load_images(t_map *g_map)
{
	g_map->texture->door[0] = mlx_load_png("src/img/door00.png");
	g_map->texture->door[1] = mlx_load_png("src/img/door01.png");
	g_map->texture->door[2] = mlx_load_png("src/img/door02.png");
	g_map->texture->door[3] = mlx_load_png("src/img/door03.png");
	g_map->texture->door[4] = mlx_load_png("src/img/door04.png");
}

void	ft_check_doors(t_map *g_map)
{
	int	a;

	a = 0;
	while (a < g_map->player->doors_nb)
	{
		if (player_range_door(g_map, &g_map->doors[a]) == 1)
		{
			open_door(g_map, &g_map->doors[a], 1);
		}
		else if (player_range_door(g_map, &g_map->doors[a]) == -1)
		{
			open_door(g_map, &g_map->doors[a], 0);
		}
		a++;
	}
}
