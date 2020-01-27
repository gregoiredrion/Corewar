/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_and_or_xor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:53:11 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/10 15:53:14 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_value2(t_env *env, int *index, t_process *process,\
t_bool *valid_operation)
{
	unsigned char	opc;
	int				value;

	value = 0;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (((opc >> 4) & 0x03) == REG_CODE)
	{
		if (env->vm_memory[*index] == 0 || env->vm_memory[*index] > 16)
			*valid_operation = false;
		else
			value = process->registries[env->vm_memory[*index]];
		*index = ((*index) + 1) % MEM_SIZE;
	}
	else if (((opc >> 4) & 0x03) == IND_CODE)
	{
		value = (int)(bytes_to_short(env->vm_memory, *index));
		value = bytes_to_int(env->vm_memory, process->pc + (value % IDX_MOD));
		*index = ((*index) + 2) % MEM_SIZE;
	}
	else
	{
		value = bytes_to_int(env->vm_memory, *index);
		*index = ((*index) + 4) % MEM_SIZE;
	}
	return (value);
}

static int	get_value1(t_env *env, int *index, t_process *process,\
t_bool *valid_operation)
{
	unsigned char	opc;
	int				value;

	value = 0;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (opc >> 6 == REG_CODE)
	{
		if (env->vm_memory[*index] == 0 || env->vm_memory[*index] > 16)
			*valid_operation = false;
		else
			value = process->registries[env->vm_memory[*index]];
		*index = ((*index) + 1) % MEM_SIZE;
	}
	else if (opc >> 6 == IND_CODE)
	{
		value = (int)(bytes_to_short(env->vm_memory, (*index)));
		value = bytes_to_int(env->vm_memory, process->pc + (value % IDX_MOD));
		*index = ((*index) + 2) % MEM_SIZE;
	}
	else
	{
		value = bytes_to_int(env->vm_memory, (*index));
		*index = ((*index) + 4) % MEM_SIZE;
	}
	return (value);
}

int			instr_xor(t_env *env, t_process *process)
{
	int				value1;
	int				value2;
	int				index;
	t_bool			valid_operation;
	unsigned char	opc;

	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	value1 = get_value1(env, &index, process, &valid_operation);
	value2 = get_value2(env, &index, process, &valid_operation);
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation == true)
	{
		process->registries[env->vm_memory[index]] = value1 ^ value2;
		process->carry = ((value1 ^ value2) == 0) ? 1 : 0;
	}
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}

int			instr_or(t_env *env, t_process *process)
{
	int				value1;
	int				value2;
	int				index;
	t_bool			valid_operation;
	unsigned char	opc;

	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	value1 = get_value1(env, &index, process, &valid_operation);
	value2 = get_value2(env, &index, process, &valid_operation);
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation == true)
	{
		process->registries[env->vm_memory[index]] = value1 | value2;
		process->carry = ((value1 | value2) == 0) ? 1 : 0;
	}
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}

int			instr_and(t_env *env, t_process *process)
{
	int				value1;
	int				value2;
	int				index;
	t_bool			valid_operation;
	unsigned char	opc;

	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	value1 = get_value1(env, &index, process, &valid_operation);
	value2 = get_value2(env, &index, process, &valid_operation);
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation == true)
	{
		process->registries[env->vm_memory[index]] = value1 & value2;
		process->carry = ((value1 & value2) == 0) ? 1 : 0;
	}
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}
