/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:14:56 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/12 16:20:23 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(s_copy = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (*s && len--)
	{
		s_copy[i] = s[start];
		i++;
		start++;
	}
	s_copy[i] = '\0';
	free((char *)s);
	return (s_copy);
}
