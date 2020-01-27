/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:52:45 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/12 20:26:57 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <errno.h>

static void	init_env(t_env *env)
{
	ft_bzero(env, sizeof(*env));
	env->dump = NO_DUMP;
}

static void	init_vm(t_env *env)
{
	int		i;
	int		spacing;

	i = 0;
	spacing = MEM_SIZE / env->nchamps;
	ft_memset(&env->vm_ownership[0], NEUTRAL_COLOR, MEM_SIZE);
	while (i < env->nchamps)
	{
		env->champs[i].starting_address = i * spacing;
		ft_memset(&env->vm_ownership[i * spacing], i + 1,
			env->champs[i].header.prog_size);
		ft_memcpy(&env->vm_memory[i * spacing], &env->champs[i].prog[0],
			env->champs[i].header.prog_size);
		i++;
	}
}

static int	initialize(t_env *env, int argc, char **argv)
{
	int		ret;

	if (argc < 2)
	{
		print_usage();
		return (FAILURE);
	}
	init_env(env);
	if ((ret = handle_args(++argv, env)) != SUCCESS)
		return (FAILURE);
	init_vm(env);
	if (env->visu_on)
	{
		if (init_ncurses(env) == ERR)
			return (FAILURE);
	}
	else
		print_intro(env);
	return (SUCCESS);
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		ret;

	if (initialize(&env, argc, argv) == FAILURE)
		return (EXIT_FAILURE);
	if (init_first_processes(&env) == ALLOC_FAILURE)
		return (free_all(&env, ALLOC_FAILURE));
	if ((ret = vm_exec(&env)) == ALLOC_FAILURE)
		return (free_all(&env, ALLOC_FAILURE));
	if (!env.visu_on)
		print_conclusion(ret, env);
	free_all(&env, SUCCESS);
	if (env.visu_on)
		endwin();
	return (EXIT_SUCCESS);
}
