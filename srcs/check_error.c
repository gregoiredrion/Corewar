/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:23:31 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/11 16:12:06 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_quotes(char *str)
{
	size_t	i;
	size_t quotes;

	i = 0;
	quotes = 0;
	while (str[i + 1])
	{
		if (str[i] == '"')
			quotes++;
		i++;
	}
	if (quotes != 1 || (str[i] && str[i] != '"'))
		return (0);
	return (i - 1);
}

char		*check_name_comment(int fd, const char *command)
{
	char	**split;
	char	*line;
	size_t	size;

	if (get_next_line(fd, &line) == -1)
		return (NULL);
	if (!(split = ft_strsplit(line, '"')))
		return (NULL);//free line and empty gnl
	if (!(size = check_quotes(line)))
		return (NULL);//free split and write lexical error
	ft_strdel(&line);
	if (!split[0] || !split[1] || split[2])
		return (NULL);//free split and write lexical error
	if (ft_strcmp(split[0], command))
		return (NULL);//free split and write lexical error
	return (split[1]);
}
