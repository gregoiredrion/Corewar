/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:41:10 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/04 18:44:10 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list*ft_lstadd_begin(t_list *lst, t_list *new_elem)
{
	new_elem->next = lst;
	lst = new_elem;
	return (lst);
}
