/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:35:31 by agilmet           #+#    #+#             */
/*   Updated: 2020/01/12 19:35:33 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_conclusion(int ret, t_env env)
{
	if (ret == DUMP)
		dump_memory(env);
	else if (env.last_champ_alive)
	{
		ft_printf("\nThe player %d, \"%s\" has won !\n",
				env.last_champ_alive_nb,
				env.last_champ_alive);
	}
	else
		ft_printf("No winner.\n");
}

void		print_intro(t_env *env)
{
	int	i;

	i = 0;
	ft_printf("Introducing Players...\n");
	while (i < env->nchamps)
	{
		ft_printf("Player %d, \"%s\", weighing %d bytes, (\"%s\")\n",\
		env->champs[i].number, env->champs[i].header.prog_name,\
		env->champs[i].header.prog_size, env->champs[i].header.comment);
		i++;
	}
}

void		print_usage(void)
{
	ft_printf("Usage: ./corewar [-d N] [-a] [[-n N] champion1.cor] ...\n");
	ft_printf("      -a   : Prints output from \"aff\"\n");
	ft_printf("             Prints when champion is said to be alive\n");
	ft_printf("      -n N : Set nbr N for a champion (Default is -1, -2,..)\n");
	ft_printf("      -d N : Dumps Memory after N cycles then Exits\n");
	ft_printf("      !Up to 4 champions allowed!\n");
}
