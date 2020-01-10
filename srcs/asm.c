/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:37:59 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/09 23:28:03 by gdrion           ###   ########.fr       */
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
	//if (!(cor.prog = malloc(sizeof(char) * cor.max)))
	//	return (error_msg(-1));
	//cor.header.magic = COREWAR_EXEC_MAGIC;
	if (asm_parser(&cor, argv[1]) < 1)
	{
		printf("test\n");
		return (0);
	}
	display_tokens(cor.tokens);
	//if (!(token_validity(&cor)))
	//	printf("Token validity error msg\n");//free
	//cor.header.prog_size = cor.size;
	//last offsets
	//if (!(cor.name = create_cor_file()))
	//	return (error_msg(-1));
	//ft_printf("Writing output program to %s\n", cor.name);
	//free
	return (0);
}
