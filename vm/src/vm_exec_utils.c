/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:40:11 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/11 02:15:25 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool		is_opc_valid(t_op op, unsigned char opc)
{
	unsigned char	code;
	int				i;

	i = 3;
	while (i >= 0)
	{
		code = opc & 0x03;
		if (code == IND_CODE)
			code = 4;
		if (i >= op.nb_arg)
		{
			if (code)
				return (false);
		}
		else if (!(code & op.arg_types[i]))
			return (false);
		opc >>= 2;
		i--;
	}
	return (true);
}

/*
** DOES: kill process et reforme la liste chainee
** RETURN : la prochaine t_dbl_lst next du process killed. Peut etre NULL
*/

t_dbl_list	*kill_process(t_env *env, t_dbl_list *list_process)
{
	t_dbl_list *to_ret;

	if (list_process->prev)
		list_process->prev->next = list_process->next;
	if (list_process->next)
		list_process->next->prev = list_process->prev;
	if (env->first_process == list_process)
		env->first_process = list_process->next;
	to_ret = list_process->next;
	free_one_list_process(list_process, SUCCESS);
	env->processes_running--;
	return (to_ret);
}

/*
**	Deux grands cas: soit la fonction appelante veut move d un certain nombre
**  de steps, soit elle veut move a la prochaine instruction (sans deja
**  connaitre le nb de steps.
**
**	Si !there is opc, cela veut dire qu on prend juste steps
**  Si there is opc, il faut calculer les steps sur base de l opc.
*/

int			calculate_steps(char nb_args, t_bool dir_small, unsigned char opc)
{
	int				steps;
	unsigned char	code;
	char			shift;

	steps = 2;
	shift = 6;
	while (nb_args--)
	{
		code = (opc >> shift) & 0x03;
		if (code == REG_CODE)
			steps += 1;
		else if (code == DIR_CODE && !dir_small)
			steps += 4;
		else if (code == DIR_CODE || code == IND_CODE)
			steps += 2;
		shift -= 2;
	}
	return (steps);
}

void		move_pc(t_process *process, t_bool there_is_opc,\
unsigned char opc, int steps)
{
	t_bool			dir_small;
	char			nb_args;
	int				steps_tmp;

	steps_tmp = 0;
	nb_args = g_op_tab[process->opcode].nb_arg;
	dir_small = (g_op_tab[process->opcode]).is_dir_small;
	if (there_is_opc)
		steps = calculate_steps(nb_args, dir_small, opc);
	if (process->pc + steps < 0)
	{
		steps_tmp = (process->pc + steps) % MEM_SIZE;
		process->pc = (MEM_SIZE + steps_tmp) % MEM_SIZE;
	}
	else
		process->pc = (process->pc + steps) % MEM_SIZE;
}
