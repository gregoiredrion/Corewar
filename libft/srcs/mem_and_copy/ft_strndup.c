/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:19:32 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/29 19:43:18 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	char	*save;

	if (!(ret = ft_strnew(n + 1)))
		return (NULL);
	save = ret;
	while (*s1 && n--)
		*ret++ = *s1++;
	*ret = '\0';
	return (save);
}
