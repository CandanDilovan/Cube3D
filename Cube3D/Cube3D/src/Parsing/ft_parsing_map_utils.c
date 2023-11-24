/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:50 by dcandan           #+#    #+#             */
/*   Updated: 2023/11/24 18:49:07 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_fill_g_map(t_map *g_map, char *map)
{
	int			fd;
	char		*line;
	uint32_t	a;
	int			flag;

	g_map->map = malloc(sizeof(char *) * (g_map->height + 1));
	flag = 0;
	a = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line && a != g_map->height)
	{
		if (g_map->widht < ft_strlen_g_map(line) && ft_is_map(line, &flag) == 0)
			g_map->widht = ft_strlen_g_map(line);
		if (flag == 1 && ft_is_map(line, &flag) == 0)
			g_map->map[a++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	g_map->map[a] = NULL;
	close(fd);
	return (0);
}

static int	ft_read_cub(t_map *g_map, int fd)
{
	char	*line;
	int		flag;
	int		a;

	a = 0;
	line = get_next_line(fd);
	if (!line)
		return (ft_return_error("Error : .cub might be empty"));
	flag = 0;
	while (line)
	{
		if (ft_is_map(line, &flag) == 0)
			g_map->height++;
		else if (ft_is_map(line, &flag) == -1 && flag == 0)
			ft_identify_texture(g_map, line, &a);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (a != 6)
		return (ft_return_error
			("Error : There needs to be 2 colors and 4 textures"), -1);
	return (0);
}

int	map_count(t_map *g_map, char *map)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_return_error("Error : Fd failed"), -1);
	g_map->height = 0;
	g_map->widht = 0;
	if (ft_read_cub(g_map, fd) == -1)
		return ((void)close(fd), -1);
	//check map et free si il est faux;
	return ((void)close(fd), ft_fill_g_map(g_map, map), 0);
}
