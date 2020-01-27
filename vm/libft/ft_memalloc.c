/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:48:21 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/15 16:57:42 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;
	size_t			i;
	unsigned char	*bytes;

	if (!(ret = malloc(size)))
		return (NULL);
	bytes = (unsigned char*)ret;
	i = 0;
	while (i < size)
	{
		bytes[i] = '\0';
		i++;
	}
	return (ret);
}
