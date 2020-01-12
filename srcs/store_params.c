/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:40:33 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/12 21:18:59 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	write_param(t_cor *cor, t_token *param, size_t nb_bytes, int *error)
{
	int 	output;

	output = 0;
	if (param->type & T_LAB)
		return (offsets(cor, param, nb_bytes));
	if (nb_bytes == 1)
		output = (char)ft_atoi(param->str + 1);
	else if (nb_bytes == 2)
	{
		if (param->type & T_DIR)
			output = (short)ft_atoi(param->str + 1);
		else
			output = (short)ft_atoi(param->str);
	}
	else
		output = ft_atoi(param->str + 1);
	if (write_prog(cor, output, nb_bytes, error) == -1)
		return (MALLOC_ERROR);
	return (OK);
}

t_token	*store_params(t_cor *cor, t_token *param, int *error)
{
	size_t	nb_bytes;

	while (!(param->type & (T_NEW | T_EOF)))
	{
		if (param->type & T_SEP)
			param = param->next;
		if (param->type & T_REG)
			nb_bytes = 1;
		if (param->type & T_DIR)
			nb_bytes = (cor->op.label_size == 1) ? 2 : 4;
		if (param->type & T_IND)
			nb_bytes = 2;
		if (write_param(cor, param, nb_bytes, error) == MALLOC_ERROR)
			return (NULL);
		param = param->next;
	}
	return (param);
}
