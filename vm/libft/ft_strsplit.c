/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:34:15 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/22 14:05:59 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		acc;

	acc = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s && *s == c)
				s++;
		}
		else if (*s != c)
		{
			while (*s && *s != c)
				s++;
			acc++;
		}
	}
	return (acc);
}

static char		*get_word_at(char const *s, int index, char c)
{
	int		acc;

	acc = 0;
	while (*s && acc < index)
	{
		if (*s == c)
		{
			while (*s && *s == c)
				s++;
		}
		else if (*s != c)
		{
			while (*s && *s != c)
				s++;
			acc++;
		}
	}
	while (*s == c)
		s++;
	return ((char*)s);
}

static int		get_first_word_size(char const *s, char c)
{
	int		acc;

	acc = 0;
	while (*s++ != c)
		acc++;
	return (acc);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		word_size;

	if (!s)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(*ret) * (count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	while (++i < count_words(s, c))
	{
		word_size = get_first_word_size(get_word_at(s, i, c), c);
		if (!(ret[i] = (char*)malloc(sizeof(**ret) * (word_size + 1))))
			return (NULL);
		j = 0;
		while (j < word_size)
		{
			ret[i][j] = get_word_at(s, i, c)[j];
			j++;
		}
		ret[i][j] = '\0';
	}
	ret[i] = 0;
	return (ret);
}
