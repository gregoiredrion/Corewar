/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:42:31 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/29 14:16:14 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*id_token(t_token *token)
{
	if (token->type == T_REG)
		return ("REGISTER");
	else if (token->type == T_DIR)
		return ("DIRECT");
	else if (token->type == T_IND)
		return ("INDIRECT");
	else if (token->type == T_LAB)
		return ("LABEL");
	else if (token->type == T_CMD)
		return ("COMMAND");
	else if (token->type == T_STR)
		return ("STRING");
	else if (token->type == T_INS)
		return ("INSTRUCTION");
	else if (token->type == T_SEP)
		return ("SEPARATOR");
	return ("Error Boiiii");
}
void			display_tokens(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == T_NEW)
			printf("\n");
		else
			ft_printf("[%s] ", id_token(tokens));
		tokens = tokens->next;
	}
}