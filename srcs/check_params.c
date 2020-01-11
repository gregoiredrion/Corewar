/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:54:24 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/10 21:49:17 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token	*store_cmd(t_cor* cor, t_token *token)
{
	if (token->type & T_NAM && token->next->type & T_STR)
		return (store_name(cor, token->next));
	if (token->type & T_CMT && token->next->type & T_STR)
		return (store_comment(cor, token->next));
	return (NULL);
}

int	instr_params(t_cor *cor, t_token *token, size_t nb_arg)
{
	size_t	i;

	i = 0;
	while (i < nb_arg && !(token->type & (T_EOF | T_NEW)))
	{
		if (cor->tab[i] & token->type)
		{
			cor->tab[i] = (token->type & T_LAB) ? token->type - T_LAB : token->type;
			token = token->next;
			i++;
		}
		else
			return (ERROR);//wrong param
		if (token->type == T_SEP)
			token = token->next;
		else if (!(token->type & (T_EOF | T_NEW)))
			return (ERROR);//wrong nb param
	}
	return (OK);
}
