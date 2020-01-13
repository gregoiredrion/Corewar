/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:27:46 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/13 22:01:39 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

# define MALLOC_ERROR -1
# define ERROR 0
# define OK 1

# define NB_ARG 1
# define ARG_TYPE 2

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
	size_t			pos;
	size_t			nb_bytes;
	t_token			*token;
	struct s_offset	*next;
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
	int				fd;
	size_t			flag;
	char			*file;
	t_arg_type		tab[3];
	size_t			size;
	size_t			line;
	size_t			pos;
	size_t			max;
	char			*prog;
	t_label			*labels;
	t_offset		*offset;
	t_op			op;
	t_token			*tokens;
	t_header		header;
}				t_cor;

/*
** Parsing
*/
int				asm_parser(t_cor *cor, char *file);
t_token			*create_token(char *input, int type, size_t col, size_t line);
int				create_cor(t_cor *cor);
int				skip_nl(t_cor *cor, char *input, size_t *line, size_t *col);
int				check_ind(char *input, size_t i);
int				check_label(char *input);
int				check_cmd(char *input);
int				check_dir(char *input);
int				check_reg_instr(char *input);
int				token_validity(t_cor *cor);
int				get_instr(char *input, size_t *n);
int				get_reg(char *input, size_t *n);
int				get_indir(char *input, size_t *n);
int				get_type(char *input, size_t *n);
int				tokenization(t_cor *cor, char *input, size_t *col, size_t *line);
void			pushback_token(t_cor *cor, t_token *token);
int				upper(char *str);

/*
** Error
*/
int				usage(void);
int				invalid_param(char *instr, int error, int type, size_t pos);
int				lexical_error(size_t line, size_t col, char *token_string);
t_token			*syntax_error(t_token *token);
t_token			*syntax_newline(void);
t_token			*invalid_instr(t_token *token);
int				error_msg(int ret);

/*
** Store and process tokens to prog
*/
t_token			*store_instruction(t_cor *cor, t_token *token, int *error);
t_token			*store_label(t_cor *cor, t_token *label, int *error);
t_token			*store_cmd(t_cor *cor, t_token *token);
t_token			*store_params(t_cor *cor, t_token *token, int *error);
int				last_offsets(t_cor *cor);
int				offsets(t_cor *cor, t_token *token, size_t nb_bytes);
int				write_prog(t_cor *cor, int add, size_t nb_bytes, int *error);
int				process_tokens(t_cor *cor);
int				instr_params(t_cor *cor, t_token *token, size_t nb_arg);

/*
** Character authentification
*/
int				authorized_char(char c);
int				is_labelchar(char c);
int				separating_char(char c);

/*
** Output
*/
char			*create_cor_file(t_cor *cor, int *error);

/*
** Free
*/
int				free_all(t_cor *cor, int error);

//display_tokens
char			*id_token(t_token *token);
void			display_tokens(t_token *tokens);

#endif
