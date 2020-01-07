/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:30:56 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/07 16:36:36 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*find_label(t_offset *offset, t_label *label)
{
	while (label)
	{
		if (!ft_strcmp(label->name, offset->name))
			return (label);
	}
	return (NULL);
}

static void	process_offset(t_cor *cor, t_label *label, t_offset *offset)
{
	int		i;
	int		res;

	i = offset->pos;
	res = label->pos - offset->start;
	cor->prog[i] = res;//need to reverse and to know how many bytes
}

int			offsets(t_cor *cor)
{
	t_offset	*offset;
	t_label		*label;

	offset = cor->offset;
	while (offset)
	{
		if (!(label = find_label(offset, cor->labels)))
		{
			ft_printf("No such label lie while attempting to dereference token [TOKEN][007:007] DIRECT_LABEL \"%s\"", offset->name);
			return (ERROR);
		}
		process_offset(cor, label, offset);
		offset = offset->next;
	}
	return (OK);
}
