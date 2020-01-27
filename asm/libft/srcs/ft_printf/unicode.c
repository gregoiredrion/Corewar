/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:40:37 by gdrion            #+#    #+#             */
/*   Updated: 2019/02/09 16:46:00 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_mask(int byte_len)
{
	char	*mask;

	if (byte_len <= 7)
	{
		if (!(mask = ft_strdup("0xxxxxxx")))
			return (NULL);
	}
	else if (byte_len <= 11)
	{
		if (!(mask = ft_strdup("110xxxxx10xxxxxx")))
			return (NULL);
	}
	else if (byte_len <= 16)
	{
		if (!(mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx")))
			return (NULL);
	}
	else
	{
		if (!(mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx")))
			return (NULL);
	}
	return (mask);
}

static char	*transform(char *mask, wint_t a)
{
	int i;

	i = ft_strlen(mask) - 1;
	while (a)
	{
		if (mask[i] == 'x')
		{
			mask[i] = a % 2 + '0';
			a /= 2;
		}
		i--;
	}
	while (i > 0)
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i--;
	}
	return (mask);
}

static char	*convert_binary(char *mask)
{
	char	*transform;
	char	*test;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!(test = ft_strnew(4)))
		return (NULL);
	while (mask[i])
	{
		if (!(transform = ft_strndup(mask + i, 8)))
			return (NULL);
		test[a++] = ft_atoi_base(transform, 2);
		i += 8;
		ft_strdel(&transform);
	}
	ft_strdel(&mask);
	return (test);
}

int			get_byte_len(wint_t a)
{
	int		byte_len;

	byte_len = 1;
	while (a /= 2)
		byte_len++;
	if (byte_len <= 7)
		return (1);
	if (byte_len <= 11)
		return (2);
	if (byte_len <= 16)
		return (3);
	if (byte_len <= 21)
		return (4);
	return (-1);
}

char		*unicode(wint_t a)
{
	int		byte_len;
	char	*mask;
	wint_t	save;

	byte_len = 1;
	save = a;
	while (save /= 2)
		byte_len++;
	if (!(mask = get_mask(byte_len)))
		return (NULL);
	if (!(mask = transform(mask, a)))
		return (NULL);
	if (!(mask = convert_binary(mask)))
		return (NULL);
	return (mask);
}
