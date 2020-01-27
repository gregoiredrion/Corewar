/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:25:11 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/12/19 11:56:41 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_wint_t(char *bits, int nb_octet)
{
	int		i;
	char	*tmp;
	int		*octet;
	int		index;
	int		save;

	save = nb_octet;
	index = 0;
	i = 0;
	if (!(octet = (int *)malloc(sizeof(int) * nb_octet)))
		return ;
	while (nb_octet > 0)
	{
		tmp = ft_strsub(bits, i, 8);
		i = i + 8;
		octet[index] = ft_atoi_base(tmp, 2);
		free(tmp);
		nb_octet--;
		index++;
	}
	index = 0;
	while (index < save)
		write(1, &octet[index++], 1);
	free(octet);
}

static void	ft_fill_bits(int nb_octet, int *tab, int bits)
{
	char	*mask;
	int		end;

	if (nb_octet == 2)
		mask = ft_strdup("110xxxxx10xxxxxx");
	if (nb_octet == 3)
		mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	if (nb_octet == 4)
		mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	end = (int)ft_strlen(mask) - 1;
	while (bits >= 0)
	{
		while (mask[end] != 'x')
			end--;
		mask[end--] = tab[bits--] + 48;
	}
	while (mask[end])
	{
		if (mask[end] == 'x')
			mask[end] = '0';
		end--;
	}
	ft_write_wint_t(mask, nb_octet);
	free(mask);
}

static void	ft_len_to_print(int *tab, int bits)
{
	int		len;

	if (bits <= 7)
		len = 1;
	else if (bits > 7 && bits <= 11)
		len = 2;
	else if (bits > 11 && bits <= 16)
		len = 3;
	else
		len = 4;
	ft_fill_bits(len, tab, bits - 1);
}

void		ft_putwchar(wint_t c)
{
	int		*tab;
	int		bits;
	int		save_bits;
	wint_t	save;

	bits = 1;
	save = c;
	while ((save = save / 2))
		bits++;
	save = c;
	if (!(tab = (int *)malloc(sizeof(int) * bits)))
		return ;
	save_bits = bits;
	while (c > 0)
	{
		tab[--bits] = c % 2;
		c = (c - (c % 2)) / 2;
	}
	if (save_bits > 7)
		ft_len_to_print(tab, save_bits);
	else
		ft_putchar((char)save);
	free(tab);
}
