/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:51:35 by babels            #+#    #+#             */
/*   Updated: 2023/11/09 16:44:39 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	setup_start_dir(t_map *g_map, char direction)
{
	if (direction == 'N')
		set_north(g_map);
	else if (direction == 'S')
		set_south(g_map);
	else if (direction == 'W')
		set_west(g_map);
	else if (direction == 'E')
		set_east(g_map);
}

void	set_south(t_map *g_map)
{
	g_map->player->pa = (2 * PI) / 4;
	g_map->player->dirx = 0;
	g_map->player->diry = 0.66;
}

void	set_north(t_map *g_map)
{
	g_map->player->pa = -(2 * PI) / 4;
	g_map->player->dirx = 0;
	g_map->player->diry = -0.66;
}

void	set_west(t_map *g_map)
{
	g_map->player->pa = PI;
	g_map->player->dirx = 0.66;
	g_map->player->diry = 0;
}

void	set_east(t_map *g_map)
{
	g_map->player->pa = 2 * PI;
	g_map->player->dirx = -0.66;
	g_map->player->diry = 0;
}
