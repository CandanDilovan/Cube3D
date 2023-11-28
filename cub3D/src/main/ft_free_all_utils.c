/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:37:29 by dcandan           #+#    #+#             */
/*   Updated: 2023/11/27 14:40:52 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_free_maps(t_map *g_map)
{
	int	a;

	a = -1;
	while (++a < (int)g_map->height)
		free(g_map->map[a]);
	free(g_map->map);
	ft_free_maperror(g_map);
}
