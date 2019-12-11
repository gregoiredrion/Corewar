/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:27:46 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/11 15:01:14 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

typedef struct		s_core
{
	char	*name;
	char	*comment;
	int		fd;
	size_t	flag;
	size_t	size;
	size_t	carry;
	char	*bytes;
	//int	*to_do;?? (int tab to store to do (offset))
}					t_core;

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
}					t_op;

int		usage(void);
t_core	*create_core(char **argv);
char	*check_name_comment(int fd, const char *command);

#endif
