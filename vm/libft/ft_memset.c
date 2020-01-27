/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:51:21 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/28 11:22:16 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;
	int				i;

	bytes = (unsigned char*)b;
	i = 0;
	while (i < (int)len)
	{
		bytes[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
