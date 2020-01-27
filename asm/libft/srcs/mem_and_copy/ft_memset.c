/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:36:40 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/06/20 14:20:23 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	d;
	char			*str;

	str = (char *)b;
	d = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = d;
		i++;
	}
	return (str);
}
