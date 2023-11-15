/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/11/15 13:37:30 by aabel            ###   ########.fr       */
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
	printf("\nPress 'M' to enable mouse and 'N' to disable it\n");
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
		if (map_count(g_map, argv[1]) == -1 || ft_int_map(g_map) == -1)
			return (free(g_map), ft_return_error("Error : FD failed"), NULL);
		if (ft_no_void(g_map) == -1)
			return (NULL);
		if (ft_textures(g_map) == -1)
			return (NULL);
	}
	return (g_map);
}

void	init_player(t_map *g_map)
{
	int	y;
	int	x;

	find_spawn(g_map->map, &y, &x);
	g_map->player->x = x + 0.5;
	g_map->player->y = y + 0.5;
	setup_start_dir(g_map, g_map->map[y][x]);
	g_map->player->dirx = cos(g_map->player->pa);
	g_map->player->diry = sin(g_map->player->pa);
	g_map->texture->time = 2.0;
	g_map->texture->flag = 0;
}

void	find_spawn(char **map, int *x, int *y)
{
	*x = 0;
	*y = 0;
	if (!map)
		return ;
	while (map[*x])
	{
		*y = 0;
		while (map[*x][*y])
		{
			if (map[*x][*y] == 'N' || map[*x][*y] == 'E'
				|| map[*x][*y] == 'W' || map[*x][*y] == 'S')
				return ;
			(*y)++;
		}
		*y = 0;
		(*x)++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*g_map;

	g_map = ft_parsing_verif(argc, argv);
	if (!g_map)
		return (-1);
	init_player(g_map);
	init_door(g_map);
	g_map->texture->ceilling = ft_rgb(g_map->c);
	g_map->texture->floor = ft_rgb(g_map->f);
	g_map->mouse = 0;
	g_map->mouse_moved = 0;
	if (!g_map->texture->ceilling || !g_map->texture->floor)
		return (ft_return_error("Something's wrong with colors"));
	ft_set_map(g_map);
	g_map->player->ray = mlx_new_image(g_map->mlx, WW, WH);
	mlx_image_to_window(g_map->mlx, g_map->player->ray, 0, 0);
	// mlx_image_to_window(g_map->mlx, g_map->texture->door_img, 0, 0);
	mlx_loop_hook(g_map->mlx, ft_move, g_map);
	mlx_loop(g_map->mlx);
	mlx_terminate(g_map->mlx);
	return (0);
}
