/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:02:31 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/14 00:33:37 by gdrion           ###   ########.fr       */
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

static void		update_cline(char *input, size_t *n, size_t *col, size_t *line)
{
	char	*save;
	int		c;

	c = *n;
	save = input;
	while (c-- && *input)
	{
		if (*input++ == '\n')
		{
			*col = 0;
			*line += 1;
		}
		*col += 1;
	}
	if (*input)
		*col += 1;
}

static int		change_settings(t_cor *cor, char *s, size_t *n, size_t *col)
{
	t_token	*token;

	token = create_token(NULL, T_STR, *col, cor->line);
	update_cline(s, n, col, &cor->line);
	token->str = ft_strndup(s + 1, *n - 1);
	pushback_token(cor, token);
	return (*n + 1);
}

int				tokenization(t_cor *cor, char *input, size_t *col, size_t *line)
{
	char	*token_string;
	t_token	*token;
	size_t	n;
	int		type;
	size_t	i;

	n = 0;
	type = get_type(input, &n);
	i = n;
	if (type == T_STR && i++)
		return (change_settings(cor, input, &n, col));
	else if (type == T_EOF)
		update_cline(input, &n, col, line);
	if (!(token_string = ft_strndup(input, n)))
		return (MALLOC_ERROR);
	if (type & (T_NAM | T_CMT))
		get_cmd_type(&type, token_string);
	if (type == 0)
		return (lexical_error(*line, *col, token_string));
	if (!(token = create_token(token_string, type, *col, *line)))
		return (MALLOC_ERROR);
	pushback_token(cor, token);
	if (!(type & (T_STR | T_EOF)))
		*col += i;
	return (i);
}
