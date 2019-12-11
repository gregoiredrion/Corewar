/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:07:45 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/10/17 17:39:20 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(intmax_t n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (9 < n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_isminimum(char *str)
{
	str = ft_strdup("-9223372036854775808");
	return (str);
}

char		*ft_itoa(intmax_t n)
{
	int		i;
	char	*str;

	str = NULL;
	i = count_numbers(n);
	if (n == LLONG_MIN)
		return (ft_isminimum(str));
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	if (n <= 9 && n >= 0)
		str[i] = n + 48;
	return (str);
}
