/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:34:30 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:00:09 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_wstrsize(t_formspec *fs)
{
	int		count;
	wchar_t	*tmp;
	int		prec;
	int		nbits;

	prec = fs->prec;
	tmp = fs->wc;
	count = 0;
	while (*tmp)
	{
		nbits = numbits(*tmp);
		if (prec >= 0 && prec < nbits)
			break ;
		count += nbits;
		prec -= nbits;
		tmp++;
	}
	return (count);
}

void		handle_wstring(va_list ap, t_formspec *fs)
{
	fs->wc = va_arg(ap, wchar_t*);
	if (fs->wc)
		fs->n1 = get_wstrsize(fs);
	else
		fs->n1 = 6;
	if (fs->prec >= 0 && fs->prec <= fs->n1)
		fs->n1 = fs->prec;
}
