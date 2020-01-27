/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:59:01 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/18 19:18:09 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tag;

	tag = NULL;
	while (*s)
	{
		if (*s == c)
			tag = s;
		s++;
	}
	if (c == 0)
		tag = s;
	return ((char*)tag);
}
