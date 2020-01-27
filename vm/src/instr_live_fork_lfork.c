/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_live_fork_lfork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:39:26 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/11 02:15:20 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		instr_lfork(t_env *env, t_process *process)
{
	short		dir_value;
	t_process	*new_process;
	t_dbl_list	*list_process;

	dir_value = bytes_to_short(env->vm_memory, (process->pc + 1) % MEM_SIZE);
	if (!(new_process = ft_memalloc(sizeof(t_process))))
		return (ALLOC_FAILURE);
	ft_memcpy(new_process, process, sizeof(t_process));
	move_pc(new_process, 0, 0, dir_value);
	new_process->opcode = 0;
	if (!(list_process = ft_dbllstnew(new_process, sizeof(t_process))))
	{
		free(new_process);
		return (ALLOC_FAILURE);
	}
	ft_dbllstadd(&(env->first_process), list_process);
	move_pc(process, 0, 0, 3);
	env->processes_running++;
	return (SUCCESS);
}

int		instr_fork(t_env *env, t_process *process)
{
	short		dir_value;
	t_process	*new_process;
	t_dbl_list	*list_process;

	dir_value = bytes_to_short(env->vm_memory, (process->pc + 1) % MEM_SIZE);
	if (!(new_process = ft_memalloc(sizeof(t_process))))
		return (ALLOC_FAILURE);
	ft_memcpy(new_process, process, sizeof(t_process));
	move_pc(new_process, 0, 0, dir_value % IDX_MOD);
	new_process->opcode = 0;
	if (!(list_process = ft_dbllstnew(new_process, sizeof(t_process))))
	{
		free(new_process);
		return (ALLOC_FAILURE);
	}
	ft_dbllstadd(&(env->first_process), list_process);
	move_pc(process, 0, 0, 3);
	env->processes_running++;
	return (SUCCESS);
}

int		instr_live(t_env *env, t_process *process)
{
	int i;
	int	dir_value;

	process->is_alive = true;
	env->nb_live_one_cycle_to_die++;
	dir_value = bytes_to_int(env->vm_memory, (process->pc + 1) % MEM_SIZE);
	i = 0;
	while (i < env->nchamps)
	{
		if (dir_value && env->champs[i].number == dir_value)
		{
			env->last_champ_alive = &(env->champs[i].header.prog_name[0]);
			env->last_champ_alive_nb = dir_value;
			if (!env->visu_on && env->aff_live_notif_enabled)
				ft_printf("a process says that Player %s is alive\n",\
				env->last_champ_alive);
		}
		i++;
	}
	move_pc(process, 0, 0, 5);
	return (SUCCESS);
}
