/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impossible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:27:58 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/17 20:00:41 by dilovancand      ###   ########.fr       */
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

void	ft_machin(t_map *g_map)
{
	int			i;
	int			a;
	int			b;
	uint32_t	x[2];

	a = 1;
	i = 2;
	while (a > 0)
	{
		x[0] = -1;
		while (g_map->height > ++x[0])
		{
			x[1] = -1;
			while (g_map->widht > ++x[1])
			{
				if (g_map->int_map[x[0]][x[1]] == i)
					ft_fill(g_map, x, &a);
			}
		}
		i++;
		a--;
	}
	a = -1;
	while ((int)g_map->height > ++a)
	{
		b = -1;
		while ((int)ft_strlen(g_map->map[a]) > ++b)
		{
			if (g_map->int_map[a][b] > 1)
				ft_printf("%d", 2);
			else 
				ft_printf("%d", g_map->int_map[a][b]);
		}
		ft_printf("\n");
	}
}
