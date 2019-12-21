/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:09:05 by gdrion            #+#    #+#             */
/*   Updated: 2019/02/09 14:53:40 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_width_o(t_flags *f)
{
	char	*wid;
	int		i;

	i = 0;
	if (!(wid = ft_strnew(f->width - f->precision)))
		return (NULL);
	while (f->width-- > f->precision)
		wid[i++] = f->zero;
	return (wid);
}

static char	*apply_prec_o(char *nbr, t_flags *f, int new, int len)
{
	char	*ret;
	int		i;

	i = 0;
	if (f->hash && f->precision <= 0)
		new++;
	if (!(ret = ft_strnew(new + 1)))
		return (NULL);
	if (f->hash)
	{
		f->precision--;
		ret[i++] = '0';
	}
	while (f->precision-- > len)
		ret[i++] = '0';
	while (len--)
		ret[i++] = *nbr++;
	f->precision = ft_strlen(ret);
	return (ret);
}

static char	*simple_conv_o(char *nbr, t_flags *f)
{
	int		len;
	int		new;
	char	*prec;
	char	*wid;
	char	*ret;

	len = (int)ft_strlen(nbr);
	if (*nbr == '0' && f->precision > -1)
		len = 0;
	else if (*nbr == '0')
		f->hash = 0;
	new = (f->precision >= len) ? f->precision : len;
	if (f->precision > -1 || f->minus)
		f->zero = ' ';
	if (!(prec = apply_prec_o(nbr, f, new, len)))
		return (NULL);
	if (f->width <= f->precision)
		return (prec);
	if (!(wid = apply_width_o(f)))
		return (NULL);
	if (f->minus)
		ret = join_and_free(prec, wid);
	else
		ret = join_and_free(wid, prec);
	return (ret);
}

char		*ft_conv_o(va_list ap, t_flags *f)
{
	char		*ret;
	char		*nb;
	uintmax_t	d;

	if (f->j)
		d = va_arg(ap, uintmax_t);
	else if (f->z)
		d = va_arg(ap, size_t);
	else if (f->ll)
		d = va_arg(ap, unsigned long long);
	else if (f->l || f->conv == 'O')
		d = va_arg(ap, unsigned long);
	else if (f->h)
		d = (unsigned short)va_arg(ap, uintmax_t);
	else if (f->hh)
		d = (unsigned char)va_arg(ap, uintmax_t);
	else
		d = (unsigned int)va_arg(ap, uintmax_t);
	if (!(nb = ft_uitoa_base(d, 8)))
		return (NULL);
	ret = simple_conv_o(nb, f);
	ft_strdel(&nb);
	return (ret);
}
