/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:43:49 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/13 17:00:46 by wdeltenr         ###   ########.fr       */
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

static void	write_file(t_cor *cor, int fd)
{
	write(fd, &cor->header, sizeof(cor->header));
	write(fd, cor->prog, cor->size);
}

char		*create_cor_file(t_cor *cor, int *error)
{
	int		fd;
	char	*name;

	if (!(name = file_name(cor->name)))
	{
		*error = MALLOC_ERROR;
		return (NULL);
	}
	if ((fd = open(name, O_CREAT | O_RDWR | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	{
		write(2, "Could not create .cor file\n", 27);
		return (NULL);
	}
	write_file(cor, fd);
	if (close(fd) == -1)
	{
		write(2, "Could not close .cor file\n", 26);
		return (NULL);
	}
	ft_printf("Writing output program to %s\n", name);
	ft_strdel(&name);
	return (name);
}
