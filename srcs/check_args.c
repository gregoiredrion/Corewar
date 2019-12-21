/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:47:02 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 15:25:56 by wdeltenr         ###   ########.fr       */
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

static int	check_upper(t_cor *cor, char **args, char *raw)
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
				return (lexical_error(cor->line, get_column(raw, args[i])));//move
			j++;
		}
		i++;
	}
	return (OK);
}

static int	find_type(t_cor *cor, char *arg, char *raw, int type)
{
	if (arg[0] == 'r')
	{
		if (!check_format_arg(cor, arg, raw, REG_CODE))
			return (ERROR);
		if (!(type & T_REG))
			return (invalid_param(cor->op.name, ARG_TYPE));
	}
	else if (arg[0] == DIRECT_CHAR)
	{
		if (!check_format_arg(cor, arg, raw, DIR_CODE))
			return (ERROR);
		if (!(type & T_DIR))
			return (invalid_param(cor->op.name, ARG_TYPE));
	}
	else
	{
		if (!check_format_arg(cor, arg, raw, IND_CODE))
			return (ERROR);
		if (!(type & T_IND))
			return (invalid_param(cor->op.name, ARG_TYPE));
	}
	return (OK);
}

static int	check_types(t_cor *cor, char **args, char *raw)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (!find_type(cor, args[i], raw, cor->op.arg_type[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int			check_args(t_cor *cor, char **args, char *raw)
{
	if (!check_nb_args(cor->op.nb_arg, args))
		return (invalid_param(cor->op.name, NB_ARG_ERROR));
	if (check_upper(cor, args, raw))
		return (ERROR);
	if (!check_types(cor, args, raw))
		return (ERROR);
	return (OK);
}
