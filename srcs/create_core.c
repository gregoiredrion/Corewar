/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:00:41 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/12 17:15:00 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			create_cor(char **argv, t_cor *cor)
{
	if (!(cor = malloc(sizeof(t_cor))))
		return (MALLOC_ERROR);
	cor->fd = -1;
	cor->flag = 0;
	cor->name = NULL;
	cor->comment = NULL;
	cor->carry = 0;
	cor->size = 0;
	cor->size = line;
	cor->bytes = NULL;
	return (1);
}
