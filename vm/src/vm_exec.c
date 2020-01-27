/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:54:53 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/13 00:45:49 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	(*g_instr[17])(t_env *env, t_process *process) =
{
	NULL, instr_live, instr_ld, instr_st, instr_add, instr_sub, instr_and,\
	instr_or, instr_xor, instr_zjmp, instr_ldi, instr_sti, instr_fork,\
	instr_lld, instr_lldi, instr_lfork, instr_aff
};

static int		save_opcode(unsigned char vm_memory[MEM_SIZE],\
t_process *process)
{
	unsigned char	opcode;

	opcode = vm_memory[process->pc];
	if (opcode > 16 || opcode == 0)
		return (FAILURE);
	process->opcode = opcode;
	process->cycle_counter = g_op_tab[opcode].nb_cycles;
	return (SUCCESS);
}

static int		exec_process(t_env *env, t_process *process)
{
	if (process->opcode == 0)
	{
		if (save_opcode(env->vm_memory, process) == FAILURE)
			move_pc(process, 0, 0, 1);
		else
			process->cycle_counter--;
	}
	else if (process->cycle_counter == 1)
	{
		if (g_instr[process->opcode](env, process) == ALLOC_FAILURE)
			return (ALLOC_FAILURE);
		process->opcode = 0;
	}
	else
		process->cycle_counter--;
	return (SUCCESS);
}

static int		one_cycle_processes(t_env *env)
{
	t_dbl_list	*curr_list_process;
	t_process	*curr_process;

	curr_list_process = env->first_process;
	while (curr_list_process)
	{
		curr_process = (t_process*)curr_list_process->content;
		if (exec_process(env, curr_process) == ALLOC_FAILURE)
			return (ALLOC_FAILURE);
		if (!env->cycles_to_die && !curr_process->is_alive)
			curr_list_process = kill_process(env, curr_list_process);
		else
		{
			if (!env->cycles_to_die)
				curr_process->is_alive = 0;
			curr_list_process = curr_list_process->next;
		}
	}
	return (SUCCESS);
}

static int		exec_processes(t_env *env)
{
	env->cycles_to_die = env->max_cycles;
	while (env->first_process && env->cycles_to_die &&\
	(!env->visu_on || env->visu_running))
	{
		if (env->visu_on)
		{
			win_refresh(*env);
			handle_key(env);
		}
		env->cycles_to_die--;
		if (one_cycle_processes(env) == ALLOC_FAILURE)
			return (ALLOC_FAILURE);
		if (env->dump != NO_DUMP && --env->dump == 0)
			return (DUMP);
		env->current_cycle++;
	}
	return (SUCCESS);
}

int				vm_exec(t_env *env)
{
	int		ret;

	env->max_cycles = CYCLE_TO_DIE;
	env->checks_left = MAX_CHECKS;
	while (env->max_cycles > 0)
	{
		ret = exec_processes(env);
		if (ret == ALLOC_FAILURE || ret == DUMP)
			return (ret);
		if (!env->first_process)
			return (SUCCESS);
		if (env->nb_live_one_cycle_to_die >= NBR_LIVE || env->checks_left == 1)
		{
			env->checks_left = MAX_CHECKS;
			env->max_cycles -= CYCLE_DELTA;
		}
		else
			env->checks_left--;
		env->nb_live_one_cycle_to_die = 0;
	}
	return (SUCCESS);
}
