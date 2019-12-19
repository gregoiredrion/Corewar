/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:27:46 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/19 17:50:23 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "define.h"

# define MALLOC_ERROR -1
# define ERROR 0
# define OK 1

# define COMMENT 0

typedef struct	s_token
{
	int				type;
	size_t			col;
	size_t			line;
	char			*str;
	struct s_token	*next;
}				t_token;

typedef struct	s_offset
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
	struct s_label	*next;
}				t_label;

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

typedef struct	s_cor
{
	char			*name;
	char			*comment;
	int				fd;
	size_t			flag;
	size_t			size;
	size_t			carry;
	size_t			line;
	char			*program;
	t_label			*labels;
	t_offset		*offset;
	t_op			op;
	t_token			*tokens;
}				t_cor;

int		usage(void);
int		error_msg(int ret);
int		create_cor(t_cor *cor);
int		check_name_comment(t_cor *cor, int fd);// unused ftm
int		init_cor(t_cor *cor, char **argv);
int		empty(char *line);
int		upper(char *str);
int		blank(char *str);

int		check_format_arg(t_cor *cor, char *arg, char *raw, int type);
int		store_instr(t_cor *cor, char *instr, char *params, char *raw);
int		store_params(t_cor *cor, char *params, char *raw);
int		store_label(t_cor *cor, char *label, char *raw);
int		store_cmd(t_cor *cor, char *cmd, char *raw);

int		invalid_param(char *instr, int type);
int		lexical_error(size_t line, size_t col);
size_t	get_column(char *raw, char *to_find);
int		syntax_error(size_t line, size_t col);
int		invalid_instr(char *instr, size_t line, size_t col);

int		tokenisation(char *input);
int		check_ind(char *input);
int		check_label(char *input);
int		check_cmd(char *input);
int		check_dir(char *input);
int		check_reg_instr(char *input);

#endif
