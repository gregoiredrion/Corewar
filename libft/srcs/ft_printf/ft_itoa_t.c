/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:39:15 by gdrion            #+#    #+#             */
/*   Updated: 2019/02/09 15:01:34 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit_ll(intmax_t n)
{
	int		c;

	c = 1;
	while (n /= 10)
		c++;
	return (c);
}

char		*ft_lltoa(intmax_t n)
{
	int			digits;
	intmax_t	temp;
	char		*t;

	digits = count_digit_ll(n);
	temp = n;
	if (n < 0)
	{
		temp = -n;
		digits++;
	}
	if (!(t = ft_strnew(digits)))
		return (NULL);
	t[digits] = '\0';
	if (n < 0)
		t[0] = '-';
	t[--digits] = temp % 10 + 48;
	while (temp /= 10)
		t[--digits] = temp % 10 + 48;
	return (t);
}

static int	count_digit_ul(uintmax_t n)
{
	int	c;

	c = 1;
	while (n /= 10)
		c++;
	return (c);
}

char		*ft_ultoa(uintmax_t n)
{
	int			digits;
	uintmax_t	temp;
	char		*t;

	digits = count_digit_ul(n);
	temp = n;
	if (!(t = ft_strnew(digits)))
		return (NULL);
	t[digits] = '\0';
	t[--digits] = temp % 10 + 48;
	while (temp /= 10)
		t[--digits] = temp % 10 + 48;
	return (t);
}
