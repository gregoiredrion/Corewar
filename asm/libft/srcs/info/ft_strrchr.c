/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:12:24 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/06/21 18:01:41 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s2;

	s2 = NULL;
	while (*s)
	{
		if (*s == (char)c)
			s2 = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)s2);
}
