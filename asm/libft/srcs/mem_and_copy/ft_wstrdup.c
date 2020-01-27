/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:03:10 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/11/16 16:20:06 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *s)
{
	int		i;
	wchar_t	*s2;

	if (s == NULL)
		return (ft_wstrdup(L"(null)"));
	i = ft_wstrlen(s);
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1))))
		return (NULL);
	s2[i] = '\0';
	while (i--)
		s2[i] = s[i];
	return (s2);
}
