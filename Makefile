# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 19:06:14 by vvu               #+#    #+#              #
#    Updated: 2023/10/13 12:20:59 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_DIR = src/
BONUS_DIR = src/bonus_src/
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
UTILS =  ft_atoll.c ft_split_spaces.c
FLOODFILL = flood_fill_algorithm.c flood_fill_utils.c
READ_MAP = read_file_and_parse.c texture_color_init.c get_raw_map_util.c get_raw_map.c \
			color_init_utils.c init_player_position.c
RENDER = image_handler.c ray_casting.c utils.c draw_walls.c
KEY_EVENTS = key_handler.c key_utils.c
RENDER_MANDATORY_FILES = render.c init_window.c
KEY_EVENTS_FILES = key_handler.c key_utils.c
UTILS_MANDATORY_FILES = init_data.c free.c
BONUS_FILES = init_data_bonus.c free_bonus.c render_bonus.c init_window_bonus.c mini_map_bonus.c draw_bonus.c dda_algorithm_bonus.c
SRCS = $(addprefix $(SRC_DIR), $(SRC)) \
		$(addprefix $(VALID_DIR), $(VALID)) \
		$(addprefix $(ERROR_DIR), $(ERROR)) \
		$(addprefix $(FLOODFILL_DIR), $(FLOODFILL)) \
		$(addprefix $(READ_MAP_DIR), $(READ_MAP)) \
		$(addprefix $(UTILS_DIR), $(UTILS)) \
		$(addprefix $(RENDER_DIR), $(RENDER)) \
		$(addprefix $(KEY_EVENTS_DIR), $(KEY_EVENTS))

MANDATORY_SRCS = $(SRCS) $(addprefix $(UTILS_DIR), $(UTILS_MANDATORY_FILES)) \
				$(addprefix $(RENDER_DIR), $(RENDER_MANDATORY_FILES))
BONUS_SRCS = $(SRCS) $(addprefix $(BONUS_DIR), $(BONUS_FILES))

MANDATORY_OBJ_DIR = obj_mandatory/
BONUS_OBJ_DIR = obj_bonus/

OBJS = $(MANDATORY_SRCS:%.c=$(MANDATORY_OBJ_DIR)%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJ_DIR)%.o)

HEADER_DIR = header/
HEADER = $(HEADER_DIR)cub3d.h
BONUS_HEADER = $(HEADER_DIR)cub3d_bonus.h

OBJ_DIR = obj/

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
vpath %.c $(BONUS_DIR)
vpath %.h $(HEADER_DIR)

.PHONY : all bonus clean fclean re re_bonus
all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@cc $(FLAGS) $(EXTRA_FLAGS) $(OBJS) -I$(HEADER_DIR) $(LIBFT) -o $@
	@echo "$(GREEN)$(BOLD)$(NAME) successfully compiled!$(NC)"

$(MANDATORY_OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@cc $(FLAGS) -I$(HEADER_DIR) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C ./libft
	@cc $(FLAGS) $(EXTRA_FLAGS) $(BONUS_OBJS) -I$(HEADER_DIR) $(LIBFT) -o $@
	@echo "$(GREEN)$(BOLD)$(BONUS_NAME) successfully compiled!$(NC)"

$(BONUS_OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@cc $(FLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	@make clean -C ./libft
	@/bin/rm -rf $(MANDATORY_OBJ_DIR)

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(BONUS_NAME)

re: fclean all
re_bonus: fclean bonus
