/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:05:21 by lode-spi          #+#    #+#             */
/*   Updated: 2019/09/01 19:55:30 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_put(const char *restrict *format, t_formspec *fs)
{
	const char *restrict	s;

	s = *format;
	while (*s && *s != '%')
		s++;
	fs->size += (size_t)(s - *format);
	return (write(1, *format, (size_t)(s - *format)));
}

int					print_formated(const char *restrict format, va_list ap)
{
	t_formspec				fs;
	char					ac[32];

	fs.size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((*format))
			{
				get_formspec(&format, &fs);
				if (dispatch(ap, &fs, *format, ac))
				{
					ordered_release(&fs, ac, *format);
					format++;
				}
			}
		}
		else
			format += ft_put(&format, &fs);
	}
	return ((int)fs.size);
}
