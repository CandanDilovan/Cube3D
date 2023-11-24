/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:03:18 by babels            #+#    #+#             */
/*   Updated: 2023/11/17 13:25:57 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_image_t	*create_img_full(int size, mlx_t *mlx, uint64_t color)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	x = -1;
	y = -1;
	img = mlx_new_image(mlx, size, size);
	if (!img)
		return (NULL);
	while (++y < size)
	{
		while (++x < size)
		{
			if (x == 0 || x == size - 1 || y == 0 || y == size - 1)
				mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			else
				mlx_put_pixel(img, x, y, color);
		}
		x = -1;
	}
	return (img);
}

mlx_image_t	*create_img_cf(int width, int h, mlx_t *mlx, uint64_t color)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	x = -1;
	y = -1;
	img = mlx_new_image(mlx, width, h);
	if (!img)
		return (NULL);
	while (++y < h)
	{
		while (++x < width)
			mlx_put_pixel(img, x, y, color);
		x = -1;
	}
	return (img);
}

int	is_spawn(char type)
{
	if (type == 'S' || type == 'N' || type == 'W' || type == 'E')
		return (1);
	return (0);
}

int	ft_array_len_map(char	**array)
{
	int		i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
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
