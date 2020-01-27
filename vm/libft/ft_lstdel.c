/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:02:41 by lode-spi          #+#    #+#             */
/*   Updated: 2018/10/12 13:06:55 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*t;
	t_list	*tmp;

	t = *alst;
	while (t)
	{
		tmp = t;
		(*del)(tmp->content, tmp->content_size);
		t = t->next;
		free(tmp);
	}
	*alst = NULL;
}
