/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:25:25 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/10 15:15:33 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		get_str(char *input, size_t *n)
{
	size_t 	i;

	i = 1;
	while (input[i] && input[i] != '"')
		i++;
	if (!input[i])
		return (ERROR);// Do lexical error function
	*n = i;
	return (T_STR);
}

static int		get_cmd(char *input, size_t *n)
{
	size_t	i;

	i = 1;
	while (input[i] && ft_islower(input[i]))
		i++;
	if (!input[i])
		return (ERROR);	// Do lexical error function
	*n = i;
	return (T_NAM | T_CMT);
}

// To remodel imo
static int		get_dir(char *input, size_t *n)
{
	size_t	i;

	i = 1;
	if (input[i] == LABEL_CHAR)
	{
		i++;
		if (input[i + 1] == SEPARATOR_CHAR)
			return (ERROR);//Actually not fine
		while (ft_islower(input[i]))
			i++;
		if (i == 2)
			return (ERROR);
		*n = i;
		return (T_LAB | T_DIR);
	};//do_label stuff
	while (input[i] && ft_isdigit(input[i]))
		i++;
	if (i == 1)
		return (ERROR);
	*n = i;
	return (T_DIR);
}

int				get_type(char *input, size_t *n)
{
	int		type;

//	type = 0;
	if (input[0] == '"')
		return (get_str(input, n));
	else if (input[0] == '\n' && ++(*n))
		return (T_NEW);//Add token newline and return i + 1
	else if (input[0] == '\0' && ++(*n))
		return (T_EOF);//Add token EOF and return i + 1
	else if (input[0] == SEPARATOR_CHAR && ++(*n))
		return (T_SEP);//Add token T_SEP and return i + 1
	else if (input[0] == '.')
		return (get_cmd(input, n));
	else if (input[0] == DIRECT_CHAR)
		return (get_dir(input, n));
	else if (input[0] == LABEL_CHAR || ft_isdigit(input[0]))
		return get_indir(input, n);
	else if (input[0] == 'r')
		return ((type = get_reg(input, n)) != 0 ? type : get_instr(input, n));
	else
		return get_instr(input, n);//C'est pas joli
}