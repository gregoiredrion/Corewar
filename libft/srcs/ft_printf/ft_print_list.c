/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:32:50 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/05 15:12:13 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *lst)
{
	size_t	i;

	i = 1;
	if (!lst)
		return ;
	while (lst)
	{
		ft_putstr("Node ");
		ft_putnbr(i);
		ft_putstr(" :\n");
		ft_putstr(lst->content);
		ft_putstr("\n");
		i++;
		lst = lst->next;
	}
}
