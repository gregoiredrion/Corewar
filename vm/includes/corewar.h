/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:48:25 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/14 16:07:23 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <ncurses.h>
# include <fcntl.h>
# include <errno.h>
# include "op.h"
# include "libft.h"

# define FAILURE			0
# define SUCCESS			1
# define ALLOC_FAILURE		-1
# define DUMP				2

# define UNKNOWN			5

# define HEADER_SIZE		2192

# define NO_DUMP			-1

# define PROCESS_COLOR		5
# define NEUTRAL_COLOR		6
# define J1_COLOR			1
# define J2_COLOR			2
# define J3_COLOR			3
# define J4_COLOR			4

# define INFO_PAD_LINES		66
# define INFO_PAD_COLS		40

typedef _Bool	t_bool;

typedef struct	s_visu
{
	WINDOW	*main_pad;
	WINDOW	*mem_pad;
	WINDOW	*info_pad;
}				t_visu;

typedef struct	s_print_setup
{
	int		line;
	int		col;
	int		jump;
}				t_print_setup;

typedef struct	s_op
{
	char		*name;
	int			nb_arg;
	t_arg_type	arg_types[3];
	char		opcode;
	int			nb_cycles;
	char		*description;
	t_bool		has_opc;
	t_bool		is_dir_small;
}				t_op;

typedef struct	s_process
{
	char			owner;
	t_bool			is_alive;
	char			carry;
	int				registries[REG_NUMBER + 1];
	int				pc;
	unsigned char	opcode;
	int				cycle_counter;
}				t_process;

typedef struct	s_champ
{
	int				number;
	t_header		header;
	unsigned char	prog[CHAMP_MAX_SIZE];
	int				starting_address;
}				t_champ;

typedef struct	s_env
{
	t_champ			champs[MAX_PLAYERS];
	int				nchamps;
	t_visu			visu;
	t_bool			visu_on;
	t_bool			visu_running;
	t_bool			aff_live_notif_enabled;
	unsigned long	current_cycle;
	int				cycles_to_die;
	unsigned int	processes_running;
	unsigned char	vm_memory[MEM_SIZE];
	char			vm_ownership[MEM_SIZE];
	t_dbl_list		*first_process;
	char			*last_champ_alive;
	int				last_champ_alive_nb;
	int				nb_live_one_cycle_to_die;
	int				max_cycles;
	int				checks_left;
	int				dump;
}				t_env;

extern t_op		g_op_tab[17];

unsigned int	bytes_to_uint(void *first_byte);
int				bytes_to_int(unsigned char vm[MEM_SIZE], int index);
short			bytes_to_short(unsigned char vm[MEM_SIZE], int index);

void			put_int_in_vm(t_env *env, int index, int nb, t_process *p);
void			put_short_in_vm(t_env *env, int index, short nb, t_process *p);

int				handle_champ(char *path, int *index, int number, t_env *env);
int				handle_args(char **argv, t_env *env);

void			print_error(int code);

t_bool			check_if_number_free(int number, t_env env);
int				get_default_nb(t_env env);
void			set_arbitrary_champion_number(t_env *env);
void			sort_inv_by_champion_number(t_env *env);

int				parse_int(char *s, int *value);

int				init_first_processes(t_env *env);

int				vm_exec(t_env *env);
t_dbl_list		*kill_process(t_env *env, t_dbl_list *list_process);
void			move_pc(t_process *process, t_bool there_is_opc,\
unsigned char opc, int steps);
t_bool			is_opc_valid(t_op op, unsigned char opc);

int				free_one_list_process(t_dbl_list *list_process, int ret);
int				free_process(t_process *process, int ret);
int				free_list_processes(t_dbl_list *first_node, int ret);
void			free_pads(t_env *env);
int				free_all(t_env *env, int ret);

int				instr_live(t_env *env, t_process *process);
int				instr_fork(t_env *env, t_process *process);
int				instr_lfork(t_env *env, t_process *process);
int				instr_st(t_env *env, t_process *process);
int				instr_ld(t_env *env, t_process *process);
int				instr_add(t_env *env, t_process *process);
int				instr_sub(t_env *env, t_process *process);
int				instr_and(t_env *env, t_process *process);
int				instr_or(t_env *env, t_process *process);
int				instr_xor(t_env *env, t_process *process);
int				instr_zjmp(t_env *env, t_process *process);
int				instr_ldi(t_env *env, t_process *process);
int				instr_sti(t_env *env, t_process *process);
int				instr_lld(t_env *env, t_process *process);
int				instr_lldi(t_env *env, t_process *process);
int				instr_aff(t_env *env, t_process *process);

void			print_processes(t_dbl_list *first_process);

void			dump_buffer(unsigned char *buffer, int size);
void			dump_memory(t_env env);

int				init_ncurses(t_env *env);
void			handle_key(t_env *env);

int				win_refresh(t_env env);
int				mem_pad_refresh(t_env env);
int				info_pad_refresh(t_env env);

int				perror_msg(char *file, int ret);
int				error_msg(char *file, char *error_msg, int ret);
int				error_msg2(int file, char *error_msg, int ret);
int				error_msg3(char *error_msg, int ret);
int				error_msg4(char *option, char *s, int ret);
void			print_conclusion(int dump, t_env env);
void			print_intro(t_env *env);
void			print_usage(void);

#endif
