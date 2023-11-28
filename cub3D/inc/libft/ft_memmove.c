/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:29:03 by dcandan           #+#    #+#             */
/*   Updated: 2023/11/27 14:31:27 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	a = 0;
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	if (dst > src)
	{
		while (0 < len)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (a < len)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a++;
		}
	}
	return (dst);
}
