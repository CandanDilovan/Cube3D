/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:53:34 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/24 18:40:15 by dcandan          ###   ########.fr       */
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
			|| line[a] == 'E' || line[a] == 'W' || line[a] == 'D')
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
