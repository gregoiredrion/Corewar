/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:27:46 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 18:07:10 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

# define MALLOC_ERROR -1
# define ERROR 0
# define COMMENT 0
# define NAME 1

typedef struct	s_offest
{
	char			*name;
	size_t			start;
	size_t			byte;
	struct s_offest	*next;
}				t_offset;

typedef struct	s_label
{
	char			*name;
	size_t			pos;
	struct s_offest	*next;
}				t_label;

typedef struct	s_cor
{
	char			*name;
	char			*comment;
	int				fd;
	char			*file;
	size_t			flag;
	size_t			size;
	size_t			carry;
	size_t			line;
	char			*output;
	t_offset		*offset;
}				t_cor;

typedef struct	s_op
{
	char			*name;
	size_t			nb_arg;
	t_arg_type		arg_type[3];
	size_t			opcode;
	size_t			cycle_cost;
	char			*description;
	size_t			code_octet;
	size_t			label_size;
}				t_op;

typedef struct 	s_token
{
	int				type;
	size_t			col;
	size_t			line;
	char			*str;
	struct s_token	*next;
}				t_token;

int		usage(void);
int		error_msg(int ret);
int		create_cor(t_cor *cor);
int		check_name_comment(t_cor *cor, int fd);// unused ftm
int		init_cor(t_cor *cor, char **argv);
int		empty(char *line);


int		store_instr(t_cor *cor, char *instr, char *params, char *raw);
int		store_label(t_cor *cor, char *label, char *raw);
int		store_cmd(t_cor *cor, char *cmd, char *raw);
int 	asm_parser(t_cor *cor, char *file);

int		skip_comment(char *file, size_t i, size_t *line, size_t *pos);
int		trim_file(char **file);
int		skip_newline(char *file, size_t i, size_t *line, size_t *pos);
#endif
