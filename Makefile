# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 12:17:00 by atoof             #+#    #+#              #
#    Updated: 2023/09/12 17:46:17 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_DIR = src/
UTILS_DIR = src/utils/
VALID_DIR = src/check_validity/
ERROR_DIR = src/error_checking/
FLOODFILL_DIR = src/flood_fill/
READMAP_DIR = src/read_map/
SRC =	main.c
VALID = check_valid_color.c validity_utils.c valid_map.c check_map_zeros.c
ERROR =  errors.c 
UTILS =  free.c ft_atoll.c init_data.c
FLOODFILL = flood_fill_algorithm.c flood_fill_utils.c
READMAP = read_file_and_parse.c texture_color_init.c get_raw_map_util.c get_raw_map.c
SRCS = $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(VALID_DIR), $(VALID)) \
		$(addprefix $(ERROR_DIR), $(ERROR)) $(addprefix $(FLOODFILL_DIR), $(FLOODFILL)) \
		$(addprefix $(READMAP_DIR), $(READMAP)) $(addprefix $(UTILS_DIR), $(UTILS))
		
HEADER_DIR = header/
HEADER = cub3d.h
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a
FLAGS = -Wall -Werror -Wextra
ERROR_FLAGS = -fsanitize=address -g #-static-libsan -fno-omit-frame-pointer -overflow
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
