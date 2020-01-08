/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:31:19 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/08 16:27:45 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token		*starting_token(t_cor *cor, t_token *token)
{
	cor = NULL; //Silence flags
	if (token->type & (T_NAM | T_INS | T_CMT))
		return (token);
	if (token->type & (T_LAB))
	{
		token = token->next;
		if (!(token->type & (T_NEW | T_INS)))
			return (NULL);
		if (token->type == T_NEW)
			return (token->next);
		return (token);
	}
	return (NULL);
}

static t_token		*ending_token(t_cor *cor, t_token *token)
{
	cor = NULL; //Silence flags
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
		if (!(tokens = starting_token(cor, tokens)))
			return (ERROR);
		if (!(tokens = check_params(cor, tokens)))
			return (ERROR);
		if (!(tokens = ending_token(cor, tokens)))
			return (ERROR);
	}
	return (OK);
}
