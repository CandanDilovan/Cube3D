/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:53:34 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/14 19:41:31 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_is_map(char	*line, int *flag)
{
	uint32_t	a;

	a = 0;
	while (line[a])
	{
		if (line[a] == ' ' || line[a] == '\t' || line[a] == '1'
			|| line[a] == '0' || line[a] == 'N' || line[a] == 'S'
			|| line[a] == 'E' || line[a] == 'W')
		{
			a++;
			if (line[a] == '\n' || line[a] == '\0')
			{
				if (*flag == 0)
					*flag = 1;
				return (0);
			}
		}
		else
			return (-1);
	}
	return (0);
}

size_t	ft_strlen_g_map(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] && str[a] != '\n')
	{
		a++;
	}
	return (a);
}

static int	ft_fill_g_map(t_map *g_map, char *map)
{
	int			fd;
	char		*line;
	uint32_t	a;
	int			flag;

	g_map->map = malloc(sizeof(char *) * (g_map->height));
	g_map->widht = 0;
	flag = 0;
	a = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line && a != g_map->height)
	{
		if (g_map->widht < ft_strlen_g_map(line) && ft_is_map(line, &flag) == 0)
			g_map->widht = ft_strlen_g_map(line);
		if (flag == 1 && ft_is_map(line, &flag) == 0)
		{
			g_map->map[a] = ft_strdup(line);
			a++;
		}
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

int	map_count(t_map *g_map, char *map)
{
	char	*line;
	int		fd;
	int		flag;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	flag = 0;
	line = get_next_line(fd);
	g_map->height = 0;
	while (line)
	{
		if (ft_is_map(line, &flag) == 0)
			g_map->height++;
		else if (ft_is_map(line, &flag) == -1 && flag == 0)
			ft_identify_texture(g_map, line);
		else if (flag == 1 && ft_is_map(line, &flag) == -1)
			return (ft_return_error("Unexpected char in map"), -1);
		free(line);
		line = get_next_line(fd);
	}
	return ((void)close(fd), ft_fill_g_map(g_map, map), 0);
}

int	ft_is_cub(char *map)
{
	int	a;

	a = 0;
	while (map[a] && map[a] != '.')
		a++;
	if (map[a++] == '.')
		if (map[a++] == 'c')
			if (map[a++] == 'u')
				if (map[a++] == 'b')
					if (map[a] == '\0')
						return (0);
	return (-1);
}
