/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_displays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:08:12 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/11 18:00:25 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		error_msg(int ret)
{
	if (ret == MALLOC_ERROR)
		ft_printf("Malloc error\n");
	else
		ft_printf("Error\n");
	return (ret);
}

int		usage(void)
{
	write(2, "Usage: ./asm [-a] <sourcefile.s>\n\t-a : Instead of creating a"
	" .cor file, outputs a stripped and annotated version of the code to the"
	" standard output\n", 148);
	return (0);
}
