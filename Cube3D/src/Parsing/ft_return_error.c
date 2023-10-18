/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:30:15 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/14 14:14:39 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_return_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (-1);
}
