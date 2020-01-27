/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:49:32 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/10/03 15:15:03 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;
	void	*new_content;

	if (!(new_elem = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
		new_elem->next = NULL;
		return (new_elem);
	}
	if (!(new_content = malloc(content_size)))
		return (NULL);
	new_content = ft_memcpy(new_content, content, content_size);
	new_elem->content = new_content;
	new_elem->content_size = content_size;
	new_elem->next = NULL;
	return (new_elem);
}
