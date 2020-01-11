/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:58:33 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/11 22:20:46 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token	*store_tokens(t_cor *cor, t_token *token)
{
	if (token->type & (T_INS))
		if (!(token = store_instruction(cor, token)))
			return (NULL);
	if (token->type & (T_CMT | T_NAM))
		if (!(token = store_cmd(cor, token)))
			return (NULL);
	if (token->type & (T_LAB))
		token = store_label(cor, token);
	return (token);
}

int				process_tokens(t_cor *cor)
{
	t_token *token;

	token = cor->tokens;
	while (token->type != T_EOF)
	{
		if (token->type & (T_NAM | T_CMT | T_INS | T_LAB))
			token = store_tokens(cor, token);
		if (token && token->type & T_NEW)
			token = token->next;
		if (!token)
			return (ERROR);
	}
	if (!last_offsets(cor))
		return (ERROR);
	return (OK);
}
