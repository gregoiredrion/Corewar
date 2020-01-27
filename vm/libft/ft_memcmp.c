/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:22:40 by lode-spi          #+#    #+#             */
/*   Updated: 2019/11/28 19:46:07 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*bytes_s1;
	unsigned char	*bytes_s2;

	bytes_s1 = (unsigned char*)s1;
	bytes_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (bytes_s1[i] != bytes_s2[i])
			return (bytes_s1[i] - bytes_s2[i]);
		i++;
	}
	return (0);
}
