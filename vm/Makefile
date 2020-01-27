# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 14:45:24 by lode-spi          #+#    #+#              #
#    Updated: 2020/01/14 14:59:37 by lode-spi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIBFT = libft
CC = gcc
INCLUDES = -Iincludes/ -I$(LIBFT)/includes/

include ./$(LIBFT)/libft.mk
include ../corewar.mk

CFLAGS = -Wall -Wextra -Werror
CLIBFT = -L$(LIBFT) -lft
CNCURSES = -lncurses

SRCPATH = src
BINPATH = bin

OBJ = $(VM_SRC:.c=.o)
BIN = $(addprefix $(BINPATH)/, $(OBJ))

all: $(NAME)

$(LIBFT)/libft.a: $(LIBFTSRCS) $(PRINTFSRCS)
	@make -sC $(LIBFT)/

$(BINPATH):
	@mkdir -p $(BINPATH)
	@printf "▶ Building directory : \033[34m$@/\033[0m\n"

$(NAME): $(LIBFT)/libft.a $(BINPATH) $(BIN) includes/corewar.h includes/op.h
	@$(CC) -o $(NAME) $(BIN) $(CFLAGS) $(CNCURSES) $(CLIBFT) -lft
	@printf "▶ Building \033[34m$@\033[0m \033[32;1m✓\033[0m\n"

$(BINPATH)/%.o: $(SRCPATH)/%.c includes/corewar.h includes/op.h
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCLUDES)
	@printf "▶ Generating object file : \033[34m$@\033[0m\n"

clean:
	@rm -rf $(BINPATH)
	@make -C $(LIBFT)/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT)/ fclean

re : fclean all

.PHONY: all $(LIBFTSRCS) $(PRINTFSRCS)
