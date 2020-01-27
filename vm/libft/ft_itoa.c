/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:10:19 by lode-spi          #+#    #+#             */
/*   Updated: 2018/10/23 17:53:00 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_decimal_size(int n)
{
	int		size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char	*to_ret;
	int		size;
	long	tmp;

	tmp = (long)n;
	size = get_decimal_size(tmp);
	if (tmp < 0)
		size++;
	if (!(to_ret = (char*)malloc(sizeof(*to_ret) * (size + 1))))
		return (NULL);
	if (tmp < 0)
	{
		to_ret[0] = '-';
		tmp = -tmp;
	}
	to_ret[size] = '\0';
	to_ret[--size] = (tmp % 10) + 48;
	while (tmp /= 10)
		to_ret[--size] = (tmp % 10) + 48;
	return (to_ret);
}
