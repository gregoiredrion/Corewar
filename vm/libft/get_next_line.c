/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:05:14 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 23:11:40 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*get_file(const int fd, t_list **list)
{
	t_list		*curr;
	t_filesaved	*elt;

	curr = *list;
	while (curr)
	{
		if (((t_filesaved*)curr->content)->fd == fd)
			return (curr);
		curr = curr->next;
	}
	if (!(elt = (t_filesaved*)malloc(sizeof(*elt))))
		return (NULL);
	elt->fd = fd;
	elt->remaining = NULL;
	if (!(curr = ft_lstnew(elt, sizeof(*elt))))
		return (NULL);
	free(elt);
	ft_lstadd(list, curr);
	return (curr);
}

static char			*update_file_state(t_filesaved *curr)
{
	char	*nwl;
	char	*t;
	char	*r;

	r = NULL;
	if (curr->remaining && !(r = ft_strdup(curr->remaining)))
		return (NULL);
	if (r && (nwl = ft_strchr(r, '\n')))
	{
		if (!(t = ft_strsub(r, 0, nwl - r)))
			return (NULL);
		ft_strdel(&(curr->remaining));
		if (!(curr->remaining = ft_strdup(nwl + 1)))
			return (NULL);
		ft_strdel(&r);
		return (t);
	}
	ft_strdel(&r);
	return (NULL);
}

static int			reading_loop(const int fd, char **line, t_filesaved *t)
{
	char	buf[BUFF_SIZE + 1];
	int		read_bytes;
	char	*tmp;

	tmp = NULL;
	while ((read_bytes = read(fd, buf, BUFF_SIZE)))
	{
		if (read_bytes < 0)
			return (ERROR);
		buf[read_bytes] = 0;
		if (t->remaining && !(tmp = ft_strdup(t->remaining)))
			return (ERROR);
		ft_strdel(&(t->remaining));
		if (!(t->remaining = ft_strforcecat(tmp, buf)))
			return (ERROR);
		ft_strdel(&tmp);
		if ((*line = update_file_state(t)))
			return (SUCCESS);
	}
	return (2);
}

static void			free_list_element(t_list **alst, t_list *to_delete)
{
	t_list	*t;
	t_list	*cursor;

	cursor = *alst;
	if (cursor == to_delete)
		*alst = cursor->next;
	else
	{
		while (cursor)
		{
			if (cursor->next == to_delete)
			{
				t = cursor;
				cursor = cursor->next;
				t->next = cursor->next;
				break ;
			}
			cursor = cursor->next;
		}
	}
	ft_strdel(&((t_filesaved*)cursor->content)->remaining);
	free(((t_filesaved*)cursor->content));
	free(cursor);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*curr_listitem;
	t_filesaved		*curr_item;
	int				rd;

	if (!line || fd < 0 || !(curr_listitem = get_file(fd, &list)))
		return (ERROR);
	curr_item = ((t_filesaved*)curr_listitem->content);
	if ((*line = update_file_state((curr_item))))
		return (SUCCESS);
	rd = reading_loop(fd, line, curr_item);
	if (rd != 2)
		return (rd);
	if (curr_item->remaining && *(curr_item->remaining))
	{
		if (!(*line = ft_strdup(curr_item->remaining)))
			return (ERROR);
		ft_strdel(&(curr_item->remaining));
		return (SUCCESS);
	}
	free_list_element(&list, curr_listitem);
	return (END_OF_FILE);
}
