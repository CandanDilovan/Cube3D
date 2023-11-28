/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:24:34 by babels            #+#    #+#             */
/*   Updated: 2023/11/27 16:40:41 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_minimap(t_map *g_map)
{
	t_vector	map;
	t_vector	start;

	map.x = 0;
	map.y = 0;
	start.x = (int)(g_map->player->x) - NB_TILE;
	start.y = (int)(g_map->player->y) - NB_TILE;
	while (map.y <= NB_TILE * 2)
	{
		while (map.x <= NB_TILE * 2)
		{
			put_image_to_image(g_map, start, map, 0);
			map.x++;
			start.x++;
		}
		start.x = (int)(g_map->player->x) - NB_TILE;
		map.x = 0;
		start.y++;
		map.y++;
	}
	map.x = NB_TILE;
	map.y = NB_TILE;
	start.x = -1;
	start.y = -1;
	put_image_to_image(g_map, start, map, 1);
}

void	put_image_to_image(t_map *g_map, t_vector pos,
	t_vector map, int player_pos)
{
	int			y_img;
	int			x_img;
	uint32_t	*pixel;
	uint32_t	color;
	mlx_image_t	*img;

	y_img = -1;
	x_img = -1;
	if (player_pos == 0)
		img = chose_image_to_draw(g_map, pos.x, pos.y);
	else
		img = g_map->image->map_player;
	while (++y_img < TSMAP)
	{
		while (++x_img < TSMAP)
		{
			pixel = (uint32_t *)(img->pixels + (y_img + x_img * TSMAP)
					* sizeof(uint32_t));
			color = *pixel;
			color = get_rgba_tex(color);
			mlx_put_pixel(g_map->player->ray, map.x * TSMAP + x_img,
				map.y * TSMAP + y_img, color);
		}
		x_img = -1;
	}
}

t_image	*setup_image(t_map *g_map)
{
	t_image	*images;

	images = malloc(sizeof(t_image));
	if (!images)
		return (NULL);
	images->map_door = create_img_full(TSMAP, g_map->mlx, 0x660666FF);
	images->map_player = create_img_full(TSMAP, g_map->mlx, 0xFF6600FF);
	images->map_wall = create_img_full(TSMAP, g_map->mlx, 0x808080FF);
	images->map_floor = create_img_full(TSMAP, g_map->mlx, 0xC8AD7FFF);
	images->map_void = create_img_cf(TSMAP, TSMAP, g_map->mlx, 0x66000000);
	return (images);
}

mlx_image_t	*chose_image_to_draw(t_map *g_map, int x, int y)
{
	if (y >= ft_array_len_map(g_map->map) || y < 0 || x < 0
		|| x >= (int)ft_strlen(g_map->map[y]))
		return (g_map->image->map_void);
	else if (g_map->map[y][x] == '0' || is_spawn(g_map->map[y][x]))
		return (g_map->image->map_floor);
	else if (g_map->map[y][x] == '1')
		return (g_map->image->map_wall);
	else if (g_map->map[y][x] == 'D')
		return (g_map->image->map_door);
	else
		return (g_map->image->map_void);
}

u_int32_t	get_rgba_tex(u_int32_t color)
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	a;

	a = color >> 24;
	r = color >> 16;
	g = color >> 8;
	b = color;
	return (r << 8 | g << 16 | b << 24 | a << 0);
}
