/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:47:58 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/12 20:14:37 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		write_prog(t_cor *cor, int add, size_t nb_bytes, int *error)
{
	if (cor->size + nb_bytes + 1 >= cor->max)
	{
		if (!(cor->prog = realloc(cor->prog, cor->max * 2)))
		{
			*error = MALLOC_ERROR;
			return (MALLOC_ERROR);
		}
		ft_bzero(cor->prog + cor->max, cor->max);
		cor->max *= 2;
	}
	if (nb_bytes == 1)
		cor->prog[cor->size] = (char)add;
	else if (nb_bytes == 2)
		*((short *)&(cor->prog[cor->size])) = reverse_int16(add);
	else if (nb_bytes == 4)
		*((int *)&(cor->prog[cor->size])) = reverse_int32(add);
	cor->size += nb_bytes;
	return (OK);
}
