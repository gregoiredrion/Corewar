/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:36:34 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/10/18 12:20:13 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(uintmax_t n)
{
	int		i;

	i = 1;
	while (9 < n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_uitoa(uintmax_t n)
{
	int		i;
	char	*str;

	i = count_numbers(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	while (n > 9)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	if (n < 10)
		str[i] = n + 48;
	return (str);
}
