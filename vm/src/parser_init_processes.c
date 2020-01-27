/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:47:40 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/10 21:51:17 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				init_first_processes(t_env *env)
{
	t_process	*process;
	t_dbl_list	*process_list;
	int			i;

	i = 0;
	while (i < env->nchamps)
	{
		if (!(process = ft_memalloc(sizeof(t_process))))
			return (ALLOC_FAILURE);
		process->pc = env->champs[i].starting_address;
		process->registries[1] = env->champs[i].number;
		process->owner = i + 1;
		if (!(process_list = ft_dbllstnew(process, sizeof(t_process))))
		{
			free(process);
			return (ALLOC_FAILURE);
		}
		ft_dbllstadd(&(env->first_process), process_list);
		i++;
	}
	env->processes_running = env->nchamps;
	return (SUCCESS);
}
