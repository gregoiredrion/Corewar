/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:09:42 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/18 18:32:03 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*tag;

	if (!(ret = (char*)malloc(sizeof(*ret) * (ft_strlen(s1) + 1))))
		return (NULL);
	tag = ret;
	while (*s1)
		*tag++ = *s1++;
	*tag = '\0';
	return (ret);
}
