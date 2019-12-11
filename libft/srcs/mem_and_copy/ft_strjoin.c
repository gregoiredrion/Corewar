/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:33:41 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/06/24 16:52:39 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*s_join;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	n = 0;
	if (!(s_join = (char *)malloc(sizeof(char) * (i + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[n])
		s_join[i++] = s1[n++];
	n = 0;
	while (s2[n])
		s_join[i++] = s2[n++];
	s_join[i] = '\0';
	return (s_join);
}
