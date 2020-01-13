/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:38:32 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/13 21:21:34 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*type_to_str(int type)
{
	if (type == T_REG)
		return ("register");
	else if (type & T_DIR)
		return ("direct");
	else
		return ("indirect");
}

int			invalid_param(char *instr, int error, int type, size_t pos)
{
	ft_printf("Invalid parameter ");
	if (error == NB_ARG)
		ft_printf("count ");
	else
		ft_printf("%d type %s ", pos, type_to_str(type));
	ft_printf("for instruction %s\n", instr);
	return (ERROR);
}

int			lexical_error(size_t line, size_t col, char *token_string)
{
	ft_strdel(&token_string);
	ft_printf("Lexical error at [%d:%d]\n", line, col);
	return (ERROR);
}

t_token		*invalid_instr(t_token *token)
{
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] INSTRUCTION"
	" \"%s\"\n", token->line, token->col, token->str);
	return (NULL);
}
