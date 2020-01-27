/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:38:01 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:01:12 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		scale_up(int *exp, long double *ldval)
{
	int			i;
	int			n;

	n = (-*exp + 3) & ~3;
	*exp = -n;
	i = 0;
	while (n > 0)
	{
		if (n & 1)
			*ldval *= g_pows[i];
		n >>= 1;
		i++;
	}
}

static void		scale_down(int *exp, long double *ldval)
{
	int			i;
	int			n;
	long double	factor;

	factor = 1.0;
	*exp &= ~3;
	n = *exp;
	i = 0;
	while (n > 0)
	{
		if (n & 1)
			factor *= g_pows[i];
		n >>= 1;
		i++;
	}
	*ldval /= factor;
}

void			scale(int *exp, long double *ldval)
{
	if (*ldval < 0.0)
		*ldval = -*ldval;
	*exp = *exp * 30103L / 100000L - 4;
	if (*exp < 0)
		scale_up(exp, ldval);
	else if (*exp > 0)
		scale_down(exp, ldval);
}
