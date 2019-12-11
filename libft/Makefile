NAME = libft.a
INCLUDES = includes/
SRCS_DIR = srcs/
OBJ_DIR = obj/
cc = gcc
FLAGS = -Wall -Werror -Wextra

FILES = $(shell find $(SRCS_DIR) -type f | grep -E ".c$$" | \
		sed 's/srcs//g')
SRCS = $(addprefix $(SRCS_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
SRCS_SUB = $(shell find ./srcs -type d)
OBJ_SUB = $(SRCS_SUB:./srcs%=./obj%)#why %?
WIDTH = $(shell echo $(notdir $(SRCS)) | tr " " "\n" | \
	awk ' { if ( length > x ) { x = length; y = $$0 } }END{ print y }' | wc -c)

ccRED = "\e[1;31m"
ccGREEN = "\e[1;32m"
ccBLUE = "\e[1;34m"
ccWHITE = "\e[1;37m"
ccRESET = "\e[0;0m"

all: $(NAME)

$(OBJ_SUB):
	@mkdir $@

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@tput civis
	@printf $(ccBLUE)
	@printf "Compiling %-$(WIDTH)s" $(notdir $<)
	@$(cc) $(FLAGS) -o $@ -c $< -I$(INCLUDES)
	@printf $(ccRESET)
	@printf "\r"

$(NAME): $(OBJ_SUB) $(OBJ)
	@printf $(ccGREEN)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "Successfully compiled %-$(WIDTH)s\n" $(NAME)
	@printf $(ccRESET)
	@tput cnorm

clean:
	@printf $(ccRED)
	@rm -rf $(OBJ_DIR)
	@printf "Successfully deleted $(OBJ_DIR)\n"
	@printf $(ccRESET)

fclean: clean
	@printf $(ccRED)
	@rm -f $(NAME)
	@printf "Successfully deleted $(NAME)\n"
	@printf $(ccRESET)

re: fclean all

.PHONY: all clean fclean re
