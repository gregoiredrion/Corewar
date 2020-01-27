/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:06:18 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:59:57 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_wchar(va_list ap, t_formspec *fs, char *ac)
{
	wchar_t	wc;

	wc = va_arg(ap, wchar_t);
	fs->wc = &wc;
	fs->s = ac;
	wctob(fs);
}
