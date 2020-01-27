/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:49:27 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/25 13:29:14 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*bytes;

	bytes = (unsigned char*)s;
	while (n != 0)
	{
		if (*bytes == (unsigned char)c)
			return ((void*)bytes);
		bytes++;
		n--;
	}
	return (NULL);
}
