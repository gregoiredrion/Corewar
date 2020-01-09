/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:31:19 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/09 17:04:01 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token		*param_token(t_token *token, int type)
{
	if (type == T_INS)
	{
		while (token->type & (T_NEW | T_EOF))
		{
			if (!(token->type & (T_REG | T_DIR | T_IND)))
				return (syntax_error(token));
			token = token->next;
			if (token->type == T_SEP)
				token = token->next;
			else if (!(token->type & (T_NEW | T_EOF)))
				return (syntax_error(token));
		}
	}
	else
	{
		if (token->type != T_STR)
			return (syntax_error(token));
		token = token->next;
		if (token->type != T_NEW)
			return (syntax_error(token));
	}
	return (token);
}

static t_token		*starting_token(t_token *token)
{
	if (token->type & (T_NAM | T_INS | T_CMT))
		return (param_token(token->next, token->type));
	if (token->type & (T_LAB))
	{
		token = token->next;
		if (!(token->type & (T_NEW | T_INS)))
			return (syntax_error(token));
		if (token->type == T_NEW)// what about eof?
			return (starting_token(token->next));
		return (token);
	}
	return (syntax_error(token));
}

static t_token		*ending_token(t_token *token)
{
	if (token->type & (T_EOF | T_NEW))
		return (token);
	return (NULL);
}

int					token_validity(t_cor *cor)
{
	t_token	*tokens;

	tokens = cor->tokens;
	while (tokens)
	{
		if (!(tokens = starting_token(tokens)))
			return (ERROR);
		if (!(tokens = ending_token(tokens)))
			return (ERROR);
	}
	return (OK);
}
