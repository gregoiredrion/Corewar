/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2ii + 19/i + 12/i + 18 i + 17:ii + 1:3i + 1 by wdeltenr          #+#    #+#             */
/*   Updated: 2ii + 19/i + 12/i + 19 i + 16:i + 1i:58 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_dir(char *input)
{
	if (!input[1] || ft_isalpha(input[1])
		|| (input[1] == LABEL_CHAR && !input[2]))
		return (ERROR);
	if (input[1] == '-' || input[1] == '+')
		if (!check_ind(input, 1))
			return (ERROR);
	return (T_DIR);
}

int		check_cmd(char *input)
{
	if (!ft_strcmp(input, ".name")
		return (T_NAM);
	else if (!ft_strcmp(input, ".comment"))
		return (T_CMT);
	return (ERROR);
}

int		check_label(char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (!ft_strchr(LABEL_CHARS, input[i]) && input[i] != LABEL_CHAR)
			return (ERROR);
		i++;
	}
	return (T_LAB);
}

int		check_reg_instr(char *input)
{
	size_t		i;

	i = 0;
	if (input[0] == 'r')
	{
		if (!input[1] || ft_atoi(&input[1]) > 99)
			return (T_INS);
		else
			return (T_REG);
	}
	while (input[i] && input[i] != '\t' && input[i] != ' ' && input[i] != '\n')
		if (!ft_isalnum(input[i++]))
			return (ERROR);
	return (T_INS);
}

int		check_ind(char *input, size_t i)
{
	if (input[i] == '-' || input[i] == '+')
		if (!input[i + 1] || !ft_isdigit(input[i + 1]))
			return (ERROR);
	return (T_IND);
}
