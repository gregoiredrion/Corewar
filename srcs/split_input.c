/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:09:56 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/29 15:55:25 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	end_quotes(char *input, size_t i)
{
	while (input[i] && input[i] != '"')
		i++;
	if (!input[i])
		return (ERROR);
	return (i + 1);
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
	{
		cor->tokens = add;
		return ;
	}
	tmp = cor->tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
}

static int		add_token(t_cor *cor, char *input, size_t i, size_t line)
{
	int		type;
	t_token	*new;
	size_t col = 0;//tmp

	i = 0; //Variable unused error
	if (!(type = tokenisation(input)))
		return (lexical_error(0, line));
	if (!(new = create_token(input, type, col, line)))
		return (MALLOC_ERROR);
	pushback(cor, new);
	return (OK);
}

int				split_input(t_cor *cor, char *input, size_t i, size_t line)
{
	char	*tmp;
	size_t col;
	col  = 0;//tmp Silence error since variable unused
	size_t	j;

	j = i;
	if (input[i] == '"')
	{
		if (!(i = end_quotes(input, i + 1)))
					return (0);
	}
	else
	{
		while (input[i])
		{
			if (input[i] == ' ' || input[i] == '\t'
				|| input[i] =='\n' || input[i] == SEPARATOR_CHAR)
				break;
			i++;
		}
	}
	if (i == j)
		i += 1;
	if (!(tmp = ft_strndup(&input[j], i - j)))
		return (MALLOC_ERROR);
	if (add_token(cor, tmp, j, line) <= 0)
		return (0);//fix for malloc error
	return (i);
}
