/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:46:10 by gdrion            #+#    #+#             */
/*   Updated: 2019/09/06 22:31:30 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_check_modif2(char *str, t_flags *flags, int i)
{
	if (str[i] == '.')
	{
		flags->precision = ft_atoi(++str + i);
		if (ft_isdigit(*(str + i)))
			return (i + ft_count_digit(flags->precision) + 1);
		else
			return (i + ft_count_digit(flags->precision));
	}
	else if (str[i] > '0' && str[i] <= '9')
	{
		flags->width = ft_atoi(str + i);
		return (i + ft_count_digit(flags->width));
	}
	else if (str[i] == '0')
	{
		flags->zero = '0';
		return (i + 1);
	}
	return (i + 1);
}

static int			ft_check_modif(char *str, t_flags *flags, int i)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
		return ((flags->hh = 1) ? i + 2 : i + 2);
	else if (str[i] == 'L')
		return ((flags->bigl = 1) ? i + 1 : i + 1);
	else if (str[i] == 'h')
		return ((flags->h = 1) ? i + 1 : i + 1);
	else if (str[i] == 'l' && str[i + 1] == 'l')
		return ((flags->ll = 1) ? i + 2 : i + 2);
	else if (str[i] == 'l')
		return ((flags->l = 1) ? i + 1 : i + 1);
	else if (str[i] == '+')
		return ((flags->plus = 1) ? i + 1 : i + 1);
	else if (str[i] == '-')
		return ((flags->minus = 1) ? i + 1 : i + 1);
	else if (str[i] == ' ')
		return ((flags->space = 1) ? i + 1 : i + 1);
	else if (str[i] == '#')
		return ((flags->hash = 1) ? i + 1 : i + 1);
	else if (str[i] == 'j')
		return ((flags->j = 1) ? i + 1 : i + 1);
	else if (str[i] == 'z')
		return ((flags->z = 1) ? i + 1 : i + 1);
	return (ft_check_modif2(str, flags, i));
}

void				fill_flags(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (str[i] != flags->conv && str[i])
		i = ft_check_modif(str, flags, i);
	return ;
}
