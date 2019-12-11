/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:39:10 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/11/29 15:29:54 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double nb, int power)
{
	double	save;

	save = nb;
	while (1 < power)
	{
		nb = nb * save;
		power--;
	}
	while (0 > power)
	{
		nb = nb / 10;
		power++;
	}
	return (nb);
}
