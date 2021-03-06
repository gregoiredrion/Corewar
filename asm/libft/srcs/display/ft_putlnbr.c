/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:36:16 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/09/25 14:39:32 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr(long n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (9 < n)
	{
		ft_putlnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
}
