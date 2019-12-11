/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:54:10 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/09/02 17:40:35 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_and_free_newline(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*s_join;

	if (!s1 || !s2)
		return (NULL);
	n = 0;
	i = 0;
	if (!(s_join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (NULL);
	while (s1[n])
		s_join[i++] = s1[n++];
	n = 0;
	s_join[i++] = '\n';
	while (s2[n])
		s_join[i++] = s2[n++];
	s_join[i] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (s_join);
}
