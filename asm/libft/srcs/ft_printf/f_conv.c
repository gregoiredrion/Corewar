/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:44:17 by gdrion            #+#    #+#             */
/*   Updated: 2019/10/23 13:56:22 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_flags(char **nb, char *wid, t_flags *f)
{
	char	c;
	char	*ret;
	int		len;

	if (f->space || f->plus)
	{
		if (wid)
		{
			len = ft_strlen(wid);
			if (len > 1)
				wid[len - 1] = '\0';
			else
				wid[0] = '\0';
		}
		c = (f->plus >= f->space) ? '+' : ' ';
		ret = ft_buf_char(*nb, c, 2, 1);
		return (ret);
	}
	else
		return (*nb);
}

static char	*apply_flags_width(char *wid, char **nb, t_flags *f)
{
	if (*nb[0] == '-')
	{
		if (f->zero == '0' && !f->minus)
		{
			*nb[0] = '0';
			wid[0] = '-';
		}
	}
	else
	{
		if (f->space || f->plus)
		{
			if (f->zero == '0')
				wid[0] = (f->plus >= f->space) ? '+' : ' ';
			else if (!f->minus)
				wid[ft_strlen(wid) - 1] = (f->plus >= f->space) ? '+' : ' ';
			else
				*nb = apply_flags(nb, wid, f);
		}
	}
	if (f->minus)
		wid = join_and_free(*nb, wid);
	else
		wid = join_and_free(wid, *nb);
	return (wid);
}

static char	*ft_simple_conv(char **nb, t_flags *f)
{
	char	*wid;
	int		w_len;

	if (f->minus)
		f->zero = ' ';
	if (**nb == '-')
	{
		f->space = 0;
		f->plus = 0;
	}
	if ((w_len = f->width - ft_strlen(*nb)) <= 0)
		return (apply_flags(nb, NULL, f));
	if (!(wid = ft_strnew(w_len)))
		return (NULL);
	while (w_len--)
		wid[w_len] = f->zero;
	wid = apply_flags_width(wid, nb, f);
	return (wid);
}

char		*ft_conv_f(va_list ap, t_flags *flags)
{
	char		*ret;
	char		**nb;
	long double	f;

	if (flags->bigl)
		f = (long double)va_arg(ap, long double);
	else
		f = va_arg(ap, double);
	if (!(nb = (char **)malloc(sizeof(char *))))
		return (NULL);
	if (!(*nb = ft_dtoa2(f, flags)))
		return (NULL);
	ret = ft_simple_conv(nb, flags);
	free(nb);
	return (ret);
}
