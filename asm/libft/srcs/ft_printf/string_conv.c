/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:02:12 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/20 22:49:52 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_simple_conv_s(char *arg, t_flags *flags, int len)
{
	char	*new;
	int		i;

	i = 0;
	if (flags->width <= len)
		return (ft_strdup(arg));
	if (!(new = ft_strnew(flags->width)))
		return (NULL);
	if (flags->minus == 0)
	{
		while (flags->width-- > len)
			new[i++] = flags->zero;
		while (flags->width-- >= 0)
			new[i++] = *arg++;
	}
	else
	{
		while (len-- > 0 && flags->width-- > 0)
			new[i++] = *arg++;
		while (flags->width--)
			new[i++] = ' ';
	}
	return (new);
}

static char	*ft_harder_conv_s(char *arg, t_flags *f, int len)
{
	char	*new;
	int		i;
	int		newlen;
	int		save;

	save = (f->precision > len) ? len : f->precision;
	newlen = (f->width >= f->precision) ? f->width : f->precision;
	if (!(new = ft_strnew(newlen)))
		return (NULL);
	i = 0;
	if (f->minus == 1)
	{
		while (f->precision-- && *arg)
			new[i++] = *arg++;
		while (f->width-- > save)
			new[i++] = ' ';
	}
	else
	{
		while (f->width-- > save)
			new[i++] = f->zero;
		while (save--)
			new[i++] = *arg++;
	}
	return (new);
}

char		*ft_modify_arg_s(char *arg, t_flags *f)
{
	int		len;

	len = (int)ft_strlen(arg);
	if (f->precision < 0)
		return (ft_simple_conv_s(arg, f, len));
	else if (f->width <= 0 || (f->width < f->precision && f->precision < len))
		return (ft_strndup(arg, f->precision));
	else
		return (ft_harder_conv_s(arg, f, len));
	return (NULL);
}

char		*ft_conv_s(va_list ap, t_flags *flags)
{
	char	*conved;
	char	*arg;

	if (flags->l == 1 || flags->conv == 'S')
		conved = handle_unicode_string(ap, flags);
	else
	{
		arg = va_arg(ap, char *);
		if (!arg)
			arg = "(null)";
		conved = ft_modify_arg_s(arg, flags);
	}
	init_flags(flags);
	return (conved);
}
