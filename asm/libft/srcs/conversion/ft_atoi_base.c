/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:14:28 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/10/13 14:25:31 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c)
{
	if (c >= '0' && c <= '9')
		return (48);
	else if (c >= 'a' && c <= 'f')
		return (10 - 'a');
	else if (c >= 'A' && c <= 'F')
		return (10 - 'A');
	else
		return (0);
}

static int	ft_error(const char *str, int base)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (base > 16 || base < 2)
			return (0);
		if ((str[i] >= '0' && str[i] <= '9' && base > str[i] - 48)
		|| (str[i] >= 'a' && str[i] <= 'f' && base > str[i] - 'a' + 10)
		|| (str[i] >= 'A' && str[i] <= 'F' && base > str[i] - 'A' + 10))
			i++;
		else
			return (0);
	}
	return (1);
}

int			ft_atoi_base(const char *str, int base)
{
	int		i;
	int		nb;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] && str[i] == ' ' && str[i] == '\t' && str[i] == '\v'
	&& str[i] == '\n' && str[i] == '\r' && str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (ft_error(str, base) == 0)
		return (0);
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * base + str[i] - ft_check(str[i]);
		i++;
	}
	return (nb * sign);
}
