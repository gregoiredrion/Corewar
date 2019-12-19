/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:38:32 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 15:45:20 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		invalid_param(char *instr, int type)
{
	type = 0;
	instr = NULL;

	ft_printf("invalid param\n");
	return (ERROR);
}

int		lexical_error(size_t line, size_t col)
{
	line = 0;
	col = 0;

	ft_printf("lexical error\n");
	return (ERROR);
}

size_t	get_column(char *raw, char *to_find)
{
	size_t		dummy = 0;
	raw = NULL;
	to_find = NULL;

	return (dummy);
}

int		syntax_error(size_t line, size_t col)
{
	line = 0;
	col = 0;

	ft_printf("syntax error\n");
	return (ERROR);
}

int		invalid_instr(char *instr, size_t line, size_t col)
{
	line = 0;
	col = 0;
	instr = NULL;

	ft_printf("invalid instr\n");
	return (ERROR);
}
