/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:40:31 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 17:06:39 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		tokenisation(char *input)
{
	if (input[0] == '"')
		return (T_STR);// lexical error possible?
	else if (input[0] == SEPARATOR_CHAR)
		return (T_SEP);
	else if (upper(input))
		return (ERROR);
	else if (input[0] == '.')
		return (check_cmd(input));
	else if (input[0] == DIRECT_CHAR)
		return (check_dir(input));
	else if (ft_strchr(input, LABEL_CHAR) && input[0] != LABEL_CHAR)//bad
		return (check_label(input));
	else if (ft_isalpha(input[0]))
		return (check_reg_instr(input));
	else
		return (check_ind(input, 0));
}
