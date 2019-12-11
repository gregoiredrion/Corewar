NAME = asm
INCLUDES = includes/
SRCS_DIR = srcs/
OBJ_DIR = obj/
LIBFT_DIR = libft/
LIBFT_INCLUDES = libft/includes/
LIBFT = libft/libft.a
cc = gcc
FLAGS = -Wall -Werror -Wextra

FILES = $(shell find srcs -type f | grep -E ".c$$" | sed 's/srcs//g')
SRCS = $(addprefix $(SRCS_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
WIDTH = $(shell echo $(notdir $(SRCS)) | tr " " "\n" | \
	awk ' { if ( length > x ) { x = length; y = $$0 } }END{ print y }'| wc -c)

ccRED = "\e[1;31m"
ccGREEN = "\e[1;32m"
ccBLUE = "\e[1;34m"
ccWHITE = "\e[1;37m"
ccRESET = "\e[0;0m"

all: lib $(NAME)

lib:
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/asm.h Makefile
	@tput civis
	@printf $(ccBLUE)
	@printf "Compiling %-$(WIDTH)s" $(notdir $<)
	@$(cc) $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIBFT_INCLUDES)
	@printf $(ccRESET)
	@printf "\r"

$(OBJ_DIR):
	@mkdir $@

$(NAME): $(OBJ_DIR) $(OBJ) Makefile
	@printf $(ccGREEN)
	@$(cc) $(FLAGS) $(OBJ) -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(LIBFT) \
	-o $(NAME)
	@printf "Successfully compiled %-$(WIDTH)s" $(NAME)
	@printf "                                                    \n"
	@printf $(ccRESET)
	@tput cnorm

clean:
	@printf $(ccRED)
	@rm -rf $(OBJ_DIR)
	@printf "Successfully deleted $(OBJ_DIR)\n"
	@make clean -C $(LIBFT_DIR)
	@printf $(ccRESET)

fclean: clean
	@printf $(ccRED)
	@rm -f $(NAME)
	@printf "Successfully deleted $(NAME)\n"
	@make fclean -C $(LIBFT_DIR)
	@printf $(ccRESET)

re: fclean all

.PHONY: all clean fclean re
