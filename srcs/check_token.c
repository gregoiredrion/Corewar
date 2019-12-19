/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:01:31 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 16:10:58 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_dir(char *input)
{
	if (!input[1] || ft_isalpha(input[1])
		|| (input[1] == LABEL_CHAR && !input[2]))
		return (ERROR);
	if (input[1] == '-' || input[1] == '+')
		if (!check_ind(&input[1]))
			return (ERROR);
	return (T_DIR);
}

int		check_cmd(char *input)
{
	if (!ft_strcmp(input, ".name") || !ft_strcmp(input, ".comment"))
		return (T_CMD);
	return (ERROR);
}

int		check_label(char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (!ft_strchr(LABEL_CHARS, input[i]))
			return (ERROR);
		i++;
	}
	return (T_LAB);
}

int		check_reg_instr(char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
		if (!ft_isalnum(input[i++]))
			return (ERROR);
	if (input[0] == 'r')
	{
		if (ft_atoi(&input[1]) > 99)
			return (T_INS);
		else
			return (T_REG);
	}
	return (T_INS);
}

int		check_ind(char *input)
{
	size_t	i;

	i = 0;
	if (input[0] == '-' || input[0] == '+')
		if (!input[1] || !ft_isdigit(input[i]))
			return (ERROR);
	return (T_DIR);
}
