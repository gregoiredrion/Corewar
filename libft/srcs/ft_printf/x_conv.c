/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:35:33 by gdrion            #+#    #+#             */
/*   Updated: 2019/03/23 20:58:56 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_x(va_list ap, t_flags *flags)
{
	char		*ret;
	uintmax_t	d;
	char		*nb;

	if (flags->conv == 'p')
		d = va_arg(ap, unsigned long);
	else if (flags->j)
		d = va_arg(ap, uintmax_t);
	else if (flags->z)
		d = va_arg(ap, size_t);
	else if (flags->ll)
		d = va_arg(ap, unsigned long long);
	else if (flags->l)
		d = va_arg(ap, unsigned long);
	else if (flags->h)
		d = (unsigned short)va_arg(ap, uintmax_t);
	else if (flags->hh)
		d = (unsigned char)va_arg(ap, uintmax_t);
	else
		d = (unsigned int)va_arg(ap, uintmax_t);
	if (!(nb = ft_uitoa_base(d, 16)))
		return (NULL);
	ret = ft_simple_conv_d(nb, flags);
	ft_strdel(&nb);
	return (ret);
}
