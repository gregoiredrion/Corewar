/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unscale_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 02:09:00 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:01:36 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	normalize(unsigned short *split)
{
	short	xchar;

	xchar = 0;
	while (split[3] == 0)
	{
		split[3] = split[2];
		split[2] = split[1];
		split[1] = split[0];
		split[0] = 0;
		xchar -= 16;
	}
	while (split[3] < 1U << 15)
	{
		split[3] = split[3] << 1 | split[2] >> 15;
		split[2] = split[2] << 1 | split[1] >> 15;
		split[1] = split[1] << 1 | split[0] >> 15;
		split[0] <<= 1;
		xchar--;
	}
	return (xchar);
}

/*
** __args
** _exponent : Adress where you want the exponent the be set
** _input : The value to unscale. Then reduced into the mantissa of it.
** __return
** _FINITE (-1) : If the number is finite
** _NAN    (1) : If the number is considered Not A Number
** _INF    (2) : IF the number is too big for the size of the variable
*/

short			unscale_ld(int *exp, long double input)
{
	unsigned short	*split;
	short			xchar;

	split = (unsigned short*)&input;
	xchar = split[4] & 0x7fff;
	if (xchar == 0x7fff)
	{
		*exp = 0;
		return (split[3] & 0x7fff ||
				split[2] || split[1] || split[0] ? NAN : INF);
	}
	else if (!split[3] && !split[2] && !split[1] && !split[0])
	{
		*exp = 0;
		return (0);
	}
	else
	{
		xchar += normalize(split);
		*exp = xchar - 0x3ffe;
		return (FINITE);
	}
}
