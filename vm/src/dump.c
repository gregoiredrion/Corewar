/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:42:40 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/10 22:17:10 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_hex(unsigned char v, char connexion[])
{
	if (v >= 16)
	{
		put_hex(v / 16, connexion);
		put_hex(v % 16, connexion);
	}
	else
		ft_putchar(connexion[v]);
}

static void	put_hex_byte(unsigned char v)
{
	if (v < 16)
		ft_putchar('0');
	put_hex(v, "0123456789abcdef");
}

static void	put_hex_line(unsigned char *buffer, int line_size)
{
	int		i;

	i = 0;
	while (i < line_size)
	{
		put_hex_byte((unsigned char)buffer[i]);
		i++;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

void		dump_buffer(unsigned char *buffer, int size)
{
	int		i;
	int		nb_lines;

	i = 0;
	nb_lines = size / 64;
	while (i < nb_lines)
	{
		put_hex_line(buffer, 64);
		buffer += 64;
		i++;
	}
	put_hex_line(buffer, size % 64);
}

void		dump_memory(t_env env)
{
	int		i;

	i = 0;
	while (i < 64)
	{
		ft_printf("0x%04x : ", i * 64);
		put_hex_line(&env.vm_memory[64 * i], 64);
		i++;
	}
}
