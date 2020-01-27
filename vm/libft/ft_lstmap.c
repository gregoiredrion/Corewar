/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:14:20 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/25 13:42:26 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new;

	new_list = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		new = (*f)(lst);
		new = ft_lstnew(new->content, new->content_size);
		ft_lstaddback(&new_list, new);
		lst = lst->next;
	}
	return (new_list);
}
