/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:46:09 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/27 17:06:29 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_hole_in_one(int **map, uint32_t y, uint32_t x)
{
	if (map[y][x] != -1)
		return (0);
	else
		return (-1);
}

static int	ft_check_holes(t_map *g_map, uint32_t y, uint32_t x)
{
	if (g_map->int_map[y][x] && g_map->int_map[y][x] > 1)
	{
		if (x == 0 || y == 0 || y == g_map->height
			|| x == (uint32_t)ft_strlen(g_map->map[y]))
			return (-1);
		if (ft_hole_in_one(g_map->int_map, y + 1, x) == -1)
			return (-1);
		if (ft_hole_in_one(g_map->int_map, y - 1, x) == -1)
			return (-1);
		if (ft_hole_in_one(g_map->int_map, y, x + 1) == -1)
			return (-1);
		if (ft_hole_in_one(g_map->int_map, y, x - 1) == -1)
			return (-1);
	}
	return (0);
}

static void	ft_check_spawn(t_map *g_map, int x, int y, int *flag)
{
	if (g_map->map[y][x] && (g_map->map[y][x] == 'N'
		|| g_map->map[y][x] == 'S'
		|| g_map->map[y][x] == 'E' || g_map->map[y][x] == 'W'))
	{
		*flag = *flag + 1;
	}
}

int	ft_no_void(t_map *g_map)
{
	uint32_t	x;
	uint32_t	y;
	int			flag;
	int			flag2;

	flag = 0;
	flag2 = 0;
	y = -1;
	while (g_map->height > ++y)
	{
		ft_is_map(g_map->map[y], &flag);
		x = -1;
		while ((uint32_t)ft_strlen_g_map(g_map->map[y]) > ++x)
		{
			if (g_map->map[y][x] != '1' && flag == 1)
				if (ft_check_holes(g_map, y, x) == -1)
					return (ft_free_intmap(g_map),
						ft_return_error("Error : map is open"), -1);
			ft_check_spawn(g_map, x, y, &flag2);
		}
	}
	if (flag2 != 1)
		return (ft_return_error("Error : spawn"), -1);
	return (0);
}
