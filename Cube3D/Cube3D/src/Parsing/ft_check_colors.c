/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/24 17:53:03 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	**free_all_cub(char **tab, int a)
{
	while (0 <= a)
	{
		free(tab[a]);
		a--;
	}
	free(tab);
	return (NULL);
}

static char	*ft_malloc_rgb(char *str, char *rgb, int a)
{
	int		b;

	while (str[a])
	{
		b = 0;
		while (str[a + b] && str[a + b] >= '0'
			&& str[a + b] <= '9' && str[a + b] != ',')
			b++;
		if (b > 0 && b < 4)
		{
			rgb = malloc(sizeof(char) * (b + 1));
			if (!rgb)
				return (NULL);
			return (rgb);
		}
		else
			return (NULL);
	}
	return (rgb);
}

static int	*ft_int_rgb(char **rgb)
{
	int	*intrgb;

	if (!rgb[0] || rgb[0][0] == '\0')
		return (NULL);
	if (!rgb[1] || rgb[1][0] == '\0')
		return (free_all_cub(rgb, 1), NULL);
	if (!rgb[2] || rgb[2][0] == '\0')
		return (free_all_cub(rgb, 2), NULL);
	intrgb = malloc(sizeof(int) * 3);
	intrgb[0] = ft_atoi(rgb[0]);
	if (intrgb[0] > 255 || intrgb[0] < 0)
		return (NULL);
	intrgb[1] = ft_atoi(rgb[1]);
	if (intrgb[1] > 255 || intrgb[1] < 0)
		return (NULL);
	intrgb[2] = ft_atoi(rgb[2]);
	if (intrgb[2] > 255 || intrgb[2] < 0)
		return (NULL);
	free_all_cub(rgb, 3);
	return (intrgb);
}

int	*ft_rgb(char *str)
{
	int		a;
	int		b;
	int		c;
	char	**rgb;

	a = 0;
	c = 0;
	rgb = malloc(sizeof(char *) * 4);
	while (str[a])
	{
		b = -1;
		rgb[c] = ft_malloc_rgb(str, rgb[c], a);
		if (!rgb[c])
			return (free_all_cub(rgb, c), NULL);
		while (str[a + ++b] >= '0' && str[a + b] <= '9' && str[a + b] != ',')
			rgb[c][b] = str[a + b];
		if (str[a + b] == ',' || str[a + b] == '\n')
			a++;
		rgb[c][b] = '\0';
		c++;
		a = a + b;
	}
	rgb[c] = NULL;
	return (ft_int_rgb(rgb));
}
