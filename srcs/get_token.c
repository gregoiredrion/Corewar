/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:25:25 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/13 21:02:34 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		get_str(char *input, size_t *n)
{
	size_t		i;

	i = 1;
	while (input[i] && input[i] != '"')
		i++;
	*n = i;
	if (!input[i])
		return (T_EOF);
	return (T_STR);
}

static int		get_cmd(char *input, size_t *n)
{
	size_t	i;

	i = 1;
	while (input[i] && ft_islower(input[i]))
		i++;
	*n = i;
	return (T_NAM | T_CMT);
}

static int		get_dir_label(char *input, size_t *n)
{
	size_t	i;

	i = 2;
	while (is_labelchar(input[i]))
		i++;
	if (i == 2)
		return (ERROR);
	*n = i;
	return (T_LAB | T_DIR);
}

static int		get_dir(char *input, size_t *n)
{
	size_t	i;

	i = 1;
	if (input[i] == LABEL_CHAR)
		return (get_dir_label(input, n));
	if (input[i] == '-')
		i++;
	while (input[i] && ft_isdigit(input[i]))
		i++;
	if (i == 1 || !ft_isdigit(input[i - 1]))
		return (ERROR);
	*n = i;
	return (T_DIR);
}

int				get_type(char *input, size_t *n)
{
	int		type;

	if (!authorized_char(input[0]))
		return (ERROR);
	if (input[0] == '"')
		return (get_str(input, n));
	else if (input[0] == '\n' && ++(*n))
		return (T_NEW);
	else if (input[0] == '\0' && ++(*n))
		return (T_EOF);
	else if (input[0] == SEPARATOR_CHAR && ++(*n))
		return (T_SEP);
	else if (input[0] == '.')
		return (get_cmd(input, n));
	else if (input[0] == DIRECT_CHAR)
		return (get_dir(input, n));
	else if (input[0] == LABEL_CHAR || ft_isdigit(input[0]) || input[0] == '-')
		return (get_indir(input, n));
	else if (input[0] == 'r')
		return ((type = get_reg(input, n)) != 0 ? type : get_instr(input, n));
	else
		return (get_instr(input, n));
}
