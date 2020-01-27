/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wctob.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:05:31 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:01:49 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		numbits(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	if (0x80 <= c && c <= 0x7FF)
		return (2);
	if (0x800 <= c && c <= 0xFFFF)
		return (3);
	else
		return (4);
}

void	wctob(t_formspec *fs)
{
	char	ac[4];
	int		i;
	wchar_t	wc;

	wc = *(fs->wc);
	fs->n1 = numbits(wc);
	i = fs->n1;
	if (i == 1)
		ac[3] = (char)wc;
	else
	{
		while (--i > 0)
			ac[4 - fs->n1 + i] = 0X80 | ((wc >> 6 * (fs->n1 - i - 1)) & 0X3F);
		ac[4 - fs->n1] = ((0XF0 << (4 - fs->n1)) & 0XFF) |
			(wc >> 6 * (fs->n1 - 1));
	}
	ft_memcpy(fs->s, &ac[4 - fs->n1], fs->n1);
}
