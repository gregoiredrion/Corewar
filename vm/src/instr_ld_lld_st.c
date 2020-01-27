/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_ld_lld_st.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:11:58 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/11 01:09:02 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			instr_st(t_env *env, t_process *process)
{
	int				index;
	unsigned char	opc;
	t_bool			valid_operation;
	int				reg_index;

	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	if ((reg_index = env->vm_memory[index]) == 0 || reg_index > 16)
		valid_operation = false;
	index = (index + 1) % MEM_SIZE;
	if (((opc >> 4) & 0x03) == IND_CODE && valid_operation)
		put_int_in_vm(env, process->pc + (bytes_to_short(env->vm_memory,\
		index) % IDX_MOD), process->registries[reg_index], process);
	else if (((opc >> 4) & 0x03) == REG_CODE && valid_operation)
	{
		if (env->vm_memory[index] > 0 && env->vm_memory[index] <= 16)
			process->registries[env->vm_memory[index]] =\
			process->registries[reg_index];
	}
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}

static int	lld_get_first_arg(t_env *env, t_process *process,\
unsigned char opc, int *index)
{
	int		value;
	short	sh_value;

	if ((opc >> 6) == DIR_CODE)
	{
		value = bytes_to_int(env->vm_memory, *index);
		*index = ((*index) + 4) % MEM_SIZE;
		return (value);
	}
	else
	{
		value = (int)bytes_to_short(env->vm_memory, *index);
		value = (process->pc + value) % MEM_SIZE;
		sh_value = bytes_to_short(env->vm_memory, value);
		*index = ((*index) + 2) % MEM_SIZE;
		return ((int)sh_value);
	}
}

int			instr_lld(t_env *env, t_process *process)
{
	t_bool			valid_operation;
	int				value_to_stock;
	int				index;
	unsigned char	opc;

	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	value_to_stock = lld_get_first_arg(env, process, opc, &index);
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation == true)
	{
		process->registries[env->vm_memory[index]] = value_to_stock;
		process->carry = (value_to_stock == 0) ? 1 : 0;
	}
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}

static int	ld_get_first_arg(t_env *env, t_process *process,\
unsigned char opc, int *index)
{
	int value;

	if ((opc >> 6) == DIR_CODE)
	{
		value = bytes_to_int(env->vm_memory, *index);
		*index = ((*index) + 4) % MEM_SIZE;
	}
	else
	{
		value = (int)bytes_to_short(env->vm_memory, *index);
		value = (process->pc + (value % IDX_MOD)) % MEM_SIZE;
		value = bytes_to_int(env->vm_memory, value);
		*index = ((*index) + 2) % MEM_SIZE;
	}
	return (value);
}

int			instr_ld(t_env *env, t_process *process)
{
	t_bool			valid_operation;
	int				value_to_stock;
	int				index;
	unsigned char	opc;

	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	value_to_stock = ld_get_first_arg(env, process, opc, &index);
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation == true)
	{
		process->registries[env->vm_memory[index]] = value_to_stock;
		process->carry = (value_to_stock == 0) ? 1 : 0;
	}
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}
