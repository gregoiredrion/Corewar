/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:45:35 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/09 19:18:34 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char			total_arg(t_arg_type arg_type[], size_t nb_arg)
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

static int	check_possibilities(t_arg_type arg_type[], size_t nb_arg)
{
	size_t	i;

	i = 0;
	while (i < nb_arg)
	{
		if (arg_type[i] & (arg_type[i] - 1))
			return (true);
			i++;
	}
	return (false);
}

static int	write_param(t_cor *cor, t_token *param, size_t nb_bytes)
{
	int 	output;

	output = 0;
	if (param->type & T_LAB)
		if (offsets(cor, param, nb_bytes) == MALLOC_ERROR)
			return (MALLOC_ERROR);
	if (nb_bytes == 1)
		write_prog(cor, (char)ft_atoi(param->str + 1), 1);
	else if (nb_bytes == 2)
	{
		if (param->type & T_DIR)
			output = (short)ft_atoi(param->str + 1);
		else
			output = (short)ft_atoi(param->str);
		write_prog(cor, (short)output, 2);
	}
	else
	{
		output = ft_atoi(param->str + 1);
		write_prog(cor, output, 4);
	}
	return (OK);
}

static t_token	*store_params(t_cor *cor, t_token *param)
{
	size_t	nb_bytes;

	while (param && param->type != T_NEW)
	{
		if (param->type & T_SEP)
			param = param->next;
		if (param->type & T_REG)
			nb_bytes = 1;
		if (param->type & T_DIR)
			nb_bytes = (cor->op.label_size == 1) ? 2 : 4;
		if (param->type & T_IND)
			nb_bytes = 2;
		if (write_param(cor, param, nb_bytes) == MALLOC_ERROR)
			return (NULL);
	}
	return (param);
}

t_token		*store_instruction(t_cor *cor, t_token *token)
{

	if (check_possibilities(cor->op.arg_type, cor->op.nb_arg))
		write_prog(cor, total_arg(cor->op.arg_type, cor->op.nb_arg), 1);
	return (store_params(cor, token->next));
}
