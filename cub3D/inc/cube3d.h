/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:29:20 by aabel             #+#    #+#             */
/*   Updated: 2023/11/27 14:42:21 by dcandan          ###   ########.fr       */
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
# define DR 0.0174533
# define WH	720
# define WW	1280
# define TEX_SIZE 64

# define TILE_SIZE 64

# define NB_TILE 6
# define TSMAP 20

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	mlx_image_t		*map_floor;
	mlx_image_t		*map_player;
	mlx_image_t		*map_wall;
	mlx_image_t		*map_door;
	mlx_image_t		*map_void;
	mlx_image_t		**door_img;
}	t_image;

typedef struct s_doors
{
	int			x;
	int			y;
}				t_doors;

typedef struct a_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	double			time;
	int				side;
	int				flag;
	int				*ceilling;
	int				*floor;
	int				tex_y;
	int				tex_x;
	int				is_door;
	double			tex_pos;
	double			tex_step;
	mlx_texture_t	**door;
}				t_texture;

typedef struct a_player
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		pa;
	int			doors_nb;
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
	int			mouse;
	int			mouse_moved;
	t_texture	*texture;
	t_player	*player;
	t_walls		*walls;
	t_doors		*doors;
	t_image		*image;
}				t_map;

//map
int			map_count(t_map *g_map, char *map);
size_t		ft_strlen_g_map(const char *str);
int			ft_is_cub(char *map);
int			ft_no_void(t_map *g_map);
int			ft_is_map(char	*line, int *flag);
int			ft_int_map(t_map *g_map);
int			ft_machin(t_map *g_map);
int			*ft_rgb(char *str);

//texture
void		ft_identify_texture(t_map *g_map, char *line, int *flag);
int			ft_textures(t_map *g_map);
uint32_t	ft_get_colors(int *rgb);
uint32_t	ft_get_pixel(t_map *g_map);
void		ft_draw_walls(t_map *g_map, int dstart, int line_h);

//print_error
int			ft_return_error(char *str);

//rays
int			ft_check_walls_ud(t_map *g_map, double ra);
void		ft_lowest(t_map *g_map);
void		ft_paint_ray(t_map *g_map, t_walls *walls);
uint32_t	ft_colors(uint32_t colors);

//move_hitbox
void		ft_move(void *param);
void		go_front(t_map *g_map);
void		go_back(t_map *g_map);
void		go_left(t_map *g_map);
void		go_left(t_map *g_map);
void		go_right(t_map *g_map);
int			check_hitbox(t_map *g_map, double player_x, double player_y);
void		mouse_hook(t_map *g_map);
void		mouse_on_off(t_map *g_map);
void		rotate_left(t_map *g_map, double rotspeed);
void		rotate_right(t_map *g_map, double rotspeed);
void		setup_start_dir(t_map *g_map, char direction);
void		set_south(t_map *g_map);
void		set_north(t_map *g_map);
void		set_east(t_map *g_map);
void		set_west(t_map *g_map);

//init
void		init_player(t_map *g_map);
void		find_spawn(char **map, int *x, int *y);

//doors
void		init_door(t_map *g_map);
int			count_doors(t_map *g_map);
t_doors		create_door(int x, int y);
int			player_range_door(t_map *g_map, t_doors *door);
void		open_door(t_map *g_map, t_doors *door, int flag);
void		ft_load_images(t_map *g_map);
void		ft_check_doors(t_map *g_map);

//minimap
void		ft_minimap(t_map *g_map);
mlx_image_t	*chose_image_to_draw(t_map *g_map, int x, int y);
void		put_image_to_image(t_map *g_map, t_vector pos,
				t_vector map, int player_pos);
t_image		*setup_image(t_map *g_map);
u_int32_t	get_rgba_tex(u_int32_t color);
mlx_image_t	*create_img_full(int size, mlx_t *mlx, uint64_t color);
mlx_image_t	*create_img_cf(int width, int h, mlx_t *mlx, uint64_t color);
int			is_spawn(char type);
int			ft_array_len_map(char	**array);

//free
void		ft_endgame(t_map *g_map);
void		ft_free_maperror(t_map *g_map);
void		ft_free_intmap(t_map *g_map);
void		ft_free_text(t_map *g_map);
void		ft_free_maps(t_map *g_map);

#endif