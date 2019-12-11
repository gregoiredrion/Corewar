/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:39:39 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/06/28 18:04:38 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int			ft_isalpha(int c)
{
	if (ft_islower(c) == 1 || ft_isupper(c) == 1)
		return (1);
	return (0);
}
