/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:39:34 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/29 14:28:58 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_format_reg(char *arg)
{
	size_t	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == '\t' || arg[i] == ' ')
			return (ERROR);
		else if (!ft_isdigit(arg[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

static int	check_format_dir(char *arg)
{
	size_t	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == '\t' || arg[i] == ' ')
		{
			if (arg[i - 1] == DIRECT_CHAR || arg[i - 1] == LABEL_CHAR)
				return (ERROR);
			else
				return (ERROR);
		}
		i++;
	}
	return (OK);
}

static int	check_format_ind(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\t' || arg[i] == ' ')
		{
			if (arg[i - 1] == '+' || arg[i - 1] == '-')
				return (ERROR);
			else
				return (ERROR);
		}
		i++;
	}
	return (OK);
}

//tableau de fonction?
int		check_format_arg(char *arg, int type)
{
	if (type == REG_CODE)
		return (check_format_reg(arg));
	else if (type == DIR_CODE)
		return (check_format_dir(arg));
	else
		return (check_format_ind(arg));
}
