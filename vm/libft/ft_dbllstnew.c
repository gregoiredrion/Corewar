/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:49:01 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/27 15:51:46 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbllstnew(void *content, size_t content_size)
{
	t_dbl_list	*new;

	if (!(new = ft_memalloc(sizeof(t_dbl_list))))
		return (NULL);
	if (content)
	{
		new->content = content;
		new->content_size = content_size;
	}
	return (new);
}
