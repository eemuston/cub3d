# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 19:06:14 by vvu               #+#    #+#              #
#    Updated: 2023/10/12 14:33:58 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_DIR = src/
UTILS_DIR = src/utils/
VALID_DIR = src/check_validity/
ERROR_DIR = src/error_checking/
FLOODFILL_DIR = src/flood_fill/
READ_MAP_DIR = src/read_map/
RENDER_DIR = src/render/
KEY_EVENTS_DIR = src/key_events/
SRC =	main.c
VALID = check_valid_color.c validity_utils.c valid_map.c
ERROR =  errors.c 
UTILS =  free.c ft_atoll.c init_data.c ft_split_spaces.c
FLOODFILL = flood_fill_algorithm.c flood_fill_utils.c
READ_MAP = read_file_and_parse.c texture_color_init.c get_raw_map_util.c get_raw_map.c \
			color_init_utils.c init_player_position.c
RENDER = init_window.c image_handler.c mini_map.c render.c ray_casting.c dda_algorithm.c \
				utils.c draw_walls.c
KEY_EVENTS = key_handler.c key_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(VALID_DIR), $(VALID)) \
		$(addprefix $(ERROR_DIR), $(ERROR)) $(addprefix $(FLOODFILL_DIR), $(FLOODFILL)) \
		$(addprefix $(READ_MAP_DIR), $(READ_MAP)) $(addprefix $(UTILS_DIR), $(UTILS)) \
		$(addprefix $(RENDER_DIR), $(RENDER)) $(addprefix $(KEY_EVENTS_DIR), $(KEY_EVENTS))
HEADER_DIR = header/
HEADER = cub3d.h
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a
FLAGS = -Wall -Werror -Wextra
ERROR_FLAGS = -fsanitize=address -g -static-libsan -fno-omit-frame-pointer -overflow
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
			cc $(FLAGS) $(EXTRA_FLAGS) $(ERROR_FLAGS) $(OBJS) -I$(HEADER_DIR) $(LIBFT) -o $@ ; \
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
