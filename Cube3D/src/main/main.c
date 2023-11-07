/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:49:41 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/07 16:01:16 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int32_t	ft_set_map(t_map *g_map)
{

	g_map->mlx = mlx_init(WW, WH, "Cube3D", true);
	return (0);
}

static t_map	*ft_parsing_verif(int argc, char **argv)
{
	t_map	*g_map;

	if (argc < 2)
		return (ft_return_error("Error : too few arguments"), NULL);
	if (ft_is_cub(argv[1]) == -1)
		return (ft_return_error("Error : map is not .cub"), NULL);
	else
	{
		g_map = malloc(sizeof(t_map));
		if (!g_map)
			return (NULL);
		g_map->player = malloc(sizeof(t_player));
		g_map->walls = malloc(sizeof(t_walls));
		g_map->texture = malloc(sizeof(t_texture));
		if (map_count(g_map, argv[1]) == -1 || ft_int_map(g_map) == -1)
			return (free(g_map), ft_return_error("Error : FD failed"), NULL);
		if (ft_no_void(g_map) == -1)
			return (NULL);
		// if (ft_textures(g_map) == -1)
		// 	return (NULL);
	}
	return (g_map);
}

int	main(int argc, char **argv)
{
	t_map	*g_map;

	g_map = ft_parsing_verif(argc, argv);
	if (!g_map)
		return (-1);
	g_map->player->x = 1.5;
	g_map->player->y = 1.5;
	g_map->player->pa = 0;
	g_map->player->dirx = cos(g_map->player->pa);
	g_map->player->diry = sin(g_map->player->pa);
	g_map->texture->ceilling = ft_rgb(g_map->c);
	ft_printf("\n%d\n", g_map->texture->ceilling[1]);
	g_map->texture->floor = ft_rgb(g_map->f);
	if (!g_map->texture->ceilling || !g_map->texture->floor)
		return (ft_return_error("Something's wrong with colors"));
	ft_set_map(g_map);
	mlx_loop_hook(g_map->mlx, ft_move, g_map);
	mlx_loop(g_map->mlx);
	mlx_terminate(g_map->mlx);
}
