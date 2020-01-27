/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:11:09 by gdrion            #+#    #+#             */
/*   Updated: 2019/09/06 22:18:57 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_tab_to_char(int *tab, int prec)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = ft_strnew(prec + 1)))
		return (NULL);
	new[i++] = '.';
	while (prec)
	{
		new[i] = tab[i] + 48;
		i++;
		prec--;
	}
	free(tab);
	return (new);
}

static int			*ft_round(int *tab, int index)
{
	if (index && tab[index] >= 5)
	{
		tab[index] = 0;
		tab[index - 1]++;
		if (tab[index - 1] > 9)
			ft_round(tab, index - 1);
	}
	return (tab);
}

static int			*ft_assign(long double nb, int *tab, int prec)
{
	int			i;
	int			save;
	intmax_t	integer;

	save = prec;
	i = 1;
	tab[0] = 0;
	if (nb < 0)
		nb = -nb;
	integer = (intmax_t)nb;
	nb = nb - (long double)integer;
	while (prec + 1)
	{
		nb = nb * 10;
		integer = (int)nb;
		tab[i++] = integer;
		nb = nb - (long double)integer;
		prec--;
	}
	ft_round(tab, save + 1);
	return (tab);
}

static char			*ft_before_dot(long double nb)
{
	if ((intmax_t)nb != 0)
		return (ft_itoa((intmax_t)nb));
	else if (nb > -1 && nb < 0)
		return (ft_strdup("-0"));
	else
		return (ft_strdup("0"));
}

char				*ft_dtoa2(long double nb, t_flags *f)
{
	int		*tab;
	char	*str_before_dot;
	char	*str_after_dot;
	char	*str;

	if (f->precision == -1)
		f->precision = 6;
	if (!(tab = (int *)malloc(sizeof(int) * (f->precision + 2))))
		return (NULL);
	tab = ft_assign(nb, tab, f->precision);
	if (tab[0] == 1 && nb >= 0)
		nb++;
	else if (tab[0] == 1 && nb < 0)
		nb--;
	str_before_dot = ft_before_dot(nb);
	if (f->precision != 0)
	{
		str_after_dot = ft_tab_to_char(tab, f->precision);
		str = join_and_free(str_before_dot, str_after_dot);
		return (str);
	}
	else if (f->hash)
		str_before_dot = join_and_free(str_before_dot, ft_strdup("."));
	free(tab);
	return (str_before_dot);
}
