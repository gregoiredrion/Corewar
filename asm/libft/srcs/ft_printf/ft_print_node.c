/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:36:20 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/04 18:51:43 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_node(t_list *lst, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		i++;
		lst = lst->next;
	}
	ft_putstr(lst->content);
	ft_putstr("\n");
}
