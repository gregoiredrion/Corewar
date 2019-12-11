/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_incr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:05:20 by gdrion            #+#    #+#             */
/*   Updated: 2019/04/03 16:30:34 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	not_flags(char c)
{
	return (c != 'j' && c != 'z' && c != 'h' && c != 'l' && c != 'L');
}

static int	find_right_conv(char c)
{
	char	*conv;

	conv = "sSpdDioOuUxXcCfF%";
	if (ft_strchr(conv, c))
		return (1);
	if (ft_isalpha(c) && not_flags(c))
		return (1);
	return (0);
}

int			fill_incr(const char *s, t_flags *f)
{
	int		convlen;
	char	*save;

	save = (char *)s;
	convlen = 1;
	s++;
	while (*s && !find_right_conv(*s))
	{
		s++;
		convlen++;
	}
	f->conv = *s;
	fill_flags(++save, f);
	if (f->conv == '\0')
		return (convlen - 1);
	return (convlen);
}
