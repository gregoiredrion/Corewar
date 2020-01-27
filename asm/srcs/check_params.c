/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:54:24 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/12 22:24:45 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	instr_params(t_cor *cor, t_token *token, size_t nb_arg)
{
	size_t	i;

	i = 0;
	while (i < nb_arg && !(token->type & (T_EOF | T_NEW)))
	{
		if (cor->tab[i] & token->type)
		{
			cor->tab[i] = (token->type & T_LAB) ? token->type - T_LAB :
			token->type;
			token = token->next;
			i++;
		}
		else
			return (invalid_param(cor->op.name, ARG_TYPE, token->type, i));
		if (token->type == T_SEP)
			token = token->next;
	}
	if (i < nb_arg || !(token->type & (T_EOF | T_NEW)))
		return (invalid_param(cor->op.name, NB_ARG, token->type, i));
	return (OK);
}
