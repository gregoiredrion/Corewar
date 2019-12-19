/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:40:31 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 15:32:46 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char			total_arg(size_t nb_arg, t_arg_type *arg_type)
{
	char	tot;
	size_t	i;

	tot = 0;
	i = 0;
	while (i < 3)
	{
		if (i < nb_arg)
			tot += arg_type[i];
		tot <<= 2;
		i++;
	}
	return (tot);
}

static int			arg_type(char *arg)
{
	if (arg[0] == 'r')
		return (T_REG);
	else if (arg[0] == DIRECT_CHAR)
		return (T_DIR);
	else
		return (T_IND);
}

static void		set_type_params(t_op op, char **params, t_arg_type types[])
{
	size_t		i;

	i = 0;
	while (i < op.nb_arg)
	{
		types[i] = arg_type(params[i]);
		i++;
	}
}

//to do put arg instead of params
int					store_params(t_cor *cor, char *args, char *raw)
{
	char		**split;
	t_arg_type	types[3];
	size_t		i;

	i = 0;
	if (!(split = ft_strsplit(args, ',')))
		return (MALLOC_ERROR);
	while (split[i])
	{
		if (!(split[i] = ft_strtrim(split[i])))
			return (MALLOC_ERROR);
		i++;
	}
//	if (!check_args(cor, split, raw))
//		return (ERROR);
	raw = NULL; //
	set_type_params(cor->op, split, types);
	if (cor->op.nb_arg != 1)//uniquement ceux a 2+ ou ceux plusieurs poss?
		cor->program[cor->size++] = total_arg(cor->op.nb_arg, types);
	return (OK);
}
