/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:10:59 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 15:34:55 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	op_tab[];

int		store_instr(t_cor *cor, char *instr, char *params, char *raw)
{
	size_t	i;

	i = 0;
	while (op_tab[i].name)
	{
		if (!ft_strcmp(instr, op_tab[i].name))
			break ;
		i++;
	}
	if (!op_tab[i].name)
		return (invalid_instr(instr, cor->line, get_column(instr, raw)));
	cor->op = op_tab[i];
	cor->program[cor->size++] = cor->op.opcode;// to do: better join
	return (store_params(cor, params, raw));
}
