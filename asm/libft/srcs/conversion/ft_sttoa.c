/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sttoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:04:58 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/10/07 16:10:30 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(size_t n)
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

char		*ft_sttoa(size_t n)
{
	int		i;
	char	*str;

	str = NULL;
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
	if (n <= 9)
		str[i] = n + 48;
	return (str);
}
