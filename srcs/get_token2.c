/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:00:37 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/12 01:29:09 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_indir_label(char *input, size_t *n)
{
	size_t	i;

	i = 1;
	if (separating_char(input[i]))
		return (ERROR);
	while (is_labelchar(input[i]))
		i++;
	*n = i;
	return (T_LAB | T_DIR);

}

int			get_indir(char *input, size_t *n)
{
	size_t	i;

	i = 0;
	if (input[i] == LABEL_CHAR)
		return (get_indir_label(input, n));
	if (input[i] == '-')
		i++;
	while (ft_isdigit(input[i]))
		i++;
	*n = i;
	if (i == 0 || !ft_isdigit(input[i - 1]))
		return (ERROR);
	return (T_IND);
}

int			get_reg(char *input, size_t *n)
{
	size_t	i;

	i = 1;
	while (ft_isdigit(input[i]))
		i++;
	*n = i;
	return (ft_islower(input[i]) ? 0 : T_REG);
}

int			get_instr(char *input, size_t *n)
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
