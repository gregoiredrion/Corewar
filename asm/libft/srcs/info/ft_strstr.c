/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:22:15 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/06/21 18:26:46 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		n;
	char		*s;
	const char	*tmp;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		n = 0;
		if (*haystack == needle[n])
		{
			tmp = haystack;
			s = (char *)haystack;
			while (n < ft_strlen(needle) && *tmp == needle[n])
			{
				tmp++;
				n++;
			}
		}
		if (n == ft_strlen(needle))
			return (s);
		else
			haystack++;
	}
	return (NULL);
}
