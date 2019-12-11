/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:43:18 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/05/09 14:43:22 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_tab_to_char(int *tab, int prec)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * (prec + 2))))
		return (NULL);
	new[i++] = '.';
	while (prec)
	{
		new[i] = tab[i] + 48;
		i++;
		prec--;
	}
	free(tab);
	new[i] = '\0';
	return (new);
}

static int		*ft_round(int *tab, int index)
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

static int		*ft_assign(long double nb, int *tab, int prec)
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

static char		*ft_before_dot(long double nb)
{
	char	*str;

	if ((intmax_t)nb != 0)
		str = ft_itoa((intmax_t)nb);
	else if (nb < 0 && nb > -1)
		str = ft_strdup("-0");
	else
		str = ft_strdup("0");
	return (str);
}

char			*ft_dtoa(long double nb, int prec)
{
	int		*tab;
	char	*str_before_dot;
	char	*str_after_dot;
	char	*str;

	tab = (int *)malloc(sizeof(int) * (prec + 2));
	tab = ft_assign(nb, tab, prec);
	if (tab[0] == 1 && nb >= 0)
		nb++;
	else if (tab[0] == 1 && nb < 0)
		nb--;
	str_before_dot = ft_before_dot(nb);
	if (prec != 0)
	{
		str_after_dot = ft_tab_to_char(tab, prec);
		str = ft_strjoin(str_before_dot, str_after_dot);
		free(str_before_dot);
		free(str_after_dot);
		return (str);
	}
	free(tab);
	return (str_before_dot);
}
