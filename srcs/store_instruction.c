/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:41:23 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/11 01:09:57 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	op_tab[];

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

static int						find_instruction(t_cor *cor, t_token *token)
{
	size_t	i;

	i = 0;
  cor->pos = cor->size;
	while (op_tab[i].name)
	{
		if (!ft_strcmp(token->str, op_tab[i].name))
			break ;
		i++;
	}
	if (!op_tab[i].name)
		return (ERROR);
	cor->op = op_tab[i];
	write_prog(cor, (char)cor->op.opcode, 1);
	return (OK);
}

t_token   *store_instruction(t_cor *cor, t_token *token)
{
  size_t      i;

  i = 0;
  if (!find_instruction(cor, token))
    return (ERROR);//unknowm instr
  while (i < cor->op.nb_arg)
  {
    cor->tab[i] = cor->op.arg_type[i];
    i++;
  }
  if (!instr_params(cor, token->next, cor->op.nb_arg))
    return (ERROR);
  if (cor->op.code_octet)
  	write_prog(cor, (char)total_arg(cor->tab, cor->op.nb_arg), 1);
  return (store_params(cor, token->next));
}
