/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:00:41 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/06 17:05:18 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			create_cor(t_cor *cor)
{
	cor->name = NULL;
	cor->fd = -1;
	cor->flag = 0;
	cor->file = NULL;
	cor->size = 0;
	cor->line = 1;
	cor->prog = NULL;
	cor->labels = NULL;
	cor->offset = NULL;
	cor->tokens = NULL;
	ft_bzero(&(cor->header), sizeof(cor->header));
	return (OK);
}
