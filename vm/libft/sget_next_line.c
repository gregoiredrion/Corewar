/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sget_net_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 23:07:18 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:07:54 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_new_line(char **rest, char **line)
{
	char	*tmp;
	char	*new_line;

	if (*rest && (new_line = ft_strchr(*rest, 10)))
	{
		if (!(*line = ft_strsub(*rest, 0, new_line - *rest)))
			return (0);
		tmp = ft_strdup(new_line + 1);
		ft_strdel(rest);
		*rest = tmp;
		return (1);
	}
	return (0);
}

static char	*strforcejoin(char **s1, char const *s2)
{
	char	*tmp;

	if (!(*s1))
		tmp = ft_strdup(s2);
	else
		tmp = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	*s1 = tmp;
	return (tmp);
}

int			sget_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*rest = NULL;
	ssize_t			read_bytes;

	if (fd < 0)
		return (-1);
	if (rest && has_new_line(&rest, line))
		return (1);
	while ((read_bytes = read(fd, buf, BUFF_SIZE)))
	{
		if (read_bytes < 0)
			return (-1);
		buf[read_bytes] = '\0';
		strforcejoin(&rest, buf);
		if (has_new_line(&rest, line))
			return (1);
	}
	if (rest && *rest != '\0')
	{
		*line = ft_strdup(rest);
		ft_strdel(&rest);
		return (1);
	}
	return (0);
}
