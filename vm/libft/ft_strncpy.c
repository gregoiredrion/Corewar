/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:26:22 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/13 14:36:58 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*tag;

	tag = dst;
	i = 0;
	while (i < len && *src)
	{
		*tag++ = *src++;
		i++;
	}
	while (i < len)
	{
		*tag++ = '\0';
		i++;
	}
	return (dst);
}
