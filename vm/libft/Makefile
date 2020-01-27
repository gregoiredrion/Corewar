# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 13:58:35 by lode-spi          #+#    #+#              #
#    Updated: 2019/11/28 19:45:27 by lode-spi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

include ./libft.mk

CC = gcc
INCLUDES = -Iincludes/
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf

PRINTF_BINPATH = $(PRINTF)/bin/
PRINTF_SRCPATH = $(PRINTF)/src/
PRINTF_OBJS = $(addprefix $(PRINTF)/bin/, $(PRINTFSRCS:.c=.o))

OBJS = $(LIBFTSRCS:.c=.o)
OBJS := $(OBJS) $(PRINTF_OBJS)

all: $(NAME)

$(PRINTF_BINPATH):
	@mkdir -p $(PRINTF_BINPATH)
	@printf "▶ Building directory : \033[34m$@/\033[0m\n"

$(NAME): $(PRINTF_BINPATH) $(OBJS)
	@printf "▶ Building \033[34m$@\033[0m \033[32;1m✓\033[0m\n"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(PRINTF_BINPATH)%.o: $(PRINTF_SRCPATH)%.c includes/ft_printf.h includes/libft.h
	@printf "▶ Generating object file : \033[34m$@\033[0m\n"
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCLUDES)

%.o: %.c
	@printf "▶ Generating object file : \033[34m$@\033[0m\n"
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCLUDES)

clean:
	@rm -f $(OBJS) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all
