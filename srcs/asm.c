/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:37:59 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/10 16:38:03 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		return (usage());
	else if (!check_validity(argv))
		return (usage());
	if (flag(argv[1]))
	{
		//store flagag in struct
		fd = open(argv[2], O_RDONLY);
	}
	else
		fd = open(argv[1], O_RDONLY);
	return (0);
}
