/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:00:41 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/18 18:34:56 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			create_cor(t_cor *cor)
{
	cor->fd = -1;
	cor->flag = 0;
	cor->file = NULL;
	cor->name = NULL;
	cor->comment = NULL;
	cor->carry = 0;
	cor->size = 0;
	cor->size = 0;
	return (1);
}
