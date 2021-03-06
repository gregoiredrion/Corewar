/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:59:07 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/12 20:12:42 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		pushback(t_cor *cor, t_label *add)
{
	t_label		*tmp;

	if (!cor->labels)
	{
		cor->labels = add;
		return ;
	}
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
	if (!(new->name = ft_strndup(name, ft_strlen(name) - 1)))
		return (NULL);
	new->pos = pos;
	new->next = NULL;
	return (new);
}

t_token			*store_label(t_cor *cor, t_token *label, int *error)
{
	t_label		*new;

	if (!(new = init_label(label->str, cor->size)))
	{
		*error = MALLOC_ERROR;
		return (NULL);
	}
	pushback(cor, new);
	return (label->next);
}
