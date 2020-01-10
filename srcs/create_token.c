/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:00:43 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/10 17:05:47 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			pushback_token(t_cor *cor, t_token *add)
{
	t_token	*tmp;
	if (!cor->tokens)
	{
		cor->tokens = add;
		return ;
	}
	tmp = cor->tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
}

t_token			*create_token(char *input, int type, size_t col, size_t line)
{
	t_token	*new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
	new->str = input;
	new->col = col;
	new->line = line;
	new->type = type;
	new->next = NULL;
	return (new);
}
