/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:29:46 by lode-spi          #+#    #+#             */
/*   Updated: 2019/09/01 19:11:56 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	genld_a(t_formspec *fs, char *p, int nsig, int exp)
{
	fs->s[fs->n1++] = '0';
	if (fs->prec > 0 || fs->flags & FNO)
		fs->s[fs->n1++] = '.';
	if (fs->prec < -exp)
		exp = -fs->prec;
	fs->nz1 = -exp;
	fs->prec += exp;
	if (fs->prec < nsig)
		nsig = fs->prec;
	ft_memcpy(&fs->s[fs->n1], p, fs->n2 = nsig);
	fs->nz2 = fs->prec - nsig;
}

static void	genld_b(t_formspec *fs, char *p, int nsig, int exp)
{
	ft_memcpy(&fs->s[fs->n1], p, nsig);
	fs->n1 += nsig;
	fs->nz1 = exp - nsig;
	if (fs->prec > 0 || fs->flags & FNO)
	{
		fs->s[fs->n1] = '.';
		fs->n2++;
	}
	fs->nz2 = fs->prec;
}

static void	genld_c(t_formspec *fs, char *p, int nsig, int exp)
{
	ft_memcpy(&fs->s[fs->n1], p, exp);
	fs->n1 += exp;
	nsig -= exp;
	if (fs->prec > 0 || fs->flags & FNO)
		fs->s[fs->n1++] = '.';
	if (fs->prec < nsig)
		nsig = fs->prec;
	ft_memcpy(&fs->s[fs->n1], p + exp, nsig);
	fs->n1 += nsig;
	fs->nz1 = fs->prec - nsig;
}

void		genld(t_formspec *fs, char *p, short nsig, short exp)
{
	int		n;

	if (nsig <= 0)
	{
		nsig = 1;
		p = "0";
	}
	exp++;
	if (exp <= 0)
		genld_a(fs, p, nsig, exp);
	else if (nsig < exp)
		genld_b(fs, p, nsig, exp);
	else
		genld_c(fs, p, nsig, exp);
	if ((fs->flags & (FMI | FZE)) == FZE)
	{
		n = fs->n0 + fs->n1 + fs->nz1 + fs->n2 + fs->nz2;
		if (fs->width > n)
			fs->nz0 = fs->width - n;
	}
}
