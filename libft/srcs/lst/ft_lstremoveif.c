/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:11:55 by gdrion            #+#    #+#             */
/*   Updated: 2019/10/03 14:14:12 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstremoveif(t_list **alst, void *data_ref, int (*cmp)())
{
	t_list		*current;
	t_list		*prev;

	if (alst == NULL)
		return ;
	current = *alst;
	while (current != NULL)
	{
		if (cmp(current->content, data_ref) == 0)
		{
			if (current == *alst)
			{
				*alst = current->next;
				free(current);
				current = *alst;
				continue ;
			}
			else
				prev->next = current->next;
			free(current);
			current = prev;
		}
		prev = current;
		current = current->next;
	}
}
