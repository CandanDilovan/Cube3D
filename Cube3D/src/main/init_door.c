/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:26 by aabel             #+#    #+#             */
/*   Updated: 2023/11/15 12:14:29 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_door(t_map *g_map)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = -1;
	y = -1;

	g_map->doors = malloc(sizeof(t_doors *) * (count_doors(g_map) + 1));
	while (g_map->map[++y])
	{
		while (g_map->map[y][++x])
			if (g_map->map[y][x] == 'D')
				g_map->doors[++i] = *create_door(x, y);
			x = -1;
	}
	// g_map->doors[i + 1] = NULL;
}

int	count_doors(t_map *g_map)
{
	int			i;
	uint32_t	x;
	uint32_t	y;

	i = 0;
	y = -1;
	while (++y < g_map->height)
	{
		x = -1;
		while (++x < g_map->widht)
			if (g_map->map[y][x] == 'D')
				i++;
	}
	return (i);
}

t_doors	*create_door(int x, int y)
{
	t_doors	*door;

	door = malloc(sizeof(t_doors));
	if (!door)
		return (NULL);
	door->x = x;
	door->y = y;
	door->state = 'C';
	door->current_img = 0;
	return (door);
}

int	player_range_door(t_map *g_map)
{
	double	ydistance;
	double	xdistance;

	ydistance = 0;
	xdistance = 0;

	ydistance = g_map->player->y - g_map->doors->y;
	xdistance = g_map->player->x - g_map->doors->x;
	printf("ydistance = %f\n", ydistance);
	printf("xdistance = %f\n", xdistance);
	if (ydistance <= 2 || ydistance >= -2)
	{
		if (xdistance <= 2 || xdistance >= -2)
			return (1);
	}
	else
		return (-1);
	return (0);
}
