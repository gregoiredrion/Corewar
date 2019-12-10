/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_displays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:08:12 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/10 16:46:38 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	usage(void)
{
	write(2, "Usage: ./asm [-a] <sourcefile.s>\n\t-a : Instead of creating a"
	" .cor file, outputs a stripped and annotated version of the code to the"
	" standard output\n", 148);
}
