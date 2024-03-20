# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 18:30:30 by ohertzbe          #+#    #+#              #
#    Updated: 2024/03/13 14:16:16 by ohertzbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
NAME := pipex

LIBFT := ./lib/libft/libft.a

INCL := -I ./include

M_DIR := src/mandatory/
M_SRC := main.c child_functions.c open_files.c paths.c pipes.c \
		 utils.c error_exit.c
M_PATH := $(addprefix $(M_DIR), $(M_SRC))
M_OBJ := $(patsubst $(M_DIR)%.c, obj/%.o, $(M_PATH))

B_DIR := src/bonus/
B_SRC := main_bonus.c child_functions_bonus.c here_doc_bonus.c \
		 open_files_bonus.c paths_bonus.c pipes_bonus.c \
		 utils_bonus.c error_exit_bonus.c
B_PATH := $(addprefix $(B_DIR), $(B_SRC))
B_OBJ := $(patsubst $(B_DIR)%.c, obj/%.o, $(B_PATH))
		

obj/%.o: src/mandatory/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/bonus/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

bonus: .bonus

.bonus: $(LIBFT) $(B_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
	touch .bonus
	
$(NAME): $(LIBFT) $(M_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(INCL)

$(LIBFT):
	make -C ./lib/libft

clean:
	rm -rf obj
	make -C ./lib/libft clean

fclean: clean
	make -C ./lib/libft fclean
	rm -f .bonus
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus