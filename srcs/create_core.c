/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:00:41 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/11 17:28:55 by gdrion           ###   ########.fr       */
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

int			create_core(char **argv, t_core *core)
{
	int		ret;

	if (!(core = malloc(sizeof(t_core))))
		return (MALLOC_ERROR);
	if (!(store_fd_flag(core, argv)))
		return (ERROR);//call usage and free
	ret = check_name_comment(core->fd, ".name ", &(core->name));
	if (ret == ERROR || ret == MALLOC_ERROR)
		return (ret);
	ret = check_name_comment(core->fd, ".comment ", &(core->comment));
	if (ret == ERROR || ret == MALLOC_ERROR)
		return (ret);
	core->carry = 0;
	core->size = 0;
	core->bytes = NULL;
	ft_printf("|NAME:| |%s|\n", core->name);
	ft_printf("|COMMENT:| |%s|\n", core->comment);
	return (1);
}
