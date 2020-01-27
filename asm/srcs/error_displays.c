/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_displays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:08:12 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/12 19:21:17 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		error_msg(int ret)
{
	if (ret == MALLOC_ERROR)
		write(2, "Malloc error\n", 13);
	return (ret);
}

int		usage(void)
{
	write(2, "Usage: ./asm  <sourcefile.s>\n", 29);
	return (0);
}
