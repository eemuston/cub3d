# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eemuston <eemuston@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 12:17:00 by atoof             #+#    #+#              #
#    Updated: 2023/09/06 15:57:00 by eemuston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_DIR = src/
SRC = main.c errors.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
HEADER_DIR = header/
HEADER = cub3d.h
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a
FLAGS = -Wall -Werror -Wextra
# ERROR_FLAGS = -fsanitize=address -static-libsan -g -fno-omit-frame-pointer -overflow
EXTRA_FLAGS = -lmlx -framework OpenGL -framework AppKit

BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

vpath %.c $(SRC_DIR)
vpath %.h $(HEADER_DIR)

all: $(NAME)

$(NAME): $(OBJS)
		@if [ -f $(NAME) ] && [ "$(OBJS)" -ot "$(NAME)" ]; then \
			echo "$(GREEN)$(BOLD)$(NAME) is already up-to-date!$(NC)"; \
		else \
			echo "$(YELLOW)$(BOLD)Compiling $(NAME)...$(NC)"; \
			make -C ./libft; \
			cc $(FLAGS) $(EXTRA_FLAGS) $(OBJS) -I$(HEADER_DIR) $(LIBFT) -o $@ ; \
			echo "$(GREEN)$(BOLD)$(NAME) successfully compiled!$(NC)"; \
		fi
$(OBJ_DIR)%.o: %.c $(HEADER_DIR)$(HEADER)
	@echo "$(YELLOW)$(BOLD)Compiling $<...$(NC)"
	@mkdir -p $(@D)
	@cc $(FLAGS) -I$(HEADER_DIR) -c -o $@ $<
	
clean:
	@echo "$(CYAN)$(BOLD)Cleaning object files...$(NC)"
	@make clean -C ./libft
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)$(BOLD)Cleaning $(NAME)...$(NC)"
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) successfully cleaned!$(NC)"

re: fclean all
