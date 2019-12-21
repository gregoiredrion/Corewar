/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:19:12 by gdrion            #+#    #+#             */
/*   Updated: 2019/12/21 10:54:32 by gregoiredrion    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		stock_fd(t_cor *cor, char *file)
{
	int 	ret;
	char	*new;
	char	buffer[BUFF_SIZE + 1];

	if ((cor->fd = open(file, O_RDONLY)) == -1)
	{
		//ft_printf("Read Error\n");
		return (0);
	}
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

	i = 0;
	pos  = 0;
	stock_fd(cor, file);
	if (trim_file(&(cor->file)) == -1)
		return (MALLOC_ERROR);
	while (i < cor->size)
	{
		i = skip_comment(cor->file, i, &(cor->line), &pos);
		//get_token
		if (!(i = skip_newline(cor->file, i, &(cor->line), &pos)))
			return (0);
		printf("Line = %zu - Pos = %zu - i = %zu\n", cor->line,pos, i);
		printf("File start pos = :%s:\n", cor->file + pos);
		printf("File start i = :%s:\n", cor->file + i);
		printf("Error token [%03zu][%03zu]\n", cor->line, i - pos);
		exit (1);
	}
	return (1);
}
