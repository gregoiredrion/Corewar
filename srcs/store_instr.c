/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:10:59 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/30 14:25:18 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	op_tab[];

t_op	store_instr(t_token *token)
{
	size_t	i;
	t_op	op;

	i = 0;
	while (op_tab[i].name)
	{
		if (!ft_strcmp(token->str, op_tab[i].name))
			break ;
		i++;
	}
	if (!op_tab[i].name)
		return (NULL/*invalid_instr(token)*/);
	op = op_tab[i];
	//cor->prog[cor->size++] = cor->op.opcode;// to do: better join
	return (OK);
}
