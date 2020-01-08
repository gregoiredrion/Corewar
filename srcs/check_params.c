/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:54:24 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/30 17:52:48 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	op_tab[];

t_token		*label_params(t_token *token)
{
	if (token->next && token->next->type & T_NEW)
		token = token->next;
	if (token->next && (token->next->type & T_INSTR))
		return (token->next);
	else
		return (NULL);
}

t_token		*instr_params(t_token *token)
{
	size_t	i;
	t_op	op;
	t_token	prev;
	int		sep;

	sep = T_NEW | T_EOF | T_SEP;
	i = 0;
	prev.type = T_SEP;
	if (!(op = store_instr(token)))
		return (NULL);
	while (i < op.nb_arg && token->next)
	{
		if (prev.type & sep && token->next->type & op.arg_type[i])
		{
			prev.type = arg_type[i];
			i++;
		}
		else if (!(prev.type & T_NEW) && token->next->type & sep)
		{
			if (i < op.nb_arg && token->next->type & (T_NEW | T_SEP))
				return (NULL);
			prev.type = sep;
		}
		else
			return (NULL);
		token = token->next;
	}

}

// Function tab or if forest ?
t_token		*check_params(t_token *token)
{
	if (token->type == T_LAB)
		if (!(label_params(token)))
			return (ERROR);
	if (token->type == T_INSTR)
		if (!(instr_params(token))

}
