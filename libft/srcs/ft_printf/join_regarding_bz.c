/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   je_code_parce_jaime_ca_bien_sur.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:34:41 by gdrion            #+#    #+#             */
/*   Updated: 2019/02/09 15:00:13 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen_info(char *s1, int info)
{
	int count;

	count = 0;
	while (info)
	{
		if (*s1 == '\0')
			info--;
		if (info)
		{
			s1++;
			count++;
		}
	}
	return (count);
}

static int		fill_regarding_bz(char *new, char *buf, int info, int i)
{
	while (info)
	{
		if (*buf == '\0')
			info--;
		if (info)
			new[i++] = *buf++;
	}
	return (i);
}

char			*ft_buf_char(char *buf, char c, int info, int nb_bz)
{
	char	*new;
	int		len;
	int		i;

	if (!buf)
		return (NULL);
	i = 0;
	len = ft_strlen_info(buf, nb_bz);
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	if (info == 1)
	{
		i = fill_regarding_bz(new, buf, nb_bz, i);
		new[i++] = c;
	}
	else if (info == 2)
	{
		new[i++] = c;
		i = fill_regarding_bz(new, buf, nb_bz, i);
	}
	ft_strdel(&buf);
	new[i] = '\0';
	return (new);
}

char			*join_regarding_bz(char *s1, int info1, char *s2, int info2)
{
	char	*s3;
	int		newlen;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	newlen = ft_strlen_info(s1, info1) + ft_strlen_info(s2, info2);
	if (!(s3 = ft_strnew(newlen)))
		return (NULL);
	i = fill_regarding_bz(s3, s1, info1, i);
	i = fill_regarding_bz(s3, s2, info2, i);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (s3);
}

void			ft_putstrn(char *s, int len)
{
	write(1, s, len);
	return ;
}
