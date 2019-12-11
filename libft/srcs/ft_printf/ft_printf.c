/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:45:10 by gdrion            #+#    #+#             */
/*   Updated: 2019/10/29 12:42:59 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*join_and_free(char *buf, char *conv)
{
	char *new;

	if (!buf || !conv)
		return (NULL);
	if (!(new = ft_strjoin(buf, conv)))
		return (NULL);
	ft_strdel(&buf);
	ft_strdel(&conv);
	return (new);
}

static int	print_free(t_flags *f, va_list ap, char *buf)
{
	int count;

	count = (int)ft_strlen_info(buf, f->info1);
	ft_putstrn(buf, count);
	va_end(ap);
	ft_strdel(&buf);
	free(f);
	return (count);
}

static void	stock_info(t_flags *f)
{
	f->info1 += f->info2 - 1;
	init_flags(f);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*buf;
	char	*conv;
	t_flags	*flags;

	if (!format || !(flags = ft_create_struct())
		|| !(buf = ft_strnew(0)))
		return (-1);
	(i = -1) ? va_start(ap, format) : 1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i += fill_incr(format + i, flags);
			if (!(conv = choose_conv(ap, flags)) ||
			!(buf = join_regarding_bz(buf, flags->info1, conv, flags->info2)))
				return (-1);
			stock_info(flags);
		}
		else if (format[i] != '\0' && format[i] != '%')
			if (!(buf = ft_buf_char(buf, format[i], 1, flags->info1)))
				return (-1);
	}
	return (print_free(flags, ap, buf));
}
