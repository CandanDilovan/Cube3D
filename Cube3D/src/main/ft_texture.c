/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:42:11 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/15 12:30:40 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_time(void)
{
	double	time;

	time = mlx_get_time();
	time = floor(time);
	return (time);
}

static void	ft_change(t_map *g_map)
{
	if (g_map->texture->time < ft_time())
	{
		g_map->texture->time = ft_time() + 0.5;
		if (g_map->texture->flag == 1)
			g_map->texture->flag = 0;
		else if (g_map->texture->flag == 0)
			g_map->texture->flag = 1;
	}
}

static uint32_t	ft_colors(uint32_t colors)
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	a = colors >> 24;
	r = colors >> 16;
	g = colors >> 8;
	b = colors;
	return (r << 8 | g << 16 | b << 24 | a << 0);
}

static mlx_texture_t	*ft_tex_selector(t_map *g_map)
{
	if (g_map->texture->side == 'W')
		return (g_map->texture->west[g_map->texture->flag]);
	else if (g_map->texture->side == 'E')
		return (g_map->texture->east[g_map->texture->flag]);
	else if (g_map->texture->side == 'N')
		return (g_map->texture->north[g_map->texture->flag]);
	else if (g_map->texture->side == 'S')
		return (g_map->texture->south[g_map->texture->flag]);
	else
		return (NULL);
}

uint32_t	ft_get_pixel(t_map *g_map)
{
	mlx_texture_t	*texture;
	uint32_t		color;
	uint32_t		*pixel;

	texture = ft_tex_selector(g_map);
	g_map->texture->tex_y = (int)g_map->texture->tex_pos & (TEX_SIZE - 1);
	g_map->texture->tex_pos += g_map->texture->tex_step;
	pixel = NULL;
	pixel = (uint32_t *)(texture->pixels + (TEX_SIZE * g_map->texture->tex_y
				+ g_map->texture->tex_x) * sizeof(uint32_t));
	color = *pixel;
	return (ft_colors(color));

}

void	ft_draw_walls(t_map *g_map, int dstart, int line_h)
{
	double		walls_x;

	ft_tex_selector(g_map);
	if (g_map->texture->side == 'W' || g_map->texture->side == 'E')
		walls_x = g_map->player->y + g_map->walls->line * g_map->walls->angley;
	else
		walls_x = g_map->player->x + g_map->walls->line * g_map->walls->anglex;
	walls_x -= floor(walls_x);
	g_map->texture->tex_x = (int)(walls_x * TEX_SIZE);
	g_map->texture->tex_step = 1.0 * TEX_SIZE / line_h;
	g_map->texture->tex_pos = (dstart - WH / 2 + line_h / 2)
		* g_map->texture->tex_step;
	ft_change(g_map);
}
