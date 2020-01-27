/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:21:28 by gdrion            #+#    #+#             */
/*   Updated: 2018/12/18 12:35:16 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*aapply_prec_d3(char *prec, t_flags *f, int i)
{
	char	c;

	if (f->zero == ' ' || (f->width <= i))
	{
		if (f->conv == 'p' || ((f->conv == 'x' || f->conv == 'X') && f->hash))
		{
			if (!(prec = join_and_free(ft_strdup("0x"), prec)))
				return (NULL);
		}
		else if ((f->plus || f->space) && ((f->conv == 'd' || f->conv == 'D'
		|| f->conv == 'I' || f->conv == 'i') && *prec != '-'))
		{
			c = (f->plus >= f->space) ? '+' : ' ';
			if (!(prec = ft_buf_char(prec, c, 2, 1)))
				return (NULL);
		}
	}
	f->precision = (int)ft_strlen(prec);
	return (prec);
}

static char	*aapply_prec_d2(char *nb, int nb_len, char *prec, t_flags *f)
{
	int	i;

	i = 0;
	if (*nb == '-' && (f->zero == ' ' || f->width < nb_len) && nb_len--)
		prec[i++] = *nb++;
	else if (*nb == '-' && nb_len--)
		nb++;
	while (f->precision-- > nb_len)
		prec[i++] = '0';
	while (nb_len--)
		prec[i++] = *nb++;
	return (aapply_prec_d3(prec, f, i));
}

char		*aapply_prec_d(t_flags *f, char *nb)
{
	char	*prec;
	int		nb_len;
	int		p_len;

	nb_len = (int)ft_strlen(nb);
	if (*nb == '0')
	{
		if (f->precision > -1)
			nb_len = 0;
		if (f->conv == 'x' || f->conv == 'X')
			f->hash = 0;
	}
	p_len = (f->precision > nb_len) ? f->precision : nb_len;
	if (!(prec = ft_strnew(p_len + 1)))
		return (NULL);
	return (aapply_prec_d2(nb, nb_len, prec, f));
}

char		*aaply_width_d(t_flags *f, int w_len, char *nb)
{
	char	*wid;

	if (!(wid = ft_strnew(w_len)))
		return (NULL);
	ft_memset(wid, f->zero, (size_t)w_len);
	if (f->zero == '0')
	{
		if (f->conv == 'p' || ((f->conv == 'x' || f->conv == 'X') && f->hash))
		{
			wid[0] = '0';
			wid[1] = 'x';
		}
		else if (*nb == '-')
			wid[0] = '-';
		else if ((f->plus || f->space) && (f->conv == 'd' || f->conv == 'D' ||
		f->conv == 'i' || f->conv == 'I'))
			wid[0] = (f->plus >= f->space) ? '+' : ' ';
	}
	return (wid);
}
