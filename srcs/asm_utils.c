/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:01:52 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 15:37:13 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//to do : creer macro pour present/pas present
int		empty(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != '\t' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		upper(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		blank(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}
