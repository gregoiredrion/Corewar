/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:14:17 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/13 21:55:11 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*type_to_str(int type)
{
	if (type == T_REG)
		return ("REGISTER");
	else if (type == T_DIR + T_LAB)
		return ("DIRECT_LABEL");
	else if (type == T_IND + T_LAB)
		return ("INDIRECT_LABEL");
	else if (type & T_DIR)
		return ("DIRECT");
	else if (type & T_IND)
		return ("INDIRECT");
	else if (type == T_LAB)
		return ("LABEL");
	else if (type == T_NAM)
		return ("COMMAND_NAME");
	else if (type == T_CMT)
		return ("COMMAND_COMMENT");
	else if (type == T_STR)
		return ("STRING");
	else if (type == T_INS)
		return ("INSTRUCTION");
	else if (type == T_SEP)
		return ("SEPARATOR");
	else if (type == T_NEW)
		return ("ENDLINE");
	else
		return ("END");
}

t_token		*syntax_newline(void)
{
	ft_printf("Syntax error - unexpected end of input (Perhaps you forgot to "
	"end with a newline ?)\n");
	return (NULL);
}

t_token		*syntax_error(t_token *token)
{
	if (token->type == T_NEW)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s\n", token->line,
		token->col, type_to_str(token->type));
	else if (token->type == T_EOF)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"(null)\"\n",
		token->line, token->col, type_to_str(token->type));
	else
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n",
		token->line, token->col, type_to_str(token->type), token->str);
	return (NULL);
}
