/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:15:46 by gdrion            #+#    #+#             */
/*   Updated: 2019/02/09 19:10:31 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_width(unsigned char *new, t_flags *f, unsigned char curr_arg)
{
	int i;

	i = 0;
	if (f->minus == 0)
	{
		while (f->width-- > 1)
			new[i++] = f->zero;
		new[i++] = curr_arg;
		new[i] = '\0';
	}
	else
	{
		new[i++] = curr_arg;
		while (f->width-- > 1)
			new[i++] = f->zero;
		new[i] = '\0';
	}
}

static char	*ft_harder_conv_c(va_list ap, t_flags *flags)
{
	unsigned char	*new;
	unsigned char	curr_arg;

	if (flags->minus)
		flags->zero = ' ';
	if (flags->conv != 'c')
		curr_arg = flags->conv;
	else
	{
		curr_arg = va_arg(ap, int);
		if (curr_arg == 0)
			flags->info2++;
	}
	if (!(new = malloc(sizeof(unsigned char) * (flags->width + 2))))
		return (NULL);
	fill_width(new, flags, curr_arg);
	return ((char *)new);
}

static char	*apply_flags(char *str, t_flags *flags)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = (str[0] == '\0') ? 1 : (int)ft_strlen(str);
	if (!(new = ft_strnew(flags->width + 1)))
		return (NULL);
	flags->width -= len;
	if (flags->minus == 1)
	{
		ft_strncpy(new, str, len);
		while (flags->width-- > 0)
			new[len++] = ' ';
	}
	else
	{
		while (flags->width-- > 0)
			new[i++] = flags->zero;
		ft_strncpy(new + i, str, len);
	}
	free(str);
	return (new);
}

char		*ft_conv_c(va_list ap, t_flags *flags)
{
	char	*uni;
	wint_t	curr_arg;

	if (flags->conv == 'C' || (flags->l == 1 && flags->conv == 'c'))
	{
		curr_arg = va_arg(ap, wint_t);
		if (!(uni = unicode(curr_arg)))
			return (NULL);
		if (curr_arg == 0)
			flags->info2++;
		return (apply_flags(uni, flags));
	}
	return (ft_harder_conv_c(ap, flags));
}
