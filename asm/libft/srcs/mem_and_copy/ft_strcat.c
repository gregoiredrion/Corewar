/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:14:11 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/06/21 17:59:23 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		n;

	n = 0;
	i = ft_strlen(s1);
	while (s2[n])
	{
		s1[i] = s2[n];
		i++;
		n++;
	}
	s1[i] = '\0';
	return (s1);
}
