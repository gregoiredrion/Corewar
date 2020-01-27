/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:14:46 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/22 11:24:51 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*bytes_src;
	unsigned char	*bytes_dst;

	bytes_src = (unsigned char *)src;
	bytes_dst = (unsigned char *)dst;
	while (n > 0)
	{
		*bytes_dst++ = *bytes_src++;
		n--;
	}
	return (dst);
}
