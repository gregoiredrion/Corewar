/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:03:29 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:57:20 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_counters(t_formspec *fs)
{
	fs->n0 = 0;
	fs->nz0 = 0;
	fs->n1 = 0;
	fs->nz1 = 0;
	fs->n2 = 0;
	fs->nz2 = 0;
}

int			dispatch(va_list ap, t_formspec *fs, char specif, char *ac)
{
	init_counters(fs);
	if (specif == 'C' || (specif == 'c' && fs->qual == 'l'))
		handle_wchar(ap, fs, ac);
	else if (specif == 'S' || (specif == 's' && fs->qual == 'l'))
		handle_wstring(ap, fs);
	else if (specif == 'c')
		ac[fs->n0++] = va_arg(ap, int);
	else if (specif == 'd' || specif == 'i' || specif == 'D')
		handle_sint(ap, fs, specif, ac);
	else if (specif == 'x' || specif == 'X' || specif == 'o' || specif == 'u' ||
			specif == 'U' || specif == 'O')
		handle_uint(ap, fs, specif, ac);
	else if (specif == '%')
		ac[fs->n0++] = '%';
	else if (specif == 's')
		handle_string(ap, fs);
	else if (specif == 'p')
		handle_ptr(ap, fs, ac);
	else if (specif == 'f')
		handle_ld(ap, fs, ac);
	else
		return (0);
	return (1);
}
