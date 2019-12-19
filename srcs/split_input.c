/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:09:56 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 17:51:06 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	end_quotes(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] != '"')
		i++;
	if (!input[i])
		return (ERROR);
	return (i);
}

static t_token	*create_token(char *input, int type, size_t col, size_t line)
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

static void		pushback(t_cor *cor, t_token *add)
{
	t_token	*tmp;

	if (!cor->tokens)
		cor->tokens = add;
	tmp = cor->tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
}

static int		add_token(t_cor *cor, char *input, size_t col, size_t line)
{
	int		type;
	t_token	*new;

	type = tokenisation(input);
	if (!(new = create_token(input, type, col, line)))
		return (MALLOC_ERROR);
	pushback(cor, new);
	return (OK);
}

int				split_input(t_cor *cor, char *input, size_t col, size_t line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (input[0] == '"')
		i = end_quotes(input);
	else
	{
		while (input[i])
		{
			if (input[i] == ' ' || input[i] == '\t' || input[i] =='\n')
				break;
			i++;
		}
	}
	if (!(tmp = ft_strndup(input, i)))
		return (MALLOC_ERROR);
	if (add_token(cor, tmp, col, line) == -1)
		return (MALLOC_ERROR);
	return (i);
}
