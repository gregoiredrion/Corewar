/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 01:24:43 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:57:30 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		one_step(long to_store, char *p)
{
	int		i;

	i = 8;
	while (to_store > 0 && i-- > 0)
	{
		*--p = (to_store % 10) + '0';
		to_store /= 10;
	}
	while (i-- > 0)
		*--p = '0';
}

void			fill_buff_ld(t_formspec *fs, t_ld *vars)
{
	long		to_store;
	int			approx;
	long double	ld;

	ld = vars->ldval;
	approx = fs->prec + vars->exp + 10;
	if (approx > 22)
		approx = 22;
	*(vars->p)++ = '0';
	while (approx > 0 && ld > 0.0)
	{
		to_store = (long)ld;
		if ((approx -= 8) > 0)
			ld = (ld - (long double)to_store) * 1e8L;
		vars->p += 8;
		one_step(to_store, vars->p);
	}
}
