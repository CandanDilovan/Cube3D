/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impossible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:27:58 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/24 12:45:58 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_fill(t_map *g_map, uint32_t *x, int *a)
{
	if (g_map->map[x[0] + 1][x[1]] != '1'
		&& g_map->int_map[x[0] + 1][x[1]] == 0)
	{
		g_map->int_map[x[0] + 1][x[1]] = g_map->int_map[x[0]][x[1]] + 1;
		*a = *a + 1;
	}
	if (g_map->map[x[0] - 1][x[1]] != '1'
		&& g_map->int_map[x[0] - 1][x[1]] == 0)
	{
		g_map->int_map[x[0] - 1][x[1]] = g_map->int_map[x[0]][x[1]] + 1;
		*a = *a + 1;
	}
	if (g_map->map[x[0]][x[1] + 1] != '1'
		&& g_map->int_map[x[0]][x[1] + 1] == 0)
	{
		g_map->int_map[x[0]][x[1] + 1] = g_map->int_map[x[0]][x[1]] + 1;
		*a = *a + 1;
	}
	if (g_map->map[x[0]][x[1] - 1] != '1'
		&& g_map->int_map[x[0]][x[1] - 1] == 0)
	{
		g_map->int_map[x[0]][x[1] - 1] = g_map->int_map[x[0]][x[1]] + 1;
		*a = *a + 1;
	}
}

static int	ft_space(t_map *g_map, uint32_t *x, int *a, int i)
{
	while (g_map->height > ++x[0])
	{
		x[1] = -1;
		while (ft_strlen(g_map->map[x[0]]) > ++x[1])
		{
			if (g_map->int_map[x[0]][x[1]] == i)
			{
				if (g_map->map[x[0]][x[1]] != '1' && (x[1] == 0 || x[0] == 0
					|| x[0] == g_map->height
					|| x[1] == (uint32_t)ft_strlen(g_map->map[x[0]])))
				ft_fill(g_map, x, a);
			}
		}
	}
	return (0);
}

int	ft_machin(t_map *g_map)
{
	int			i;
	int			a;
	uint32_t	x[2];

	a = 1;
	i = 2;
	while (a > 0)
	{
		x[0] = -1;
		x[1] = -1;
		if (ft_space(g_map, x, &a, i) == -1)
			return (ft_return_error("Error : Map is open"), -1);
		i++;
		a--;
	}
	return (0);
}
