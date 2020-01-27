VM_SRC = main.c								\
		 parse_int.c						\
		 endian_translator.c				\
		 champion_number.c					\
		 parser.c							\
		 ncurses_memory_pad.c				\
		 ncurses_main_pad.c					\
		 ncurses_info_pad.c					\
		 ncurses_init.c						\
		 dump.c								\
		 error.c							\
		 parser_init_processes.c			\
		 vm_exec.c							\
		 vm_exec_utils.c 					\
		 free.c								\
		 op.c								\
		 instr_live_fork_lfork.c			\
		 instr_ld_lld_st.c					\
		 instr_aff.c						\
		 instr_zjmp.c						\
		 instr_and_or_xor.c					\
		 instr_sti.c						\
		 instr_add.c						\
		 instr_sub.c						\
		 instr_ldi_lldi.c					\
		 print_messages.c

ASM_SRC = add_token.c						\
		  asm.c								\
		  asm_parse_utils.c					\
		  asm_parser.c						\
		  char_authentication.c				\
		  check_params.c					\
		  create_cor_file.c					\
		  create_core.c						\
		  create_token.c					\
		  error.c							\
		  error2.c							\
		  error_displays.c					\
		  free_all.c						\
		  get_token.c						\
		  get_token2.c						\
		  offsets.c							\
		  op.c								\
		  process_tokens.c					\
		  store_header.c					\
		  store_instruction.c				\
		  store_label.c						\
		  store_params.c					\
		  token_validity.c					\
		  token_validity2.c					\
		  write_prog.c
