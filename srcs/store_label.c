/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:59:07 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/11 01:31:51 by wdeltenr         ###   ########.fr       */
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
	new->name = ft_strndup(name, ft_strlen(name) - 1);
	new->pos = pos;
	new->next = NULL;
	return (new);
}

t_token			*store_label(t_cor *cor, t_token *label)
{
	t_label		*new;

	if (!(new = init_label(label->str, cor->size)))
		return (NULL);
	pushback(cor, new);
	return (label->next);
}
