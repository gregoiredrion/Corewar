/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:02:31 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/10 00:53:12 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		get_cmd_type(int *type, char *str)
{
	if (!(ft_strcmp(str, ".name")))
	 	*type = *type ^ T_CMT;
	else if (!(ft_strcmp(str, ".comment")))
		*type = *type ^ T_NAM;
	else
		*type = 0;
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

char	*change_settings(char *input, size_t *i, size_t *n)
{
	*i = *i + 1;
	*n = *n -1;
	return (input + 1);
}

int		tokenization(t_cor *cor, char *input, size_t col, size_t line)
{
	char	*token_string;
	t_token	*token;
	size_t	n;
	int		type;
	size_t	i;

	n = 0;
	type = get_type(input, &n);
	i = n + 1;
	if (type == T_STR)
	{
		input = change_settings(input, &i, &n);
		//n--;
		//i++;
	}
	token_string = ft_strndup(input, n);
	if (type & (T_NAM | T_CMT))
		get_cmd_type(&type, token_string);
	if (type == 0)
		return (ERROR);// Do lexical Error function ! Avant ???
	token = create_token(token_string, type, col, line);
	pushback(cor, token);
	//display_tokens(token);
	return (i);
}
