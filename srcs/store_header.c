/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:10:29 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/06 16:54:59 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	store_comment(t_cor *cor, t_token *token)
{
	if (ft_strlen(token->str) > PROG_NAME_LENGTH)
	{
		ft_printf("Champion name too long (Max length 128)\n");
		return (ERROR);
	}
	ft_strcpy(cor->header.prog_name, token->str);
	return (OK);
}

static int	store_name(t_cor *cor, t_token *token)
{
	if (ft_strlen(token->str) > COMMENT_LENGTH)
	{
		ft_printf("Champion comment too long (Max length 2048)\n");
		return (ERROR);
	}
	ft_strcpy(cor->header.comment, token->str);
	return (OK);
}

int			store_header(t_cor *cor, t_token *token)
{
	if (!ft_strcmp(token->str, ".name"))
	{
		if (!store_name(cor, token->next))
			return (ERROR);
	}
	else
	{
		if (!store_comment(cor, token->next))
			return (ERROR);
	}
	return (OK);
}
