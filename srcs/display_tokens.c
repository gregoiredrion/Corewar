/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:42:31 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/10 17:13:52 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*id_token(t_token *token)
{
	if (token->type == T_REG)
		return ("REGISTER");
	if (token->type == (T_DIR | T_LAB))
		return ("DIRECT_LABEL");
	if (token->type == (T_IND | T_LAB))
		return ("INDIRECT_LABEL");
	else if (token->type == T_DIR)
		return ("DIRECT");
	else if (token->type == T_IND)
		return ("INDIRECT");
	else if (token->type == T_LAB)
		return ("LABEL");
	else if (token->type & (T_NAM | T_CMT))
		return ("COMMAND");
	else if (token->type == T_STR)
		return ("STRING");
	else if (token->type == T_INS)
		return ("INSTRUCTION");
	else if (token->type == T_SEP)
		return ("SEPARATOR");
	else if (token->type == T_EOF)
		return ("End of file");
	return ("Error Boiiii");
}
void			display_tokens(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == T_NEW)
			printf("[NEWLINE] \n");
		else
			ft_printf("[%s][%d:%d] ", id_token(tokens), tokens->line, tokens->col/*, tokens->str*/);
		tokens = tokens->next;
	}
	printf("\n");
}
