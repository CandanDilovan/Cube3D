/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:39:54 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/07 14:35:35 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H

# define CUBE3D_H

# include "libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# define PI 3.141592653558209
# define DR 0.0174533 / 2

# define TILE_SIZE 64

typedef struct a_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}				t_texture;

typedef struct a_player
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		pa;
	mlx_image_t	*ray;
}				t_player;

typedef struct a_walls
{
	int			stepx;
	int			stepy;
	double		lx;
	double		ly;
	double		x;
	double		y;
	double		wx;
	double		wy;
	double		sdx;
	double		sdy;
	double		ddx;
	double		ddy;
	double		anglex;
	double		angley;
	double		line;
	uint32_t	mx;
	uint32_t	my;
}				t_walls;

typedef struct a_map
{
	mlx_t		*mlx;
	int			**int_map;
	char		**map;
	uint32_t	height;
	uint32_t	widht;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			error;
	t_texture	*texture;
	mlx_image_t	*img;
	t_player	*player;
	t_walls		**walls;
}				t_map;

//map
int		map_count(t_map *g_map, char *map);
size_t	ft_strlen_g_map(const char *str);
int		ft_is_cub(char *map);
int		ft_no_void(t_map *g_map);
int		ft_is_map(char	*line, int *flag);
int		ft_int_map(t_map *g_map);

//texture
int		ft_identify_texture(t_map *g_map, char *line);
int		ft_textures(t_map *g_map);

//print_error
int		ft_return_error(char *str);

//rays
int		ft_check_walls_ud(t_map *g_map, double ra, int r);
void	ft_lowest(t_map *g_map);
void	ft_paint_ray(t_map *g_map, t_walls **walls);

//move_hitbox

void	ft_move(void *param);
void	go_front(t_map *g_map);
void	go_back(t_map *g_map);
void	go_left(t_map *g_map);
void	go_left(t_map *g_map);
void	go_right(t_map *g_map);
int		check_hitbox(t_map *g_map, double player_x, double player_y);
#endif