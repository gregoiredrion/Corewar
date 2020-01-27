/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldtob.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:39:09 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:00:31 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*adjust(char *p, int *written, int *exp)
{
	*exp += 7;
	while (*p == '0')
	{
		p++;
		(*written)--;
		(*exp)--;
	}
	return (p);
}

static void		round_ld(t_formspec *fs, t_ld *vars, int written)
{
	char		drop;
	int			n;

	vars->nsig = fs->prec + vars->exp + 1;
	if (vars->nsig > written)
		vars->nsig = written;
	if (vars->nsig > 0)
	{
		drop = vars->nsig < written && vars->p[vars->nsig] >= '5' ? '9' : '0';
		n = vars->nsig;
		while (vars->p[--n] == drop)
			vars->nsig--;
		if (drop == '9')
			vars->p[n]++;
		if (n < 0)
		{
			vars->p--;
			vars->nsig++;
			vars->exp++;
		}
	}
}

static void		deal_ld(t_formspec *fs, t_ld *vars, char ac[])
{
	int			written;

	vars->ldval = fs->v.ld;
	scale(&(vars->exp), &(vars->ldval));
	fill_buff_ld(fs, vars);
	written = vars->p - &ac[1];
	vars->p = adjust(&ac[1], &written, &(vars->exp));
	round_ld(fs, vars, written);
}

void			ldtob(t_formspec *fs, char *uac)
{
	char		ac[32];
	t_ld		vars;

	vars.nsig = 0;
	vars.p = ac;
	if (fs->prec < 0)
		fs->prec = 6;
	if ((vars.err = unscale_ld(&vars.exp, fs->v.ld)) > 0)
	{
		if (fs->n0 > 0)
		{
			fs->n0 = 0;
			fs->s = &uac[0];
		}
		ft_memcpy(fs->s, vars.err == NAN ? "nan" : "inf", (fs->n1 = 3));
		return ;
	}
	else if (vars.err == 0)
	{
		vars.nsig = 0;
		vars.exp = 0;
	}
	else
		deal_ld(fs, &vars, ac);
	genld(fs, vars.p, vars.nsig, vars.exp);
}
