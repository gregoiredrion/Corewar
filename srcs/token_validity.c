/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:31:19 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/13 21:55:54 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token		*param_token(t_token *token, int type)
{
	if (type == T_INS)
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
				return (syntax_newline());//special syntax error
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

static t_token		*check_name_cmt(t_token *token)
{
	static int	name = 0;
	static int	cmt = 0;

	if (token->type == T_LAB)
	{
		if (cmt == 0 || name == 0)
			return (syntax_error(token));
		return (token);
	}
	if (token->type == T_NAM)
		name++;
	if (token->type == T_CMT)
		cmt++;
	if (cmt > 1 || name > 1)
		return (syntax_error(token));
	if (token->type == T_INS && (cmt == 0 || name == 0))
		return (syntax_error(token));
	return (param_token(token->next, token->type));
}

static t_token		*starting_token(t_token *token)
{
	if (token->type & (T_NAM | T_INS | T_CMT))
		return (check_name_cmt(token));
	if (token->type & (T_LAB))
	{
		if (!check_name_cmt(token))
			return (NULL);
		token = token->next;
		if (!(token->type & (T_NEW | T_INS)))
			return (syntax_error(token));
		if (token->type == T_INS)
			return (starting_token(token));
		if (token->type == T_NEW)
			return (starting_token(token->next));
		return (token);
	}
	return (syntax_error(token));
}

static t_token		*ending_token(t_token *token)
{
	if (token->type & T_NEW)
		return (token->next);
	if (token->type & T_EOF)
		return (token);
	return (NULL);
}

int					token_validity(t_cor *cor)
{
	t_token	*tokens;

	tokens = cor->tokens;
	while (tokens && tokens->type != T_EOF)
	{
		if (!(tokens = starting_token(tokens)))
			return (ERROR);
		if (!(tokens = ending_token(tokens)))
			return (ERROR);
	}
	return (OK);
}
