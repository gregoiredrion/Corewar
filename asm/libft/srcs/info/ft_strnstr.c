/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:22:15 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/03 15:19:56 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		n;
	size_t		save;
	const char	*tmp;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		save = len;
		n = 0;
		if (*haystack == needle[n])
		{
			tmp = haystack;
			while (n < ft_strlen(needle) && *tmp == needle[n] && *tmp && save--)
			{
				tmp++;
				n++;
			}
		}
		len--;
		if (n == ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
