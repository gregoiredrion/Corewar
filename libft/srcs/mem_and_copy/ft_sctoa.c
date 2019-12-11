/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:26:33 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/09/25 12:58:09 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(signed char n)
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
	if (!(str = (char *)malloc(sizeof(char) * (5))))
		return (NULL);
	str = ft_strdup("-128");
	return (str);
}

char		*ft_sctoa(signed char n)
{
	int		i;
	char	*str;

	str = NULL;
	if (n == -128)
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
