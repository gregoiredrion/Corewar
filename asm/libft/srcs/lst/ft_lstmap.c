/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:00:51 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/04 12:04:42 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*save;

	if (!lst || !(tmp = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	tmp = f(lst);
	save = tmp;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		tmp->next = f(lst);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (save);
}
