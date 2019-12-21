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

/*static size_t	get_column(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || ft_is_upper(line[i]))
			return (i);
		i++;
	}
	return (0);
}*/

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

int				store_label(t_cor *cor, char *label, char *raw)
{
	t_label		*new;

	if (upper(label) || blank(label))
		return (lexical_error(cor->line, get_column(raw, label)));//replace label
	if (!(new = init_label(label, cor->size)))
		return (MALLOC_ERROR);
	pushback(cor, new);
	return (OK);
}
