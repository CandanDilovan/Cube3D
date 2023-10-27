/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:49:41 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/27 15:27:40 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_paint_ray(t_map *g_map)
{
	double	a;
	double	x;
	double	y;

	a = g_map->player->line;
	x = g_map->player->x * 64;
	y = g_map->player->y * 64;
	if (g_map->player->ray)
		mlx_delete_image(g_map->mlx, g_map->player->ray);
	g_map->player->ray = mlx_new_image(g_map->mlx,
			(g_map->widht * TILE_SIZE), (g_map->height * TILE_SIZE));
	printf("line : %f\n", a);
	a *= 64;
	while (a > 0)
	{
		mlx_put_pixel(g_map->player->ray, (x + 6),
			(y + 6), 0xFFFFFF);
		x += g_map->player->dirx;
		y += g_map->player->diry;
		a--;
	}
	mlx_image_to_window(g_map->mlx, g_map->player->ray, 0, 0);
}

void	ft_move(void *param)
{
	t_map		*g_map;
	mlx_t		*m;

	g_map = (t_map *)param;
	m = g_map->mlx;
	if (mlx_is_key_down(m, MLX_KEY_ESCAPE))
		mlx_close_window(m);
	if (g_map)
	{
		if (mlx_is_key_down(m, MLX_KEY_A) && !mlx_is_key_down(m, MLX_KEY_D)
			&& !mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S))
		{
			g_map->player->pa -= 0.01;
			if (g_map->player->pa < 0)
				g_map->player->pa += 2 * PI;
			g_map->player->dirx = cos(g_map->player->pa);
			g_map->player->diry = sin(g_map->player->pa);
			ft_check_walls_ud(g_map);
			ft_paint_ray(g_map);
		}
		if (mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A)
			&& !mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S))
		{
			g_map->player->pa += 0.01;
			if (g_map->player->pa > 2 * PI)
				g_map->player->pa -= 2 * PI;
			g_map->player->dirx = cos(g_map->player->pa);
			g_map->player->diry = sin(g_map->player->pa);
			ft_check_walls_ud(g_map);
			ft_paint_ray(g_map);
		}
		if (mlx_is_key_down(m, MLX_KEY_S) && !mlx_is_key_down(m, MLX_KEY_W)
			&& !mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A))
		{
			g_map->player->x -= g_map->player->dirx / 32;
			g_map->player->y -= g_map->player->diry / 32;
			g_map->img->instances[0].x = g_map->player->x * TILE_SIZE;
			g_map->img->instances[0].y = g_map->player->y * TILE_SIZE;
			ft_check_walls_ud(g_map);
			ft_paint_ray(g_map);
		}
		if (mlx_is_key_down(m, MLX_KEY_W) && !mlx_is_key_down(m, MLX_KEY_S)
			&& !mlx_is_key_down(m, MLX_KEY_D) && !mlx_is_key_down(m, MLX_KEY_A))
		{
			g_map->player->x += g_map->player->dirx / 32;
			g_map->player->y += g_map->player->diry / 32;
			g_map->img->instances[0].x = g_map->player->x * TILE_SIZE;
			g_map->img->instances[0].y = g_map->player->y * TILE_SIZE;
			ft_check_walls_ud(g_map);
			ft_paint_ray(g_map);
		}
	}
}

static void	ft_paint_map(t_map *g_map)
{
	uint32_t		x;
	uint32_t		y;
	mlx_image_t		*img;
	mlx_image_t		*wimg;
	mlx_texture_t	*ntm;

	y = -1;
	ntm = mlx_load_png("src/img/DarkBlue64.png");
	img = mlx_texture_to_image(g_map->mlx, ntm);
	ntm = mlx_load_png("src/img/Black64.png");
	wimg = mlx_texture_to_image(g_map->mlx, ntm);
	while (g_map->height > ++y)
	{
		x = -1;
		while (ft_strlen(g_map->map[y]) > ++x)
		{
			if (g_map->map[y][x] && g_map->int_map[y][x] == 1)
				mlx_image_to_window(g_map->mlx, img,
					(x * TILE_SIZE), (y * TILE_SIZE));
			else if (g_map->map[y][x] && g_map->int_map[y][x] == 0)
				mlx_image_to_window(g_map->mlx, wimg,
					(x * TILE_SIZE), (y * TILE_SIZE));
		}
	}
}


static void	ft_paint_player(t_map *g_map)
{
	int			x;
	int			y;

	y = -1;
	g_map->img = mlx_new_image(g_map->mlx, 13, 12);
	while (++y < 12)
	{
		x = -1;
		while (++x < 13)
			mlx_put_pixel(g_map->img, x, y, 0x00FFFFFF);
	}
	mlx_image_to_window(g_map->mlx, g_map->img,
		(g_map->player->x * TILE_SIZE), (g_map->player->y * TILE_SIZE));
}

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
	ft_paint_map(g_map);
	ft_paint_player(g_map);
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
		g_map->walls = malloc(sizeof(t_walls));
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
		g_map->player->avionx = 0;
		g_map->player->avionx = 0.66;
		g_map->player->dirx = -1;
		g_map->player->diry = 0;
		g_map->player->dirx = cos(g_map->player->pa) * 2;
		g_map->player->diry = sin(g_map->player->pa) * 2;
	}
	ft_set_map(g_map);
	mlx_loop_hook(g_map->mlx, ft_move, g_map);
	mlx_loop(g_map->mlx);
	mlx_terminate(g_map->mlx);
}
