/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_ldi_lldi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 00:28:26 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/11 00:28:28 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_1st_arg_lldi(t_env *env, int *index, t_process *process,\
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
		value = bytes_to_int(env->vm_memory, process->pc + value);
		*index = ((*index) + 2) % MEM_SIZE;
	}
	else
	{
		value = (int)(bytes_to_short(env->vm_memory, (*index)));
		*index = ((*index) + 2) % MEM_SIZE;
	}
	return (value);
}

static int	get_1st_arg(t_env *env, int *index, t_process *process,\
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
		value = (int)(bytes_to_short(env->vm_memory, (*index)));
		*index = ((*index) + 2) % MEM_SIZE;
	}
	return (value);
}

static int	get_2nd_arg(t_env *env, int *index, t_process *process,\
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
	else
	{
		value = (int)(bytes_to_short(env->vm_memory, (*index)));
		*index = ((*index) + 2) % MEM_SIZE;
	}
	return (value);
}

int			instr_lldi(t_env *env, t_process *process)
{
	int				arg[3];
	int				index;
	unsigned char	opc;
	t_bool			valid_operation;

	arg[0] = 0;
	arg[1] = 0;
	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	arg[0] = get_1st_arg_lldi(env, &index, process, &valid_operation);
	arg[1] = get_2nd_arg(env, &index, process, &valid_operation);
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation)
	{
		process->registries[env->vm_memory[index]] =\
		bytes_to_int(env->vm_memory, process->pc + arg[0] + arg[1]);
		process->carry = (process->registries[env->vm_memory[index]]\
		== 0) ? 1 : 0;
	}
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}

int			instr_ldi(t_env *env, t_process *process)
{
	int				arg[2];
	int				index;
	unsigned char	opc;
	t_bool			valid_operation;

	arg[0] = 0;
	arg[1] = 0;
	valid_operation = true;
	opc = env->vm_memory[(process->pc + 1) % MEM_SIZE];
	if (!is_opc_valid(g_op_tab[process->opcode], opc))
		valid_operation = false;
	index = (process->pc + 2) % MEM_SIZE;
	arg[0] = get_1st_arg(env, &index, process, &valid_operation);
	arg[1] = get_2nd_arg(env, &index, process, &valid_operation);
	if (env->vm_memory[index] == 0 || env->vm_memory[index] > 16)
		valid_operation = false;
	if (valid_operation)
		process->registries[env->vm_memory[index]] =\
		bytes_to_int(env->vm_memory, process->pc + ((arg[0] + arg[1])\
		% IDX_MOD));
	move_pc(process, true, opc, 0);
	return (SUCCESS);
}
