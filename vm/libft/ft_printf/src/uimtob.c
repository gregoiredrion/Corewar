/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uimtob.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:06:45 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:01:24 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base(char specif)
{
	if (specif == 'x' || specif == 'X')
		return (16);
	else if (specif == 'o' || specif == 'O')
		return (8);
	return (10);
}

static int	isofno(t_formspec *fs, char specif)
{
	return ((fs->flags & FNO) && (specif == 'o' || specif == 'O'));
}

static int	fill_buf(t_formspec *fs, char specif, char ac[], size_t size)
{
	uintmax_t	copy;
	char		*digs;
	size_t		i;
	int			base;

	digs = "0123456789abcdef0123456789ABCDEF";
	digs = (specif == 'X') ? digs + 16 : digs;
	base = get_base(specif);
	copy = fs->uim;
	i = size;
	if (copy != 0 || fs->prec != 0 || isofno(fs, specif))
		ac[--i] = digs[copy % base];
	copy /= base;
	while (copy > 0 && i > 0)
	{
		ac[--i] = digs[copy % base];
		copy /= base;
	}
	fs->n1 = size - i;
	ft_memcpy(fs->s, &ac[i], fs->n1);
	return (i);
}

void		uimtob(t_formspec *fs, char specif)
{
	char	ac[24];
	int		i;

	i = fill_buf(fs, specif, ac, 24);
	if (fs->n1 < fs->prec)
		fs->nz0 = fs->prec - fs->n1 - ((fs->uim != 0) ? isofno(fs, specif) : 0);
	if (fs->prec < 0 && (fs->flags & (FMI | FZE)) == FZE && (i = fs->width
				- fs->n0 - fs->nz0 - fs->n1) > 0)
		fs->nz0 += i;
}
