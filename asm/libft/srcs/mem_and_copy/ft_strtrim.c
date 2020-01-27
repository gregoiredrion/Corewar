/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:51:14 by wdeltenr          #+#    #+#             */
/*   Updated: 2018/07/03 17:53:56 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	int		t;

	t = 0;
	if (!s)
		return (NULL);
	t = ft_strlen(s);
	i = t - 1;
	n = 0;
	while (s[n] == '\n' || s[n] == ' ' || s[n] == '\t')
	{
		n++;
		t--;
	}
	while ((s[i] == '\n' || s[i] == ' ' || s[i] == '\t') && t > 0)
	{
		i--;
		t--;
	}
	return (ft_strsub(s, n, t));
}
