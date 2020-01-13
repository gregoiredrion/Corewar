/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:19:12 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/13 22:33:22 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		stock_fd(t_cor *cor, char *file)
{
	int		ret;
	char	*new;
	char	buffer[BUFF_SIZE + 1];

	if ((cor->fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Can't read source file %s\n", file);
		return (ERROR);
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
	return (ret == -1 ? MALLOC_ERROR : OK);
}

int				asm_parser(t_cor *cor, char *file)
{
	size_t	i;
	size_t	col;
	int		add;

	i = 0;
	col = 1;
	if ((add = stock_fd(cor, file)) < 1)
		return (add);
	while (i < cor->size + 1)
	{
		if ((add = skip_nl(cor, cor->file + i, &(cor->line), &col)) == -1)
			return (MALLOC_ERROR);
		i += add;
		if ((add = tokenization(cor, cor->file + i, &col, &(cor->line))) < 1)
			return (add);
		i += add;
	}
	close(cor->fd);
	return (OK);
}
