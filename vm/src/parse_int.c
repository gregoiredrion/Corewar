/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 01:30:14 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/12 20:35:10 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static size_t		number_length(char *input)
{
	size_t size;

	size = 0;
	while (ft_isdigit(input[size]))
		size++;
	return (size);
}

static int			check_sign(char **s)
{
	int		sign;

	sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

static char			*ft_skip_zeros(char *s)
{
	if (*s != '0')
		return (s);
	while (*s == '0')
		s++;
	if (!ft_isdigit(*s))
		s--;
	return (s);
}

int					parse_int(char *s, int *value)
{
	size_t			length;
	unsigned long	tmp;
	int				sign;

	if (!s)
		return (FAILURE);
	length = 0;
	tmp = 0;
	sign = check_sign(&s);
	s = ft_skip_zeros(s);
	length = number_length(s);
	if (length > 10 || length == 0)
		return (FAILURE);
	while (ft_isdigit(*s))
	{
		tmp = (tmp * 10) + (*s - 48);
		s++;
	}
	if (*s)
		return (FAILURE);
	if ((tmp / (unsigned long)(0x7FFFFFFFul + ((sign == 1) ? 1 : 2))) > 0)
		return (FAILURE);
	if (value)
		*value = (int)tmp * sign;
	return (SUCCESS);
}
