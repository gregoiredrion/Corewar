/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:10:29 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/13 17:47:11 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token	*store_comment(t_cor *cor, t_token *token)
{
	if (ft_strlen(token->str) > COMMENT_LENGTH)
	{
		ft_printf("Champion comment too long (Max length 2048)\n");
		return (NULL);
	}
	ft_strcpy(cor->header.comment, token->str);
	return (token->next);
}

static t_token	*store_name(t_cor *cor, t_token *token)
{
	if (ft_strlen(token->str) > PROG_NAME_LENGTH)
	{
		ft_printf("Champion name too long (Max length 128)\n");
		return (NULL);
	}
	ft_strcpy(cor->header.prog_name, token->str);
	return (token->next);
}

t_token			*store_cmd(t_cor *cor, t_token *token)
{
	if (token->type & T_NAM && token->next->type & T_STR)
		return (store_name(cor, token->next));
	if (token->type & T_CMT && token->next->type & T_STR)
		return (store_comment(cor, token->next));
	return (NULL);
}
