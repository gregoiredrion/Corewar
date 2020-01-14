/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validity2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:02:01 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/14 03:05:58 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token	*param_token_cmd(t_token *token)
{
	if (token->type != T_STR)
		return (syntax_error(token));
	token = token->next;
	if (token->type != T_NEW)
		return (syntax_error(token));
	return (token);
}

static t_token	*param_token_ins(t_token *token)
{
	if (!(token->type & (T_REG | T_DIR | T_IND)))
		return (syntax_error(token));
	while (!(token->type & (T_NEW | T_EOF)))
	{
		if (!(token->type & (T_REG | T_DIR | T_IND)))
			return (syntax_error(token));
		token = token->next;
		if (token->type == T_SEP && token->next &&
		token->next->type & (T_REG | T_DIR | T_IND))
			token = token->next;
		else if (token->type == T_SEP)
			return (syntax_error(token->next));
		else if (!(token->type == T_NEW))
			return (syntax_newline());
	}
	return (token);
}

t_token			*param_token(t_token *token, int type)
{
	if (type == T_INS)
		token = param_token_ins(token);
	else
		token = param_token_cmd(token);
	return (token);
}
