/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 00:23:01 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/11 02:17:51 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	check_if_number_free(int number, t_env env)
{
	int		i;

	i = 0;
	while (i < env.nchamps)
	{
		if (number == env.champs[i].number)
			return (false);
		i++;
	}
	return (true);
}

int		get_default_nb(t_env env)
{
	int		def;

	def = -1;
	while (!check_if_number_free(def, env))
		def--;
	return (def);
}

void	set_arbitrary_champion_number(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nchamps)
	{
		if (env->champs[i].number == 0)
			env->champs[i].number = get_default_nb(*env);
		i++;
	}
}

void	sort_inv_by_champion_number(t_env *env)
{
	int		i;
	int		j;
	t_champ	tmp;

	i = 0;
	j = 1;
	while (i < env->nchamps)
	{
		while (j < env->nchamps)
		{
			if (env->champs[j].number > env->champs[i].number)
			{
				tmp = env->champs[i];
				env->champs[i] = env->champs[j];
				env->champs[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
