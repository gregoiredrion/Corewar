/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:54:24 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/08 13:15:00 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	op_tab[];

t_token		*instr_params(t_token *token)
{
	size_t	i;
	t_op	op;
	t_token	prev;
	int		sep;

	sep = T_SEP;
	i = 0;
	prev.type = sep;
	op = store_instr(token);
	if (op.name == NULL)
		return (NULL);
	while (i < op.nb_arg && token)
	{
		if (prev.type & sep && token->type & op.arg_type[i])
		{
			prev.type = op.arg_type[i];
			i++;
		}
		else if (prev.type & op.arg_type[i] && token->type & sep)
			prev.type = token->type;
		else
			return (NULL);
		token = token->next;
	}
	return (token);
}

t_token		*check_params(t_token *token)
{
	if (token->type & T_NEW)
		token = token->next;
	if (token->type == T_INS)
		return (instr_params(token));
	else
		return (NULL);
}
