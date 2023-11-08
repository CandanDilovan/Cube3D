/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:44:11 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/08 14:25:21 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_load_texture(t_map *g_map)
{
	ft_printf("\n%s", g_map->no);
	g_map->texture->north = mlx_load_png(g_map->no);
	if (!g_map->texture->north)
		return (-1);
	g_map->texture->south = mlx_load_png(g_map->so);
	if (!g_map->texture->south)
		return (-1);
	g_map->texture->east = mlx_load_png(g_map->ea);
	if (!g_map->texture->east)
		return (-1);
	g_map->texture->west = mlx_load_png(g_map->we);
	if (!g_map->texture->west)
		return (-1);
	return (0);
}

int	ft_textures(t_map *g_map)
{
	if (!g_map->texture)
		return (ft_return_error("malloc failed"));
	if (ft_load_texture(g_map) == -1)
		return (ft_return_error("Error : Wrong texture"));
	return (0);
}
