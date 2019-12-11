/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:06:17 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/09/04 16:45:09 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi(const char *nptr)
{
	int			i;
	intmax_t	nb;
	int			sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\n'
	|| nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * (intmax_t)sign);
}
