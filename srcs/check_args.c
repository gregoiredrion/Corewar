/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:47:02 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/29 14:33:26 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_nb_args(size_t nb_arg, char **args)
{
	size_t		i;

	i = 0;
	while (args[i])
		i++;
	if (i != nb_arg)
		return (ERROR);
	return (OK);
}

static int	check_upper(char **args)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (args[i])
	{
		while (args[i][j])
		{
			if (ft_isupper(args[i][j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}

static int	find_type(char *arg, int type)
{
	if (arg[0] == 'r')
	{
		if (!check_format_arg(arg, REG_CODE))
			return (ERROR);
		if (!(type & T_REG))
			return (ERROR);
	}
	else if (arg[0] == DIRECT_CHAR)
	{
		if (!check_format_arg(arg, DIR_CODE))
			return (ERROR);
		if (!(type & T_DIR))
			return (ERROR);
	}
	else
	{
		if (!check_format_arg(arg, IND_CODE))
			return (ERROR);
		if (!(type & T_IND))
			return (ERROR);
	}
	return (OK);
}

static int	check_types(t_cor *cor, char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (!find_type(args[i], cor->op.arg_type[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int			check_args(t_cor *cor, char **args)
{
	if (!check_nb_args(cor->op.nb_arg, args))
		return (ERROR);
	if (check_upper(args))
		return (ERROR);
	if (!check_types(cor, args))
		return (ERROR);
	return (OK);
}
