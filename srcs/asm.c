/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:37:59 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/11 21:28:59 by wdeltenr         ###   ########.fr       */
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
	cor.name = argv[1];//don't forget flag
	if (!(cor.prog = malloc(sizeof(char) * cor.max)))
		return (error_msg(-1));
	cor.header.magic = reverse_int32(COREWAR_EXEC_MAGIC);
	if (asm_parser(&cor, argv[1]) < 1)
	{
		printf("test\n");
		return (0);
	}
	cor.size = 0;
	if (!(token_validity(&cor)))
		printf("Token validity error msg\n");//free
  if (!process_tokens(&cor))
        return (ERROR);
	cor.header.prog_size = reverse_int32(cor.size);
	if (!(cor.name = create_cor_file(&cor)))
		return (error_msg(-1));
	ft_printf("Writing output program to %s\n", cor.name);
	free_all(&cor);
	return (0);
}
