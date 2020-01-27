/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:07:29 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/11/16 16:16:20 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(const wchar_t *wstr)
{
	int		count;

	count = 0;
	while (wstr && *wstr)
	{
		if (*wstr >= 0 && !(*wstr >= 0xd800 && *wstr <= 0xdfff))
		{
			if (*wstr < 0x80)
				count++;
			else if (*wstr < 0x800)
				count = count + 2;
			else if (*wstr < 0x10000)
				count = count + 3;
			else if (*wstr < 0x100000)
				count = count + 4;
			else
				return (-1);
		}
		else
			return (-1);
		wstr++;
	}
	return (count);
}
