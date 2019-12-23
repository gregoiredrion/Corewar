/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:21:47 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/21 10:39:49 by gregoiredrion    ###   ########.fr       */
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

int			skip_newline(char *file, size_t i, size_t *line, size_t *pos)
{
	size_t ret;

	ret = 0;
	while (file[i] && (file[i] == '\t' || file[i] == ' ' || file[i] == '\n'))
	{
		if (file[i] == '\n')
		{
			ret = i;
			(*line)++;
			*pos = i + 1;
		}
		i++;
	}
	return (i);
}

int			skip_comment(char *file, size_t i, size_t *line, size_t *pos)
{
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
	i = skip_newline(file, i, line, pos);
	//if (!file[i])
		//return (0);
	return (i);
}
