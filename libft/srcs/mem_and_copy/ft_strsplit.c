/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:55:51 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/10/29 13:32:56 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrds(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			i++;
		while (*s != c && *s)
			s++;
		while (*s == c)
			s++;
	}
	return (i);
}

static int	ft_new_size(const char *s, int size, char c)
{
	int		i;

	i = 0;
	while (s[size] != c && s[size])
	{
		i++;
		size++;
	}
	return (i + 1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	int		t;
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_wrds(s, c) + 1))))
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		t = 0;
		if (!(tab[n] = (char *)malloc(sizeof(char) * (ft_new_size(s, i, c)))))
			return (NULL);
		while (s[i] != c && s[i])
			tab[n][t++] = s[i++];
		while (s[i] == c)
			i++;
		if (t != 0)
			tab[n++][t] = '\0';
	}
	tab[n] = NULL;
	return (tab);
}
