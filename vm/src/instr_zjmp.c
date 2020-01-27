/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 17:49:22 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/12 17:49:26 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		instr_zjmp(t_env *env, t_process *process)
{
	short value;

	value = bytes_to_short(env->vm_memory, process->pc + 1);
	if (process->carry)
		move_pc(process, 0, 0, value % IDX_MOD);
	else
		move_pc(process, 0, 0, 3);
	return (SUCCESS);
}
