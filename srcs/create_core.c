/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:00:41 by wdeltenr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/12/21 10:41:55 by gregoiredrion    ###   ########.fr       */
=======
/*   Updated: 2019/12/17 19:50:50 by wdeltenr         ###   ########.fr       */
>>>>>>> 649a97267cfc54757606e15dbaaa3e78d0ec773c
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
<<<<<<< HEAD
	cor->line = 1;
	return (1);
=======
	cor->line = 0;
	return (OK);
>>>>>>> 649a97267cfc54757606e15dbaaa3e78d0ec773c
}
