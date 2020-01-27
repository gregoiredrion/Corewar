/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 23:48:26 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/12 02:59:53 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	apply_changes(t_env *env, t_process *p, int index, int val[2])
{
	p->registries[env->vm_memory[index]] =
		p->registries[val[1]] + p->registries[val[0]];
	p->carry = (p->registries[env->vm_memory[index]] == 0) ? 1 : 0;
}

int			instr_add(t_env *env, t_process *p)
{
	int				index;
	unsigned int	opc;
	t_bool			valid_operation;
	int				val[2];

	valid_operation = true;
	opc = env->vm_memory[(p->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[p->opcode], opc))
		valid_operation = false;
	index = (p->pc + 2) % MEM_SIZE;
	if ((val[0] = env->vm_memory[index]) == 0 || val[0] > 16)
		valid_operation = false;
	index = (index + 1) % MEM_SIZE;
	if ((val[1] = env->vm_memory[index]) == 0 || val[1] > 16)
		valid_operation = false;
	index = (index + 1) % MEM_SIZE;
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation)
		apply_changes(env, p, index, val);
	move_pc(p, true, opc, 0);
	return (SUCCESS);
}
