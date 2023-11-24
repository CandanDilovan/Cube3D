/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:44:11 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/24 12:45:37 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_load_texture(t_map *g_map)
{
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
	g_map->texture->door = malloc(sizeof(mlx_texture_t *) * 2);
	g_map->texture->door[0] = mlx_load_png("src/img/stonewall.png");
	g_map->texture->door[1] = mlx_load_png("src/img/Blue64.png");
	if (!g_map->texture->door)
		return (-1);
	return (0);
}

static int	ft_malloc_text(t_map *g_map)
{
	g_map->texture = malloc(sizeof(t_texture));
	if (!g_map->texture)
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