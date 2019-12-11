/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:00:41 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/11 16:14:10 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	store_fd_flag(t_core *core, char **argv)
{
	if (argv[2])
	{
		if ((ft_strcmp("a", argv[1])))
			return (0);
		core->flag = 1;
		if ((core->fd = open(argv[2], O_RDONLY)) == -1)
			return (0);
	}
	else
	{
		core->flag = 0;
		if ((core->fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
	}
	return (1);
}

t_core		*create_core(char **argv)
{
	t_core	*core;

	if (!(core = malloc(sizeof(t_core))))
		return (NULL);
	if (!(store_fd_flag(core, argv)))
		return (NULL);//call usage and free
	if (!(core->name = check_name_comment(core->fd, ".name ")))
		return (NULL);
	if (!(core->comment = check_name_comment(core->fd, ".comment ")))
		return (NULL);
	core->carry = 0;
	core->size = 0;
	core->bytes = NULL;
	ft_printf("|NAME:| |%s|\n", core->name);
	ft_printf("|COMMENT:| |%s|\n", core->comment);
	return (core);
}
