/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_displays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:08:12 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/11 13:53:43 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		usage(void)
{
	write(2, "Usage: ./asm [-a] <sourcefile.s>\n\t-a : Instead of creating a"
	" .cor file, outputs a stripped and annotated version of the code to the"
	" standard output\n", 148);
	return (0);
}
