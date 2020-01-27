/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putscnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:25:16 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/09/25 14:39:55 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putscnbr(signed char n)
{
	if (n == -128)
	{
		write(1, "-1", 2);
		n = 28;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (9 < n)
	{
		ft_putscnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
}