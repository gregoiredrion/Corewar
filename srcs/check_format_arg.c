/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:39:34 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/17 19:49:39 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_format_reg(t_cor *cor, char *arg, char *raw)
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

static int	check_format_dir(t_cor *cor, char *arg, char *raw)
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

static int	check_format_ind(t_cor *cor, char *arg, char *raw)
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
int		check_format_arg(t_cor *cor, char *arg, char *raw, int type)
{
	if (type == REG_CODE)
		return (check_format_reg(cor, arg, raw));
	else if (type == DIR_CODE)
		return (check_format_dir(cor, arg, raw));
	else
		return (check_format_ind(cor, arg, raw));
}
