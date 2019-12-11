/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:27:00 by gdrion            #+#    #+#             */
/*   Updated: 2019/09/06 22:25:33 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*choose_conv(va_list ap, t_flags *flags)
{
	char	*ret;
	int		i;

	i = -1;
	if (flags->conv == 's' || flags->conv == 'S')
		ret = ft_conv_s(ap, flags);
	else if (flags->conv == 'f' || flags->conv == 'F')
		ret = ft_conv_f(ap, flags);
	else if (flags->conv == 'c' || flags->conv == 'C')
		ret = ft_conv_c(ap, flags);
	else if (flags->conv == 'd' || flags->conv == 'i' || flags->conv == 'D')
		ret = ft_conv_d(ap, flags);
	else if (flags->conv == 'u' || flags->conv == 'U')
		ret = ft_conv_u(ap, flags);
	else if (flags->conv == 'x' || flags->conv == 'p' || flags->conv == 'X')
		ret = ft_conv_x(ap, flags);
	else if (flags->conv == 'o' || flags->conv == 'O')
		ret = ft_conv_o(ap, flags);
	else
		ret = ft_conv_c(ap, flags);
	if (flags->conv == 'X' && ret)
		while (ret[++i])
			ret[i] = ft_c_to_upper(ret[i]);
	return (ret);
}
