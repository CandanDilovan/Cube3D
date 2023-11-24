/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:56:57 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/24 13:24:30 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_fill_intmap(t_map *g_map, uint32_t y, uint32_t x)
{
	if (g_map->map[y][x] == '1')
		g_map->int_map[y][x] = 1;
	else if (g_map->map[y][x] == '0' || g_map->map[y][x] == 'D')
		g_map->int_map[y][x] = 0;
	else if (g_map->map[y][x] == 'N'
		|| g_map->map[y][x] == 'W' || g_map->map[y][x] == 'E'
		|| g_map->map[y][x] == 'S')
		g_map->int_map[y][x] = 2;
	else
		g_map->int_map[y][x] = -1;
}

int	ft_int_map(t_map *g_map)
{
	uint32_t	x;
	uint32_t	y;

	g_map->int_map = malloc(sizeof(int *) * (g_map->height + 1));
	if (!g_map->int_map)
		return (-1);
	y = -1;
	while (g_map->height > ++y)
	{
		g_map->int_map[y] = malloc(sizeof(int) * (ft_strlen(g_map->map[y])));
		if (!g_map->int_map[y])
			return (-1);
		x = -1;
		while (ft_strlen(g_map->map[y]) > ++x)
			ft_fill_intmap(g_map, y, x);
	}
	if (ft_machin(g_map) == -1)
		return (-1);
	return (0);
}

static int	ft_strlen_cube(char *line, int a)
{
	int	b;

	b = 0;
	while (line[a + b] && (line[a + b] == ' ' || line[a + b] == '\t'
			|| line[a + b] == '.' || line[a + b] == '/'))
		a++;
	while (line[a + b] && line[a + b] >= 33 && line[a + b] <= 126)
		b++;
	return (b);
}

static char	*ft_texture_path(char *line, int a)
{
	int		b;
	char	*str;

	b = ft_strlen_cube(line, a);
	str = malloc(sizeof(char) * (b + 1));
	if (!str)
		return (NULL);
	b = 0;
	while (line[a + b] && (line[a + b] == ' ' || line[a + b] == '\t'
			|| line[a + b] == '.' || line[a + b] == '/'))
		a++;
	while (line[a + b] && line[a + b] >= 33 && line[a + b] <= 126)
	{
		str[b] = line[a + b];
		b++;
	}
	str[b] = '\0';
	return (str);
}

void	ft_identify_texture(t_map *g_map, char *line, int *flag)
{
	int	a;

	a = 0;
	while (line[a] && (line[a] == ' ' || line[a] == '\t'))
		a++;
	if (line[a] >= 33 && line[a] <= 126)
		*flag += 1;
	if (line[a] == 'N' && line[a + 1] == 'O')
		g_map->no = ft_texture_path(line, (a + 2));
	else if (line[a] == 'W' && line[a + 1] == 'E')
		g_map->we = ft_texture_path(line, (a + 2));
	else if (line[a] == 'S' && line[a + 1] == 'O')
		g_map->so = ft_texture_path(line, (a + 2));
	else if (line[a] == 'E' && line[a + 1] == 'A')
		g_map->ea = ft_texture_path(line, (a + 2));
	else if (line[a] == 'F')
		g_map->f = ft_texture_path(line, (a + 1));
	else if (line[a] == 'C')
		g_map->c = ft_texture_path(line, (a + 1));
}
