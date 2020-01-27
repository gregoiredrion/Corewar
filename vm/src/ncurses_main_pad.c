/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_main_pad.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 02:22:09 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/12 20:34:45 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	handle_key(t_env *env)
{
	int		key;

	while ((key = wgetch(env->visu.main_pad)) == ERR)
	{
		;
	}
	if (key == 'q')
		env->visu_running = false;
	if (key == 'r' || key == KEY_RESIZE)
	{
		win_refresh(*env);
		handle_key(env);
	}
}

int		win_refresh(t_env env)
{
	if (mem_pad_refresh(env) == ERR)
		return (ERR);
	if (info_pad_refresh(env) == ERR)
		return (ERR);
	prefresh(env.visu.main_pad, 0, 0, 0, 0, LINES - 1, COLS - 1);
	return (OK);
}
