/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:08:27 by gdrion            #+#    #+#             */
/*   Updated: 2019/10/29 12:33:15 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = ' ';
	flags->hash = 0;
	flags->ll = 0;
	flags->l = 0;
	flags->bigl = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->j = 0;
	flags->z = 0;
	flags->space = 0;
	flags->conv = -1;
	flags->info2 = 1;
}

t_flags		*ft_create_struct(void)
{
	t_flags		*flags;

	if (!(flags = malloc(sizeof(t_flags))))
		return (NULL);
	flags->info1 = 1;
	init_flags(flags);
	return (flags);
}
