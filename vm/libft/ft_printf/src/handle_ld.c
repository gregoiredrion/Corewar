/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:09:30 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:58:14 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(long double input)
{
	return (((unsigned short*)&input)[4] & 0x8000);
}

void		handle_ld(va_list ap, t_formspec *fs, char *ac)
{
	fs->v.ld = (fs->qual == 'L') ? va_arg(ap, long double) : va_arg(ap, double);
	if (get_sign(fs->v.ld))
		ac[fs->n0++] = '-';
	else if (fs->flags & FPL)
		ac[fs->n0++] = '+';
	else if (fs->flags & FSP)
		ac[fs->n0++] = ' ';
	fs->s = &ac[fs->n0];
	ldtob(fs, ac);
}
