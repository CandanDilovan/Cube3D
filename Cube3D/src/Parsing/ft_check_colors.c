/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/11/08 14:56:55 by dilovancand      ###   ########.fr       */
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

	a = 0;
	while (str[a])
	{
		b = 0;
		while (str[a + b] >= '0' && str[a + b] <= '9' && str[a] != ',')
			b++;
		if (b > 0 && b < 4)
		{
			rgb = malloc(sizeof(char) * (b + 1));
			if (!rgb)
				return (NULL);
		}
		else
			return (NULL);
		if (str[a + b] == ',' || str[a + b] == '\n')
			a++;
		a = a + b;
	}
	return (rgb);
}

static int	*ft_int_rgb(char **rgb)
{
	int	*intrgb;

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
	if (!rgb)
		return (NULL);
	while (str[a])
	{
		b = -1;
		rgb[c] = ft_malloc_rgb(str, rgb[c], a);
		if (!rgb[c])
			return (free_all_cub(rgb, c), NULL);
		while (str[a + ++b] >= '0' && str[a + b] <= '9' && str[a] != ',')
			rgb[c][b] = str[a + b];
		if (str[a + b] == ',' || str[a + b] == '\n')
			a++;
		c++;
		a = a + b;
	}
	return (ft_int_rgb(rgb));
}
