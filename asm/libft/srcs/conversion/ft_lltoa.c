/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:25:10 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/09/07 18:18:47 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(long long int n)
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
	if (!(str = (char *)malloc(sizeof(char) * (12))))
		return (NULL);
	str = ft_strdup("-9223372036854775808");
	return (str);
}

char		*ft_lltoa_tumsoules(long long int n)
{
	int		i;
	char	*str;

	str = NULL;
	if (n == LLONG_MIN)
		return (ft_isminimum(str));
	i = count_numbers(n);
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
