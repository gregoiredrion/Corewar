/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:11:58 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/09 23:12:02 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		instr_aff(t_env *env, t_process *process)
{
	int				index;
	unsigned char	opc;
	t_bool			valid_operation;
	char			to_print;

	valid_operation = true;
	to_print = 0;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation == true)
		to_print = (process->registries[env->vm_memory[index]] % 256);
	if (valid_operation && env->aff_live_notif_enabled && !env->visu_on)
		ft_putchar(to_print);
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}
