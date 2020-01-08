/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:31:19 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/30 13:43:58 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token		*starting_token(t_token *token)
{
	if (token->type & (T_CMD | T_INS | T_LAB))
		return (token->next);
	return (NULL);
}

static t_token		*ending_token(t_token *token)
{
	if (token->type & (T_EOF | T_NEW))
		return (token->next);
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
		//if (!(tokens = check_params(tokens)))
		//	return (ERROR);
		if (!(tokens = ending_token(tokens)))
			return (ERROR);
	}
	return (OK);
}
