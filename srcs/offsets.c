/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:30:56 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/09 16:17:50 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*find_label(char *offset, t_label *label)
{
	size_t	i;

	if (offset[0] == DIRECT_CHAR)
		i = 2;
	else
		i = 1;
	while (label)
	{
		if (!ft_strcmp(label->name, offset + i))
			return (label);
	}
	return (NULL);
}

int			last_offsets(t_cor *cor)
{
	t_offset	*offset;
	t_label		*label;

	offset = cor->offset;
	while (offset)
	{
		if (!(label = find_label(offset->name, cor->labels)))
		{
			ft_printf("No such label lie while attempting to dereference token [TOKEN][007:007] DIRECT_LABEL \"%s\"", offset->name);
			return (ERROR);
		}
		//process_offset(cor, label, offset);
		offset = offset->next;
	}
	return (OK);
}

static int	store_offset(t_cor *cor, t_token *token, size_t nb_bytes)
{
	t_offset	*offset;
	t_offset	*new;

	if (!(new = malloc(sizeof(t_offset))))
		return (MALLOC_ERROR);
	new->name = token->str;
	new->start = cor->pos;
	new->pos = cor->size;
	new->byte = nb_bytes;
	new->next = NULL;
	if (!cor->offset)
		cor->offset = new;
	else
	{
		offset = cor->offset;
		while (offset->next)
			offset = offset->next;
		offset->next = new;
	}
	return (OK);
}

int					offsets(t_cor *cor, t_token *token, size_t nb_bytes)
{
	t_label		*label;

	if ((label = find_label(token->str, cor->labels)))
			write_prog(cor, label->pos - cor->pos, nb_bytes);
	else
	{
		if (store_offset(cor, token, nb_bytes) == -1)
			return (MALLOC_ERROR);
		cor->size += nb_bytes;
	}
	return (OK);
}
