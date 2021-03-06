/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:37:59 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/13 18:14:29 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_cor	cor;
	int		ret;

	if (argc == 1)
		return (usage());
	if ((create_cor(&cor)) == -1)
		return (error_msg(MALLOC_ERROR));
	cor.name = argv[1];
	if (!(cor.prog = malloc(sizeof(char) * cor.max)))
		return (error_msg(MALLOC_ERROR));
	cor.header.magic = reverse_int32(COREWAR_EXEC_MAGIC);
	if ((ret = asm_parser(&cor, argv[1]) < 1))
		return (free_all(&cor, ret));
	cor.size = 0;
	if ((ret = token_validity(&cor)) < 1)
		return (free_all(&cor, ret));
	if ((ret = process_tokens(&cor) < 1))
		return (free_all(&cor, ret));
	cor.header.prog_size = reverse_int32(cor.size);
	if (!create_cor_file(&cor, &ret))
		return (free_all(&cor, ret));
	return (free_all(&cor, OK));
}
