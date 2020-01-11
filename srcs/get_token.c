/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:25:25 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/11 01:21:26 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		get_str(char *input, size_t *n)
{
	size_t		i;

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
		while (ft_strchr(LABEL_CHARS, input[i]))
			i++;
		if (i == 2)
			return (ERROR);
		*n = i;
		return (T_LAB | T_DIR);
	};//do_label stuff
	if (input[i] == '-' || input[i] == '+')
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

//	type = 0;
	if (input[0] == '"')
		return (get_str(input, n));
	else if (input[0] == '\n' && ++(*n))
		return (T_NEW);
	else if (input[0] == '\0' && ++(*n))
		return (T_EOF);
	else if (input[0] == SEPARATOR_CHAR && ++(*n))
		return (T_SEP);
	else if (input[0] == '.')
		return (get_cmd(input, n));//if symbal like + etc ->lexical
	else if (input[0] == DIRECT_CHAR)
		return (get_dir(input, n));//if symbal like + etc ->lexical
	else if (input[0] == LABEL_CHAR || ft_isdigit(input[0]))
		return (get_indir(input, n));//if symbal like + etc ->lexical
	else if (input[0] == 'r')
		return ((type = get_reg(input, n)) != 0 ? type : get_instr(input, n));//if symbal like + etc ->lexical
	else
		return (get_instr(input, n));//C'est pas joli
}
