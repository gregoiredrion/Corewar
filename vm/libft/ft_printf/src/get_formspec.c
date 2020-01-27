/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:03:46 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:58:03 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_flags(const char *restrict *format, t_formspec *fs)
{
	const char	*t;
	const char	fchar1[] = {' ', '+', '-', '#', '0', 0};
	const char	fbit1[] = {FSP, FPL, FMI, FNO, FZE, 0};

	fs->flags = 0;
	while ((t = ft_strchr(fchar1, **format)) != NULL)
	{
		fs->flags |= fbit1[t - fchar1];
		(*format)++;
	}
}

static void	get_width(const char *restrict *format, t_formspec *fs)
{
	fs->width = 0;
	while (ft_isdigit(**format))
	{
		fs->width = fs->width * 10 + **format - 48;
		(*format)++;
	}
}

static void	get_prec(const char *restrict *format, t_formspec *fs)
{
	if (**format != '.')
		fs->prec = -1;
	else
	{
		fs->prec = 0;
		(*format)++;
		while (ft_isdigit(**format))
		{
			fs->prec = fs->prec * 10 + **format - 48;
			(*format)++;
		}
	}
}

static void	get_qual(const char *restrict *format, t_formspec *fs)
{
	fs->qual = ft_strchr("hljzL", **format) ? *(*format)++ : '\0';
	if (**format == 'h')
	{
		fs->qual = 'H';
		(*format)++;
	}
	else if (**format == 'l')
	{
		fs->qual = 'X';
		(*format)++;
	}
}

void		get_formspec(const char *restrict *format, t_formspec *fs)
{
	get_flags(format, fs);
	get_width(format, fs);
	get_prec(format, fs);
	get_qual(format, fs);
}
