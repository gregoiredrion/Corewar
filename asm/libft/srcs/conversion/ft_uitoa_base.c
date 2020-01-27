/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:01:02 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/11/24 14:44:24 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(uintmax_t nb, intmax_t base)
{
	char		*converted;
	uintmax_t	save;
	int			i;

	i = 0;
	save = nb;
	if (save == 0)
		i++;
	while (save > 0)
	{
		save = (save - (save % base)) / base;
		i++;
	}
	if (!(converted = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	converted[i--] = '\0';
	while (i >= 0)
	{
		if (nb % base <= 9)
			converted[i--] = nb % base + 48;
		else
			converted[i--] = 'a' - 10 + (nb % base);
		nb = (nb - (nb % base)) / base;
	}
	return (converted);
}
