/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:03:09 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/01 20:25:05 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	d;

	d = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (n--)
	{
		if (*s2 == d)
			return (s2);
		s2++;
	}
	return (NULL);
}
