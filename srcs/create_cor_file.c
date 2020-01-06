/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:43:49 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/06 19:44:32 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*file_name(char *name)
{
	char	*new;
	char	*tmp;
	size_t	len;

	if (!ft_strchr(name, '.'))
	{
		if (!(new = ft_strdup(".cor")))
			return (NULL);
	}
	else
	{
		tmp = ft_strrchr(name, '.');
		len = tmp - name;
		if (!(tmp = ft_strndup(name, len)))
			return (NULL);
		if (!(new = ft_strjoin(tmp, ".cor")))
			return (NULL);
		ft_strdel(&tmp);
	}
	return (new);
}

static void write_file(t_cor *cor, int fd)
{
	write(fd, &cor->header, sizeof(cor->header));
	write(fd, cor->prog, cor->size);
}

char		*create_cor_file(t_cor *cor)
{
	int		fd;
	char	*name;

	if (!(name = file_name(cor->name)))
		return (NULL);
	if (!(fd = open(name, O_CREAT, O_WRONLY)))
		return (NULL);
	write_file(cor, fd);
	return (name);
}
