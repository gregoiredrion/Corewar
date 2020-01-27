/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:04:01 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/12 20:30:21 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	init_main_pad(t_env *env)
{
	if (!(env->visu.main_pad = newpad(68, 65 * 3 + 40 + 5)))
		return (ERR);
	nodelay(env->visu.main_pad, true);
	keypad(env->visu.main_pad, true);
	box(env->visu.main_pad, ACS_VLINE, ACS_HLINE);
	return (OK);
}

static int	init_memory_pad(t_env *env)
{
	if (!(env->visu.mem_pad = subpad(env->visu.main_pad, 66, 65 * 3, 1, 2)))
		return (ERR);
	nodelay(env->visu.mem_pad, true);
	keypad(env->visu.mem_pad, true);
	box(env->visu.mem_pad, ACS_VLINE, ACS_HLINE);
	return (OK);
}

static int	init_info_pad(t_env *env)
{
	if (!(env->visu.info_pad =
				subpad(env->visu.main_pad, 66, 40, 1, 65 * 3 + 3)))
		return (ERR);
	nodelay(env->visu.info_pad, true);
	keypad(env->visu.info_pad, true);
	box(env->visu.info_pad, ACS_VLINE, ACS_HLINE);
	return (OK);
}

static void	init_colors(void)
{
	init_pair(PROCESS_COLOR, COLOR_BLACK, COLOR_WHITE | 8);
	init_pair(NEUTRAL_COLOR, COLOR_BLACK | 8, COLOR_BLACK);
	init_pair(J1_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(J2_COLOR, COLOR_BLUE, COLOR_BLACK);
	init_pair(J3_COLOR, COLOR_GREEN, COLOR_BLACK);
	init_pair(J4_COLOR, COLOR_MAGENTA, COLOR_BLACK);
}

int			init_ncurses(t_env *env)
{
	initscr();
	start_color();
	use_default_colors();
	init_colors();
	cbreak();
	curs_set(0);
	if (init_main_pad(env) == ERR)
		return (ERR);
	if (init_memory_pad(env) == ERR)
	{
		delwin(env->visu.main_pad);
		return (ERR);
	}
	if (init_info_pad(env) == ERR)
	{
		delwin(env->visu.main_pad);
		delwin(env->visu.mem_pad);
		return (ERR);
	}
	env->visu_running = true;
	return (OK);
}
