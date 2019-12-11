/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:32:23 by gdrion            #+#    #+#             */
/*   Updated: 2018/12/18 17:13:58 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_simple_conv_d(char *nb, t_flags *f)
{
	int		w_len;
	char	*prec;
	char	*wid;

	if (f->precision != -1 || f->minus)
		f->zero = ' ';
	if (!(prec = aapply_prec_d(f, nb)))
		return (NULL);
	w_len = f->width - f->precision;
	if (f->zero == '0' && w_len > 0)
		if ((f->conv == 'p' || ((f->conv == 'x' || f->conv == 'X') && f->hash))
		&& (w_len == 1))
			w_len++;
	if (f->width <= f->precision)
		return (prec);
	if (!(wid = aaply_width_d(f, w_len, nb)))
		return (NULL);
	if (f->minus)
		prec = join_and_free(prec, wid);
	else
		prec = join_and_free(wid, prec);
	return (prec);
}

char		*ft_conv_d(va_list ap, t_flags *flags)
{
	intmax_t	arg;
	char		*nb;
	char		*conved;

	if (flags->j)
		arg = va_arg(ap, intmax_t);
	else if (flags->z)
		arg = va_arg(ap, ssize_t);
	else if (flags->ll || (flags->conv == 'D' && flags->l))
		arg = va_arg(ap, long long);
	else if (flags->l || flags->conv == 'D')
		arg = va_arg(ap, long);
	else if (flags->h)
		arg = (short)va_arg(ap, intmax_t);
	else if (flags->hh)
		arg = (char)va_arg(ap, intmax_t);
	else
		arg = va_arg(ap, int);
	if (!(nb = ft_itoa_new(arg)))
		return (NULL);
	conved = ft_simple_conv_d(nb, flags);
	ft_strdel(&nb);
	return (conved);
}
