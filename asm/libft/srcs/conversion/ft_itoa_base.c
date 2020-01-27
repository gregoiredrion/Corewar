/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:47:13 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/12/14 14:53:15 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_numbers(intmax_t nb, intmax_t base, int count)
{
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	if (nb == 0)
		count++;
	while ((nb = nb / base))
		count++;
	return (count);
}

char	*ft_itoa_base(intmax_t nb, intmax_t base)
{
	char		*converted;
	int			i;

	i = ft_count_numbers(nb, base, 1);
	if (nb < 0)
		nb = i++;
	if (!(converted = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (nb < 0)
	{
		converted[0] = '-';
		nb = nb * -1;
	}
	converted[i--] = '\0';
	while (i >= 0)
	{
		if (nb % base >= 0 && nb % base <= 9)
			converted[i--] = nb % base + 48;
		else
			converted[i--] = 'a' - 10 + (nb % base);
		nb = (nb - (nb % base)) / base;
	}
	return (converted);
}
