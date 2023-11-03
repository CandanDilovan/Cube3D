/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:49:41 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/03 13:57:08 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static double	ft_final_touch(t_map *g_map, t_walls *walls)
{
	double	a;

	a = walls->line;
	walls->x = g_map->player->x * TILE_SIZE;
	walls->y = g_map->player->y * TILE_SIZE;
	walls->wx = walls->x + (walls->anglex * a * TILE_SIZE);
	walls->wy = walls->y + (walls->angley * a * TILE_SIZE);
	a = sqrt(((walls->wx - walls->x) * (walls->wx - walls->x))
			+ ((walls->wy - walls->y) * (walls->wy - walls->y)));
	walls->lx = (walls->wx - walls->x) / a;
	walls->ly = (walls->wy - walls->y) / a;
	return (a);
}

static void	ft_draw_game(t_map *g_map, t_walls *walls, double a, int r)
{
	uint32_t	dstart;
	uint32_t	dend;
	uint32_t	y;
	int 		jsp;

	y = 0;
	a = (int)((g_map->height * TILE_SIZE) / walls->line);
	dstart = -a / 2 + (g_map->height * TILE_SIZE) / 2;
	if (dstart < 0)
		dstart = 0;
	dend = a / 2 + (g_map->height * TILE_SIZE) / 2;
	if (dend >= g_map->height)
		dend = (g_map->height * TILE_SIZE) - 1;
	jsp = (r + 1) * ((g_map->widht * TILE_SIZE) / 120);
	r = r * ((g_map->widht * TILE_SIZE) / 120);
	while (r < jsp)
	{
		y = 0;
		while (y < (g_map->height * TILE_SIZE))
		{
			if (y >= dstart && y <= dend)
				mlx_put_pixel(g_map->player->ray, r, y, 0xFFFFFF);
			else
				mlx_put_pixel(g_map->player->ray, r, y, 0);
			y++;
		}
		r++;
	}
}

void	ft_paint_ray(t_map *g_map, t_walls **walls)
{
	int		r;
	double	a;
	double	ra;

	r = -1;
	a = 0.0;
	if (g_map->player->ray)
		mlx_delete_image(g_map->mlx, g_map->player->ray);
	g_map->player->ray = mlx_new_image(g_map->mlx,
			(g_map->widht * TILE_SIZE), (g_map->height * TILE_SIZE));
	ra = g_map->player->pa - (DR * 30);
	while (++r < 120)
	{
		ft_check_walls_ud(g_map, ra, r);
		ft_final_touch(g_map, walls[r]);
		ft_draw_game(g_map, g_map->walls[r], a, r);
		ra += DR;
	}
	mlx_image_to_window(g_map->mlx, g_map->player->ray, 0, 0);
}

// void	ft_move(void *param)
// {
// 	t_map		*g_map;
// 	mlx_t		*m;

// 	g_map = (t_map *)param;
// 	m = g_map->mlx;
// 	if (mlx_is_key_down(m, MLX_KEY_ESCAPE))
// 		mlx_close_window(m);
// 	if (g_map)
// 	{
// 		if (mlx_is_key_down(m, MLX_KEY_A) && !mlx_is_key_down(m, MLX_KEY_D)
// 			&& !mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S))
// 		{
// 			g_map->player->pa -= 0.01;
// 			if (g_map->player->pa < 0)
// 				g_map->player->pa += 2 * PI;
// 			g_map->player->dirx = cos(g_map->player->pa);
// 			g_map->player->diry = sin(g_map->player->pa);
// 			ft_paint_ray(g_map, g_map->walls);
// 		}
// 		if (mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A)
// 			&& !mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S))
// 		{
// 			g_map->player->pa += 0.01;
// 			if (g_map->player->pa > 2 * PI)
// 				g_map->player->pa -= 2 * PI;
// 			g_map->player->dirx = cos(g_map->player->pa);
// 			g_map->player->diry = sin(g_map->player->pa);
// 			ft_paint_ray(g_map, g_map->walls);
// 		}
// 		if (mlx_is_key_down(m, MLX_KEY_S) && !mlx_is_key_down(m, MLX_KEY_W)
// 			&& !mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A))
// 		{
// 			g_map->player->x -= g_map->player->dirx / 32;
// 			g_map->player->y -= g_map->player->diry / 32;
// 			g_map->img->instances[0].x = g_map->player->x * TILE_SIZE;
// 			g_map->img->instances[0].y = g_map->player->y * TILE_SIZE;
// 			ft_paint_ray(g_map, g_map->walls);
// 		}
// 		if (mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S)
// 			&& !mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A))
// 		{
// 			g_map->player->x += g_map->player->dirx / 32;
// 			g_map->player->y += g_map->player->diry / 32;
// 			g_map->img->instances[0].x = g_map->player->x * TILE_SIZE;
// 			g_map->img->instances[0].y = g_map->player->y * TILE_SIZE;
// 			ft_paint_ray(g_map, g_map->walls);
// 		}
// 	}
// }

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

int	main(int argc, char **argv)
{
	t_map	*g_map;

	if (argc < 2)
		return (ft_return_error("Error : too few arguments"));
	if (ft_is_cub(argv[1]) == -1)
		return (ft_return_error("Error : map is not .cub"));
	else
	{
		g_map = malloc(sizeof(t_map));
		if (!g_map)
			return (-1);
		g_map->player = malloc(sizeof(t_player));
		g_map->walls = malloc(sizeof(t_walls *) * 120);
		if (map_count(g_map, argv[1]) == -1 || ft_int_map(g_map) == -1)
			return (free(g_map), ft_return_error("Error : FD failed"));
		if (ft_no_void(g_map) == -1)
			return (-1);
		// if (ft_textures(g_map) == -1)
			// return (-1);
		//ft_print_intmap(g_map);
		g_map->player->x = 1.5;
		g_map->player->y = 1.5;
		g_map->player->pa = 0;
		g_map->player->dirx = cos(g_map->player->pa);
		g_map->player->diry = sin(g_map->player->pa);
	}
	ft_set_map(g_map);
	mlx_loop_hook(g_map->mlx, ft_move, g_map);
	mlx_loop(g_map->mlx);
	mlx_terminate(g_map->mlx);
}
