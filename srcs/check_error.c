/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:23:31 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/11 17:27:08 by gdrion           ###   ########.fr       */
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

int			check_name_comment(int fd, const char *cmp, char **s)
{
	char	*line;
	size_t	size;
	char	**split;

	if (get_next_line(fd, &line) == -1)
		return (MALLOC_ERROR);
	if (!(split = ft_strsplit(line, '"')))
		return (MALLOC_ERROR);//free line and empty gnl
	if (!(size = check_quotes(line)))
		return (ERROR);//free split and write lexical error
	ft_strdel(&line);
	if (!split[0] || !split[1] || split[2])
		return (ERROR);//free split and write lexical error
	if (ft_strcmp(split[0], cmp))
		return (ERROR);//free split and write lexical error
	*s = split[1];
	return (1);
}
