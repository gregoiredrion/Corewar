/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:21:47 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/29 16:17:43 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			trim_file(char **file)
{
	char	*new;
	if (!(new = ft_strtrim(*file)))
		return (MALLOC_ERROR);
	*file = new;
	return (1);
}

int			skip_newline(t_cor *cor, size_t i, size_t *line, size_t *pos)
{
	char	*file;
	size_t	nl;

	file = cor->file;
	nl = 0;
	while (file[i] && (file[i] == '\t' || file[i] == ' ' || file[i] == '\n'))
	{
		if (file[i] == '\n')
		{
			(*line)++;
			*pos = i + 1;
			nl = i;
		}
		i++;
	}
	if (cor->tokens && nl)
		split_input(cor, file, nl, *line);//tokenize newline
	return (i);
}

int			skip_comment(t_cor *cor, size_t i, size_t *line, size_t *pos)
{
	char	*file;

	file = cor->file;
	while (file[i] &&file[i] == '#')
	{
		while (file[i] && file[i] != '\n')
			i++;
		if (file[i] == '\n')
		{
			i++;
			(*line)++;
			*pos = i;
		}
		while (file[i] && (file[i] == '\t' || file[i] == ' ' || file[i] == '\n'))
		{
			if (file[i] == '\n')
			{
				(*line)++;
				*pos = i + 1;
			}
			i++;
		}
	}
	i = skip_newline(cor, i, line, pos);
	return (i);
}
