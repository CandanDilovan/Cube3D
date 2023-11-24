/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:20:16 by dcandan           #+#    #+#             */
/*   Updated: 2023/11/24 12:22:50 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_endgame2(t_map *g_map)
{
	mlx_delete_texture(g_map->texture->south);
	mlx_delete_texture(g_map->texture->north);
	mlx_delete_texture(g_map->texture->east);
	mlx_delete_texture(g_map->texture->west);
	mlx_delete_texture(g_map->texture->door[0]);
	mlx_delete_texture(g_map->texture->door[1]);
	free(g_map->texture->door);
	free(g_map->image);
	free(g_map->texture->ceilling);
	free(g_map->texture->floor);
	free(g_map->player);
	free(g_map->walls);
	free(g_map->texture);
	free(g_map->c);
	free(g_map->f);
	free(g_map->no);
	free(g_map->ea);
	free(g_map->so);
	free(g_map->we);
	mlx_terminate(g_map->mlx);
	free(g_map);
}

void	ft_endgame(t_map *g_map)
{
	int	a;

	a = -1;
	mlx_delete_image(g_map->mlx, g_map->player->ray);
	mlx_delete_image(g_map->mlx, g_map->img);
	while (++a < (int)g_map->height)
		free(g_map->map[a]);
	a = -1;
	while (++a < (int)g_map->height)
		free(g_map->int_map[a]);
	a = -1;
	while (g_map->player->doors_nb < ++a)
		free(&g_map->doors[a]);
	a = -1;
	free(g_map->map);
	free(g_map->int_map);
	free(g_map->doors);
	while (g_map->player->doors_nb < ++a)
		mlx_delete_image(g_map->mlx, g_map->image->door_img[a]);
	mlx_delete_image(g_map->mlx, g_map->image->map_floor);
	mlx_delete_image(g_map->mlx, g_map->image->map_player);
	mlx_delete_image(g_map->mlx, g_map->image->map_void);
	mlx_delete_image(g_map->mlx, g_map->image->map_wall);
	mlx_delete_image(g_map->mlx, g_map->image->map_door);
	ft_endgame2(g_map);
}
