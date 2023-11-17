/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:46:26 by aabel             #+#    #+#             */
/*   Updated: 2023/11/17 20:53:49 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_door(t_map *g_map)
{
	int			i;
	uint32_t	x;
	uint32_t	y;

	i = -1;
	y = -1;
	g_map->doors = malloc(sizeof(t_doors *) * (count_doors(g_map)));
	while (++y < g_map->height)
	{
		x = -1;
		while (++x < (uint32_t)ft_strlen_g_map(g_map->map[y]))
			if (g_map->map[y][x] == 'D')
				g_map->doors[++i] = create_door(x, y);
	}
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
		while (++x < (uint32_t)ft_strlen_g_map(g_map->map[y]))
			if (g_map->map[y][x] == 'D')
				i++;
	}
	g_map->player->doors_nb = i;
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
	door->state = 'D';
	door->current_img = 0;
	return (door);
}

int	player_range_door(t_map *g_map, t_doors *door)
{
	double	ydistance;
	double	xdistance;

	ydistance = door->y - g_map->player->y;
	xdistance = door->x - g_map->player->x;
	// printf("ydistance = %f\n", ydistance);
	// printf("xdistance = %f\n", xdistance);
	if (ydistance > xdistance)
	{
		if (ydistance <= 2 && ydistance >= -2)
			if (xdistance <= 2 && xdistance >= -2)
				return (1);
		return (-1);
	}
	else
	{
		if (xdistance <= 2 && xdistance >= -2)
			if (ydistance <= 2 && ydistance >= -2)
				return (1);
		return (-1);
	}
	return (0);
}

void	open_door(t_map *g_map, t_doors *door, int flag)
{
	if (flag == 1)
	{
			g_map->map[door->y][door->x] = '0';
	}
	else if (flag == 0)
	{
			g_map->map[door->y][door->x] = 'D';
	}
}