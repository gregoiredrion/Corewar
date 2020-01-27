/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:39:16 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/14 15:38:34 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		free_all(t_env *env, int ret)
{
	if (env->visu_on)
		free_pads(env);
	return (free_list_processes(env->first_process, ret));
}

void	free_pads(t_env *env)
{
	delwin(env->visu.mem_pad);
	delwin(env->visu.info_pad);
	delwin(env->visu.main_pad);
}

int		free_process(t_process *process, int ret)
{
	if (!process)
		return (ret);
	free(process);
	return (ret);
}

int		free_one_list_process(t_dbl_list *list_process, int ret)
{
	t_process *process;

	if (!list_process)
		return (ret);
	process = (t_process*)list_process->content;
	free_process(process, ret);
	free(list_process);
	return (ret);
}

int		free_list_processes(t_dbl_list *first_node, int ret)
{
	t_dbl_list *tmp;

	if (!first_node)
		return (ret);
	while (first_node)
	{
		tmp = first_node->next;
		free_one_list_process(first_node, ret);
		first_node = tmp;
	}
	return (ret);
}
