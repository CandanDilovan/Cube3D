/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:44:11 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/15 16:08:50 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_load_texture(t_map *g_map)
{
	ft_printf("\n%s", g_map->no);
	g_map->texture->north[0] = mlx_load_png(g_map->no);
	g_map->texture->north[1] = mlx_load_png(g_map->no2);
	if (!g_map->texture->north[0])
		return (-1);
	g_map->texture->south[0] = mlx_load_png(g_map->so);
	g_map->texture->south[1] = mlx_load_png(g_map->so2);
	if (!g_map->texture->south[0])
		return (-1);
	g_map->texture->east[0] = mlx_load_png(g_map->ea);
	g_map->texture->east[1] = mlx_load_png(g_map->ea2);
	if (!g_map->texture->east[0])
		return (-1);
	g_map->texture->west[0] = mlx_load_png(g_map->we);
	g_map->texture->west[1] = mlx_load_png(g_map->we);
	if (!g_map->texture->west[0])
		return (-1);
	g_map->texture->door = mlx_load_png("src/img/stonewall.png");
	if (!g_map->texture->door)
		return (-1);
	return (0);
}

static int	ft_malloc_text(t_map *g_map)
{
	g_map->texture = malloc(sizeof(t_texture));
	if (!g_map->texture)
		return (ft_return_error("malloc failed"));
	g_map->texture->north = malloc(sizeof(mlx_texture_t) * 2);
	g_map->texture->south = malloc(sizeof(mlx_texture_t) * 2);
	g_map->texture->west = malloc(sizeof(mlx_texture_t) * 2);
	g_map->texture->east = malloc(sizeof(mlx_texture_t) * 2);
	if (!g_map->texture->north || !g_map->texture->south
		|| !g_map->texture->west || !g_map->texture->east)
		return (ft_return_error("malloc failed"));
	return (0);
}

int	ft_textures(t_map *g_map)
{
	ft_malloc_text(g_map);
	if (ft_load_texture(g_map) == -1)
		return (ft_return_error("Error : Wrong texture"));
	return (0);
}
