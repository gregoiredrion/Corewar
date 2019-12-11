/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:55:47 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/06/24 16:50:56 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	t;

	i = 0;
	n = ft_strlen(dst);
	t = n + ft_strlen(src);
	if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	size = size - (ft_strlen(dst) + 1);
	while (src[i] && size--)
	{
		dst[n] = src[i];
		n++;
		i++;
	}
	dst[n] = '\0';
	return (t);
}
