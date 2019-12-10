/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:27:46 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/10 15:56:45 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

typedef struct		s_op
{
	char		*name;
	size_t		nb_arg;
	t_arg_type	arg_type[3];
	size_t		opcode;
	size_t		cycle_cost;
	char		*description;
	size_t		code_octet;
	size_t		label_size;
}

#endif
