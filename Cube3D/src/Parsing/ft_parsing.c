/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:46:09 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/09 16:22:20 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_hole_in_one(t_map *g_map, uint32_t y, uint32_t x)
{
	if (g_map->map[y][x] && (g_map->map[y][x] == '1' || g_map->map[y][x] == '0'
		|| g_map->map[y][x] == 'N' || g_map->map[y][x] == 'S'
		|| g_map->map[y][x] == 'E' || g_map->map[y][x] == 'W'))
		return (0);
	else
		return (-1);
}

static int	ft_check_holes(t_map *g_map, uint32_t y, uint32_t x)
{
	if (ft_hole_in_one(g_map, y + 1, x) == -1)
		return (-1);
	if (ft_hole_in_one(g_map, y - 1, x) == -1)
		return (-1);
	if (ft_hole_in_one(g_map, y, x + 1) == -1)
		return (-1);
	if (ft_hole_in_one(g_map, y, x - 1) == -1)
		return (-1);
	return (0);
}

int	ft_no_void(t_map *g_map)
{
	uint32_t	x;
	uint32_t	y;
	int			flag;

	flag = 0;
	y = -1;
	while (g_map->height > ++y)
	{
		ft_is_map(g_map->map[y], &flag);
		x = -1;
		ft_printf("%s", g_map->map[y]);
		while ((uint32_t)ft_strlen_g_map(g_map->map[y]) > ++x)
		{
			if (g_map->map[y][x] == '0' && flag == 1)
			{
				if (ft_check_holes(g_map, y, x) == -1)
					return (ft_return_error("Error : map is open"));
			}
		}
	}
	return (0);
}
