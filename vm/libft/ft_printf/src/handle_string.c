/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:06:06 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:59:28 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_string(va_list ap, t_formspec *fs)
{
	fs->s = va_arg(ap, char*);
	if (fs->s)
		fs->n1 = (int)ft_strlen(fs->s);
	else
		fs->n1 = 6;
	if (fs->prec >= 0 && fs->prec < fs->n1)
		fs->n1 = fs->prec;
}
