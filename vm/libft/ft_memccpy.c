/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:24:47 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/22 18:14:03 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes_src;
	unsigned char	*bytes_dst;

	bytes_src = (unsigned char*)src;
	bytes_dst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		if (*bytes_src == (unsigned char)c)
		{
			*bytes_dst = *bytes_src;
			return ((void*)bytes_dst + 1);
		}
		*bytes_dst++ = *bytes_src++;
		i++;
	}
	return (NULL);
}
