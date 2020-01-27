/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_info_pad.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:33:53 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/13 00:52:46 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_last_player_alive_index(int last_player_alive_nb, t_env env)
{
	int		i;

	i = 0;
	while (i < env.nchamps)
	{
		if (env.champs[i].number == last_player_alive_nb)
			return (i);
		i++;
	}
	return (-1);
}

static void	print_info(t_env env, t_print_setup *setup, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	wmove(env.visu.info_pad, setup->line, setup->col);
	if (vwprintw(env.visu.info_pad, format, args) != ERR)
		setup->line += setup->jump;
	va_end(args);
}

static void	print_player_name(t_env env, char *label, t_print_setup *setup,
		int index)
{
	int	tmp;

	setup->jump = 0;
	print_info(env, setup, label);
	setup->col = (int)ft_strlen(label) + setup->col;
	tmp = setup->col + ft_strlen(env.champs[index].header.prog_name);
	if (index == -1)
	{
		setup->jump = 1;
		print_info(env, setup, "None");
	}
	else
	{
		setup->jump = (tmp / 40) + ((tmp % 40 != 0) ? 1 : 0);
		wattron(env.visu.info_pad, COLOR_PAIR(index + 1));
		print_info(env, setup, "%s", env.champs[index].header.prog_name);
		wattroff(env.visu.info_pad, COLOR_PAIR(index + 1));
	}
}

static void	print_players(t_env env, t_print_setup *setup)
{
	int		i;

	i = 0;
	setup->col = (INFO_PAD_COLS - ft_strlen("Players")) / 2;
	setup->jump = 2;
	print_info(env, setup, "Players");
	while (i < env.nchamps)
	{
		setup->col = 2;
		setup->jump = 1;
		print_info(env, setup, "Player[%d]", i + 1);
		setup->col = 3;
		print_player_name(env, "Name : ", setup, i);
		setup->col = 3;
		setup->jump = 0;
		print_info(env, setup, "Number : ");
		setup->col = (int)ft_strlen("Number : ") + setup->col;
		setup->jump = 2;
		print_info(env, setup, "%d", env.champs[i].number);
		i++;
	}
}

int			info_pad_refresh(t_env env)
{
	t_print_setup	setup;

	wclear(env.visu.info_pad);
	setup.line = 2;
	setup.col = (INFO_PAD_COLS - ft_strlen("Informations")) / 2;
	setup.jump = 2;
	print_info(env, &setup, "Informations");
	setup.jump = 1;
	setup.col = 2;
	print_info(env, &setup, "Cycle : %lu", env.current_cycle);
	print_info(env, &setup, "Max cycle : %d", env.max_cycles);
	print_info(env, &setup, "Nb live one cycle to die : %d",\
	env.nb_live_one_cycle_to_die);
	print_info(env, &setup, "Cycles to die : %d", env.cycles_to_die);
	print_info(env, &setup, "Checks left : %d", env.checks_left);
	print_info(env, &setup, "Processes running : %d", env.processes_running);
	setup.jump = 2;
	print_player_name(env, "Last alive : ", &setup,
			get_last_player_alive_index(env.last_champ_alive_nb, env));
	setup.line++;
	print_players(env, &setup);
	return (OK);
}
