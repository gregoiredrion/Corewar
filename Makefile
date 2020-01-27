# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 14:45:24 by lode-spi          #+#    #+#              #
#    Updated: 2020/01/14 16:17:59 by lode-spi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
VMDIR = vm
ASMDIR = asm

include corewar.mk

all: $(NAME)

$(NAME) : $(VMDIR)/corewar $(ASMDIR)/asm

$(VMDIR)/corewar: $(VM_SRC) $(VMDIR)/Makefile $(VMDIR)/includes/corewar.h
	@make -C vm/

$(ASMDIR)/asm: $(ASM_SRC) $(ASMDIR)/Makefile $(ASMDIR)/includes/asm.h
	@make -C asm/

clean:
	@make -C vm/ clean
	@make -C asm/ clean

fclean: clean
	@make -C vm/ fclean
	@make -C asm/ fclean

re : fclean all

.PHONY: all $(VM_SRC) $(ASM_SRC)
