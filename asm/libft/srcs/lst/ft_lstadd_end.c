/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:27:42 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/04 18:49:50 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstadd_end(t_list *lst, t_list *last_elem)
{
	t_list	*save;

	save = lst;
	while (lst->next)
		lst = lst->next;
	last_elem->next = NULL;
	lst->next = last_elem;
	return (save);
}
