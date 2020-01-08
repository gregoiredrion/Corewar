/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:37:59 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/29 19:32:27 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"



int		main(int argc, char **argv)
{
	t_cor	cor;
	if (argc == 1)
		return (usage());
	if ((create_cor(&cor)) == -1)
		return (error_msg(-1));
	if (asm_parser(&cor, argv[1]) < 1)
		return (0);
	if (!(token_validity(&cor)))
		printf("Token validity error msg\n");
	return (0);
}
