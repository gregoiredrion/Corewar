/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:32:59 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/22 14:05:25 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s_start;
	char	*s_end;
	char	*ret;
	char	*tag;

	if (!s)
		return (NULL);
	s_start = (char*)s;
	s_end = (char*)s;
	while (*s_end)
		s_end++;
	while (*s_start && ((*s_start >= 9 && *s_start <= 10) || *s_start == 32))
		s_start++;
	while (s_end > s_start && ((*s_end >= 9 && *s_end <= 10)
				|| *s_end == 32 || !*s_end))
		s_end--;
	if (!(ret = (char*)malloc(sizeof(*ret) * (s_end - s_start + 2))))
		return (NULL);
	tag = ret;
	while (s_start != s_end + 1)
		*tag++ = *s_start++;
	*tag = '\0';
	return (ret);
}
