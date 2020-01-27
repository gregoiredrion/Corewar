/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:05:53 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:58:23 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_ptr(va_list ap, t_formspec *fs, char *ac)
{
	fs->uim = (uintmax_t)((unsigned long)va_arg(ap, void*));
	ac[fs->n0++] = '0';
	ac[fs->n0++] = 'x';
	fs->s = &ac[fs->n0];
	uimtob(fs, 'x');
}
