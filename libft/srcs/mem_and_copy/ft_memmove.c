/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:55:38 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/04 09:55:05 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	i = 0;
	dst2 = (char *)dst;
	src2 = (const char *)src;
	if (dst >= src)
	{
		while (len--)
			dst2[len] = src2[len];
	}
	else if (dst < src)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
