/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:51:07 by gdrion            #+#    #+#             */
/*   Updated: 2019/04/03 16:06:07 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_modify_arg_ls(char *str, t_flags *flags)
{
	int		len;
	char	*conv;
	int		fill;
	int		i;

	i = 0;
	len = ft_strlen(str);
	fill = flags->width - len;
	if (flags->minus == 1)
		flags->zero = ' ';
	if (fill <= 0)
		return (str);
	len = (flags->width > len) ? flags->width : len;
	if (!(conv = ft_strnew(len)))
		return (NULL);
	while (fill--)
		conv[i++] = flags->zero;
	if (flags->minus == 1)
		return (join_and_free(str, conv));
	else
		return (join_and_free(conv, str));
}

static int	get_new_prec(wchar_t *a)
{
	int count;

	count = 0;
	while (*a)
		count += get_byte_len(*a++);
	return (count);
}

char		*handle_unicode_string(va_list ap, t_flags *flags)
{
	wchar_t	*arg;
	char	*buf;
	char	*uni;

	if (!(buf = ft_strnew(0)))
		return (NULL);
	arg = va_arg(ap, wchar_t *);
	if (!arg)
	{
		uni = "(null)";
		return (ft_modify_arg_s(uni, flags));
	}
	if (flags->precision == -1)
		flags->precision = get_new_prec(arg);
	while (*arg && flags->precision > 0)
	{
		flags->precision -= get_byte_len(*arg);
		if (flags->precision >= 0)
			if (!(buf = join_and_free(buf, unicode(*arg++))))
				return (NULL);
	}
	buf = ft_modify_arg_ls(buf, flags);
	return (buf);
}
