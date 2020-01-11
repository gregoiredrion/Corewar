/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:00:37 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/11 01:28:49 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_indir(char *input, size_t *n)
{
	size_t	i;
	int		type;

	type = T_IND;
	i = 0;
	if (input[i] == LABEL_CHAR)
		type = type | T_LAB;
	while (ft_isdigit(input[i]))
		i++;
	if (ft_islower(input[i]))
	{
		while (ft_islower(input[i]))
			i++;
		type = T_INS;
	}
	*n = i;
	return (type);
}

int		get_reg(char *input, size_t *n)
{
	size_t	i;

	i = 1;
	while (ft_isdigit(input[i]))
		i++;
	*n = i;
	return (ft_islower(input[i]) ? 0 : T_REG);
}

int		get_instr(char *input, size_t *n)
{
	size_t	i;
	size_t	j;
	int		type;

	type = T_INS;
	i = 0;
	j = 0;
	while (ft_islower(input[i]) || ft_isdigit(input[i]) || input[i] == '_')
		i++;
	if (input[i] == LABEL_CHAR)
	{
		i++;
		type = T_LAB;
	}
	*n = i;
//	printf("Type in instr equals %d\n", type);
	return (type);
}
