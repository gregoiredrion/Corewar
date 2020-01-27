/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:40:50 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/22 13:51:02 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*bytes_dst;
	unsigned char	*bytes_src;

	bytes_dst = (unsigned char*)dst;
	bytes_src = (unsigned char*)src;
	if (dst > src)
	{
		while (len--)
			bytes_dst[len] = bytes_src[len];
	}
	else if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
