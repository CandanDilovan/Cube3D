/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:20:16 by dcandan           #+#    #+#             */
/*   Updated: 2023/11/27 14:32:57 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_endgame2(t_map *g_map)
{
	int	a;

	a = -1;
	mlx_delete_texture(g_map->texture->south);
	mlx_delete_texture(g_map->texture->north);
	mlx_delete_texture(g_map->texture->east);
	mlx_delete_texture(g_map->texture->west);
	while (++a < 5)
		mlx_delete_texture(g_map->texture->door[a]);
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
	(free(g_map->ea), free(g_map->so), free(g_map->we));
	mlx_terminate(g_map->mlx);
	free(g_map);
}

void	ft_endgame(t_map *g_map)
{
	int	a;

	a = -1;
	while (++a < (int)g_map->height)
		free(g_map->map[a]);
	a = -1;
	while (++a < (int)g_map->height)
		free(g_map->int_map[a]);
	a = -1;
	(free(g_map->map), free(g_map->int_map));
	free(g_map->doors);
	ft_endgame2(g_map);
}

void	ft_free_maperror(t_map *g_map)
{
	int	a;

	if (g_map->c)
		free(g_map->c);
	if (g_map->f)
		free(g_map->f);
	if (g_map->no)
		free(g_map->no);
	if (g_map->ea)
		free(g_map->ea);
	if (g_map->so)
		free(g_map->so);
	if (g_map->we)
		free(g_map->we);
	a = -1;
	if (g_map->map)
	{
		while (++a < (int)g_map->height)
			free(g_map->map[a]);
		free(g_map->map);
	}
	free(g_map->player);
	free(g_map->walls);
	free(g_map);
}

void	ft_free_intmap(t_map *g_map)
{
	int	a;

	a = -1;
	while (++a < (int)g_map->height)
		free(g_map->int_map[a]);
	free(g_map->int_map);
	ft_free_maperror(g_map);
}

void	ft_free_text(t_map *g_map)
{
	int	a;

	a = -1;
	mlx_delete_texture(g_map->texture->south);
	mlx_delete_texture(g_map->texture->north);
	mlx_delete_texture(g_map->texture->east);
	mlx_delete_texture(g_map->texture->west);
	while (++a < 5)
		mlx_delete_texture(g_map->texture->door[a]);
	free(g_map->texture->door);
	free(g_map->texture);
	free(g_map->doors);
	ft_free_intmap(g_map);
}
