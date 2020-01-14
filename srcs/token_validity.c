/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:31:19 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/14 03:05:41 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token		*check_name_cmt(t_token *token)
{
	static int	name = 0;
	static int	cmt = 0;

	if (token->type == T_LAB)
	{
		if (cmt == 0 || name == 0)
			return (syntax_error(token));
	}
	if (token->type == T_NAM)
		name++;
	if (token->type == T_CMT)
		cmt++;
	if (cmt > 1 || name > 1)
		return (syntax_error(token));
	return (token);
}

static t_token		*starting_token(t_token *token)
{
	if (token->type == T_NEW && token->next->type != T_EOF)
		return (token);
	else if (token->type == T_NEW)
		token = token->next;
	if (!check_name_cmt(token))
		return (NULL);
	if (token->type & (T_NAM | T_INS | T_CMT))
		return (param_token(token->next, token->type));
	if (token->type & (T_LAB))
	{
		token = token->next;
		if (!(token->type & (T_NEW | T_INS)))
			return (syntax_error(token));
		if (token->type == T_INS)
			return (starting_token(token));
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
	if (tokens->type == T_EOF)
	{
		syntax_error(tokens);
		return (ERROR);
	}
	while (tokens && tokens->type != T_EOF)
	{
		if (!(tokens = starting_token(tokens)))
			return (ERROR);
		if (!(tokens = ending_token(tokens)))
			return (ERROR);
	}
	return (OK);
}
