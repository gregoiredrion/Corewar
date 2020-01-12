/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_authentification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <gdrion@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:05:29 by gdrion            #+#    #+#             */
/*   Updated: 2020/01/12 22:23:57 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_labelchar(char c)
{
	return (ft_islower(c) || ft_isdigit(c) || c == '_');
}

static int	start_token_char(char c)
{
	return (c == '%' || c == ',' || c == ':' || c == '"' || c == '.' ||
	c == '-');
}

int			authorized_char(char c)
{
	return (is_labelchar(c) || start_token_char(c) || c == '\n' || c == '\0');
}

int			separating_char(char c)
{
	return (c == ',' || isblank(c));
}
