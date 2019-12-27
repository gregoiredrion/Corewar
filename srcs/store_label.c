/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:59:07 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/18 13:58:53 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		pushback(t_cor *cor, t_label *add)
{
	t_label		*tmp;

	if (!cor->labels)
		cor->labels = add;
	tmp = cor->labels;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
}

static t_label	*init_label(char *name, size_t pos)
{
	t_label		*new;

	if (!(new = malloc(sizeof(t_label))))
		return (NULL);
	new->name = name;
	new->pos = pos;
	new->next = NULL;
	return (new);
}

int				store_label(t_cor *cor, char *label)
{
	t_label		*new;

	if (!(new = init_label(label, cor->size)))
		return (MALLOC_ERROR);
	pushback(cor, new);
	return (OK);
}
