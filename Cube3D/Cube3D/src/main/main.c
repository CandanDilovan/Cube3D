/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:09:02 by aabel             #+#    #+#             */
/*   Updated: 2023/11/27 14:11:38 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_set_map(t_map *g_map)
{
	mlx_image_t	*background;
	uint32_t	x;
	uint32_t	y;

	y = -1;
	g_map->mlx = mlx_init(WW, WH, "Cube3D", true);
	background = mlx_new_image(g_map->mlx, WW, WH);
	printf("Press 'M' to enable mouse and 'N' to disable it\n");
	mlx_set_mouse_pos(g_map->mlx, WW / 2, WH / 2);
	while (++y < WH)
	{
		x = -1;
		while (++x < WW)
		{
			if (y < WH / 2)
				mlx_put_pixel(background, x, y,
					ft_get_colors(g_map->texture->ceilling));
			else if (y > WH / 2)
				mlx_put_pixel(background, x, y,
					ft_get_colors(g_map->texture->floor));
		}
	}
	mlx_image_to_window(g_map->mlx, background, 0, 0);
}

static int	ft_parsing_verif2(t_map *g_map, char *argv)
{
	g_map->player = malloc(sizeof(t_player));
	if (!g_map->player)
		return (free(g_map), -1);
	g_map->walls = malloc(sizeof(t_walls));
	if (!g_map->walls)
		return (free(g_map->player), free(g_map), -1);
	if (map_count(g_map, argv) == -1)
		return (ft_free_maperror(g_map), -1);
	if (ft_int_map(g_map) == -1)
		return (free(g_map), -1);
	if (ft_no_void(g_map) == -1)
		return (-1);
	if (ft_textures(g_map) == -1)
		return (-1);
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
		if (ft_parsing_verif2(g_map, argv[1]) == -1)
			return (NULL);
	}
	return (g_map);
}

static int	init_map(t_map *g_map)
{
	if (!g_map->c || !g_map->f)
		return (ft_return_error("Something's wrong with colors"), -1);
	g_map->texture->ceilling = ft_rgb(g_map->c);
	if (!g_map->texture->ceilling)
		return (ft_free_text(g_map),
			ft_return_error("Something's wrong with colors"), -1);
	g_map->texture->floor = ft_rgb(g_map->f);
	if (!g_map->texture->floor)
		return (free(g_map->texture->ceilling), ft_free_text(g_map),
			ft_return_error("Something's wrong with colors"), -1);
	g_map->mouse = 0;
	g_map->mouse_moved = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*g_map;

	g_map = ft_parsing_verif(argc, argv);
	system("leaks Cub3D");
	if (!g_map)
		return (-1);
	init_player(g_map);
	init_door(g_map);
	if (init_map(g_map) == -1)
		return (-1);
	ft_set_map(g_map);
	g_map->image = setup_image(g_map);
	g_map->player->ray = mlx_new_image(g_map->mlx, WW, WH);
	mlx_image_to_window(g_map->mlx, g_map->player->ray, 0, 0);
	mlx_loop_hook(g_map->mlx, ft_move, g_map);
	mlx_loop(g_map->mlx);
	ft_endgame(g_map);
	return (0);
}
