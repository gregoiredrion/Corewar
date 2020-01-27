/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_memory_pad.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 20:22:59 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/11 02:10:22 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		pad_put_hex(WINDOW *pad, unsigned char v, char connexion[])
{
	if (v >= 16)
	{
		if (pad_put_hex(pad, v / 16, connexion) == ERR)
			return (ERR);
		if (pad_put_hex(pad, v % 16, connexion) == ERR)
			return (ERR);
	}
	else
	{
		if (waddch(pad, connexion[v]) == ERR)
			return (ERR);
	}
	return (OK);
}

static int		pad_put_byte(WINDOW *pad, unsigned char v)
{
	if (v < 16)
	{
		if (waddch(pad, '0') == ERR)
			return (ERR);
	}
	return (pad_put_hex(pad, v, "0123456789abcdef"));
}

static int		pad_put_memory(WINDOW *pad, t_env env)
{
	int		line;
	int		col;

	line = 0;
	while (line < 64)
	{
		col = 0;
		while (col < 64)
		{
			wattron(pad, COLOR_PAIR(env.vm_ownership[64 * line + col]));
			if (pad_put_byte(pad, env.vm_memory[64 * line + col]) == ERR)
				return (ERR);
			wattroff(pad, COLOR_PAIR(env.vm_ownership[64 * line + col]));
			col++;
			if (col < 64)
			{
				if (waddch(pad, ' ') == ERR)
					return (ERR);
			}
		}
		line++;
		if (line < 64)
			wmove(pad, line + 1, 2);
	}
	return (OK);
}

static int		pad_put_processes(WINDOW *pad, t_env env)
{
	t_dbl_list	*list;
	t_process	*cur;
	int			line;
	int			col;

	list = env.first_process;
	while (list)
	{
		cur = (t_process*)list->content;
		line = cur->pc / 64;
		col = cur->pc % 64;
		wattron(pad, COLOR_PAIR(PROCESS_COLOR));
		wmove(pad, 1 + line, 2 + col * 2 + col);
		if (pad_put_byte(pad, env.vm_memory[cur->pc]) == ERR)
			return (ERR);
		wattroff(pad, COLOR_PAIR(PROCESS_COLOR));
		list = list->next;
	}
	return (OK);
}

int				mem_pad_refresh(t_env env)
{
	wmove(env.visu.mem_pad, 1, 2);
	if (pad_put_memory(env.visu.mem_pad, env) == ERR)
		return (ERR);
	if (pad_put_processes(env.visu.mem_pad, env) == ERR)
		return (ERR);
	return (OK);
}
