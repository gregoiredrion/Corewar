/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:21:47 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/13 23:21:24 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_isblank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static size_t	skip_comment(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] != '\n')
		i++;
	return (i);
}

static int		add_newline_token(t_cor *cor, size_t col, size_t line)
{
	t_token	*token;

	if (!(token = create_token("\n", T_NEW, col, line)))
		return (MALLOC_ERROR);
	pushback_token(cor, token);
	return (OK);
}

int				skip_nl(t_cor *cor, char *input, size_t *line, size_t *col)
{
	size_t	i;
	size_t	add;

	add = 0;
	i = 0;
	while (ft_isblank(input[i]) || input[i] == '#')
	{
		if (input[i] == '\n')
		{
			if (!add)
				if (add_newline_token(cor, *(col), *line) == -1)
					return (MALLOC_ERROR);
			add++;
			*col = 0;
			(*line)++;
		}
		else if (input[i] == '#')
			i += skip_comment(input + i) - 1;
		i++;
		*col = *col + 1;
	}
	return (i);
}
