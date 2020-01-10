/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:19:12 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/10 00:53:01 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		stock_fd(t_cor *cor, char *file)
{
	int 	ret;
	char	*new;
	char	buffer[BUFF_SIZE + 1];

	if ((cor->fd = open(file, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(cor->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!(cor->file))
			new = strdup(buffer);
		else
			new = ft_strjoin(cor->file, buffer);
		if (cor->file != NULL)
		{
			free(cor->file);
			cor->file = NULL;
		}
		cor->file = new;
		cor->size += ret;
	}
	return (ret == -1 ? -1 : 1);
}

int 		asm_parser(t_cor *cor, char *file)
{
	size_t	i;
	size_t 	pos;
	size_t	add;
	i = 0;
	pos  = 1;

	stock_fd(cor, file);

	if (trim_file(&(cor->file)) == -1)
		return (MALLOC_ERROR);
	while (i < cor->size)
	{
		i = skip_comment(cor, i, &(cor->line), &pos);
		if (!(add = tokenization(cor, cor->file + i, i, cor->line)))
			return (ERROR);
		i += add;
		i = skip_newline(cor, i, &(cor->line), &pos);
	}
	display_tokens(cor->tokens);
	return (OK);
}
