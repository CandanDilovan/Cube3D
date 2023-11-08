/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:49:41 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/08 14:25:35 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int32_t	ft_set_map(t_map *g_map)
{
	mlx_image_t	*background;
	uint32_t	x;
	uint32_t	y;

	y = -1;
	g_map->mlx = mlx_init(WW, WH, "Cube3D", true);
	background = mlx_new_image(g_map->mlx, WW, WH);
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
	mlx_image_to_window(g_map->mlx, g_map->player->ray, 0, 0);
}

// static void	ft_paint_map(t_map *g_map)
// {
// 	uint32_t		x;
// 	uint32_t		y;
// 	mlx_image_t		*img;
// 	mlx_image_t		*wimg;
// 	mlx_texture_t	*ntm;

// 	y = -1;
// 	ntm = mlx_load_png("src/img/DarkBlue64.png");
// 	img = mlx_texture_to_image(g_map->mlx, ntm);
// 	ntm = mlx_load_png("src/img/Black64.png");
// 	wimg = mlx_texture_to_image(g_map->mlx, ntm);
// 	while (g_map->height > ++y)
// 	{
// 		x = -1;
// 		while (ft_strlen(g_map->map[y]) > ++x)
// 		{
// 			if (g_map->map[y][x] && g_map->int_map[y][x] == 1)
// 				mlx_image_to_window(g_map->mlx, img,
// 					(x * TILE_SIZE), (y * TILE_SIZE));
// 			else if (g_map->map[y][x] && g_map->int_map[y][x] == 0)
// 				mlx_image_to_window(g_map->mlx, wimg,
// 					(x * TILE_SIZE), (y * TILE_SIZE));
// 		}
// 	}
// }

// static void	ft_paint_player(t_map *g_map)
// {
// 	int			x;
// 	int			y;

// 	y = -1;
// 	g_map->img = mlx_new_image(g_map->mlx, 13, 12);
// 	while (++y < 12)
// 	{
// 		x = -1;
// 		while (++x < 13)
// 			mlx_put_pixel(g_map->img, x, y, 0x00FFFFFF);
// 	}
// 	mlx_image_to_window(g_map->mlx, g_map->img,
// 		(g_map->player->x * TILE_SIZE), (g_map->player->y * TILE_SIZE));
// }

// static void	ft_print_intmap(t_map *g_map)
// {
// 	uint32_t	y;
// 	uint32_t	x;

// 	y = -1;
// 	ft_printf("\n\nInt map : \n");
// 	while (g_map->height > ++y)
// 	{
// 		x = -1;
// 		while (ft_strlen(g_map->map[y]) > ++x)
// 			ft_printf("%d", g_map->int_map[y][x]);
// 		ft_printf("\n");
// 	}
// }

static int32_t	ft_set_map(t_map *g_map)
{
	int			win_h;
	int			win_w;

	win_h = (g_map->height) * TILE_SIZE;
	win_w = (g_map->widht) * TILE_SIZE;
	g_map->mlx = mlx_init(win_w, win_h, "Cube3D", true);
	// ft_paint_map(g_map);
	// ft_paint_player(g_map);
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
	g_map->texture->floor = ft_rgb(g_map->f);
	if (!g_map->texture->ceilling || !g_map->texture->floor)
		return (ft_return_error("Something's wrong with colors"));
	ft_set_map(g_map);
	mlx_loop_hook(g_map->mlx, ft_move, g_map);
	mlx_loop(g_map->mlx);
	mlx_terminate(g_map->mlx);
}
