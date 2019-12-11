/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:39:47 by gdrion            #+#    #+#             */
/*   Updated: 2018/12/17 19:24:11 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_u(va_list ap, t_flags *flags)
{
	uintmax_t	d;
	char		*ret;
	char		*nb;

	if (flags->j)
		d = va_arg(ap, uintmax_t);
	else if (flags->z)
		d = va_arg(ap, size_t);
	else if (flags->ll || (flags->conv == 'U' && flags->l))
		d = va_arg(ap, unsigned long long);
	else if (flags->l || flags->conv == 'U')
		d = va_arg(ap, unsigned long);
	else if (flags->h)
		d = (unsigned short)va_arg(ap, uintmax_t);
	else if (flags->hh)
		d = (unsigned char)va_arg(ap, uintmax_t);
	else
		d = va_arg(ap, unsigned int);
	if (!(nb = ft_ultoa(d)))
		return (NULL);
	ret = ft_simple_conv_d(nb, flags);
	ft_strdel(&nb);
	return (ret);
}
