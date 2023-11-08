/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:22:25 by aabel             #+#    #+#             */
/*   Updated: 2023/11/08 13:10:02 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_hitbox(t_map *g_map, double player_x, double player_y)
{
	if (g_map->map[(int)player_y][(int)player_x] == '1')
		return (1);
	return (0);
}
