/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:38:32 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/29 14:20:39 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*type_to_str(int type)
{
	if (type == T_REG)
		return (ft_strdup("register"));
	else if (type == T_DIR)
		return (ft_strdup("direct"));
	else if (type == T_IND)
		return (ft_strdup("indirect"));
	else if (type == T_LAB)
		return (ft_strdup("label"));
	else if (type == T_CMD)
		return (ft_strdup("command_name"));
	else if (type == T_STR)
		return (ft_strdup("string"));
	else if (type == T_INS)
		return (ft_strdup("instruction"));
	else if (type == T_SEP)
		return (ft_strdup("separator"));
	else
		return (ft_strdup("endline"));
}

int		invalid_param(char *instr, int type, int param, size_t pos)
{
	char	*tmp;

param = 0; //Silence error . is param still needed 
	ft_printf("Invalid parameter \n");
	if (type == NB_ARG)
		ft_printf("count ");
	else
	{
		if (!(tmp = type_to_str(type)))
			return (MALLOC_ERROR);
		ft_printf("%d type %s ", pos, tmp);
		ft_strdel(&tmp);
	}
	ft_printf("for instruction %s\n", instr);
	return (ERROR);
}

int		lexical_error(size_t line, size_t col)
{
	ft_printf("Lexical error at [%d:%d]\n", line, col);
	return (ERROR);
}

int		syntax_error(t_token *token)
{
	char	*tmp;

	if (!(tmp = type_to_str(token->type)))
		return (MALLOC_ERROR);
	tmp = ft_str_to_upper(tmp);
	ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n", token->line, token->col, tmp, token->str);
	free(tmp);
	return (ERROR);
}

int		invalid_instr(t_token *token)
{
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n", token->line, token->col, token->str);
	return (ERROR);
}
