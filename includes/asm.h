/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:27:46 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/11 17:59:52 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define MALLOC_ERROR -1
# define ERROR 0
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
int		error_msg(int ret);
int		create_core(char **argv, t_core *core);
int		check_name_comment(int fd, const char *cmp, char **s);

#endif
