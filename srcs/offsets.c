/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:30:56 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/12 00:58:00 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_label	*find_label(char *offset, t_label *label)
{
	size_t	i;

	i = (offset[0] == DIRECT_CHAR) ? 2 : 1;
	while (label)
	{
		if (!ft_strcmp(label->name, offset + i))
			return (label);
		label = label->next;
	}
	return (NULL);
}

static void		process_offset(t_cor *cor, t_label *label, t_offset *offset)
{
	int		res;

	res = label->pos - offset->start;
	if (offset->nb_bytes == 2)
		*((short *)&(cor->prog[offset->pos])) = reverse_int16(res);
	else if (offset->nb_bytes == 4)
		*((int *)&(cor->prog[offset->pos])) = reverse_int32(res);
}

int				last_offsets(t_cor *cor)
{
	t_offset	*offset;
	t_label		*label;
	size_t		i;

	offset = cor->offset;
	while (offset)
	{
		i = (offset->name[0] == DIRECT_CHAR) ? 2 : 1;
		if (!(label = find_label(offset->name, cor->labels)))
		{
			ft_printf("No such label %s while attempting to dereference token "
			"[TOKEN][%03d:%03d] DIRECT_LABEL \"%s\"\n", offset->name + i,
			offset->token->line, offset->token->col, offset->name);
			return (ERROR);
		}
		process_offset(cor, label, offset);
		offset = offset->next;
	}
	return (OK);
}

static int		store_offset(t_cor *cor, t_token *token, size_t nb_bytes)
{
	t_offset	*offset;
	t_offset	*new;

	if (!(new = malloc(sizeof(t_offset))))
		return (MALLOC_ERROR);
	new->name = token->str;
	new->start = cor->pos;
	new->pos = cor->size;
	new->nb_bytes = nb_bytes;
	new->token = token;
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

int				offsets(t_cor *cor, t_token *token, size_t nb_bytes)
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
