/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:02:31 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/12 01:31:34 by gdrion           ###   ########.fr       */
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

static char		*change_settings(char *input, size_t *i, size_t *n)
{
	*i = *i + 1;
	*n = *n - 1;
	return (input + 1);
}

int				tokenization(t_cor *cor, char *input, size_t *col, size_t line)
{
	char	*token_string;
	t_token	*token;
	size_t	n;
	int		type;
	size_t	i;

	n = 0;
	type = get_type(input, &n);
	i = n;
	if (type == T_STR)
		input = change_settings(input, &i, &n);
	token_string = ft_strndup(input, n);//protection?
	if (type & (T_NAM | T_CMT))
		get_cmd_type(&type, token_string);
	if (type == 0)
		return (lexical_error(line, *col));// Do lexical Error function ! Avant ???
	if (!(token = create_token(token_string, type, *col, line)))
		return (MALLOC_ERROR);
	pushback_token(cor, token);
	*col += i;
	return (i);
}
