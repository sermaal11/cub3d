# =========================================
#              CONFIGURACIÓN
# =========================================

NAME := cub3D
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3

SRC_DIR := src
OBJ_DIR := obj
INCLUDES := -Iinclude -Iutils

SRCS :=	main.c \
		utils/utils.c \
		utils/parsing_utils.c \
		utils/rendering_utils.c \
		parsing/parsing.c \
		parsing/parsing_map.c \
		parsing/parsing_map_two.c \
		parsing/parsing_map_file.c \
		parsing/parsing_fc_color.c \
		parsing/parsing_textures.c \
		parsing/parsing_map_three.c \
		parsing/parsing_fc_color_two.c \
		rendering/window.c \
		execution/renderer.c \
		movement/movement.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Librerías
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# MiniLibX Linux
MLX_LINUX_DIR := minilibx-linux
MLX_LINUX := $(MLX_LINUX_DIR)/libmlx.a
MLX_LINUX_FLAGS := -L$(MLX_LINUX_DIR) -lmlx -lXext -lX11 -lm

# MiniLibX macOS (OpenGL)
MLX_MACOS_DIR := minilibx-opengl
MLX_MACOS := $(MLX_MACOS_DIR)/libmlx.a
MLX_MACOS_FLAGS := -L$(MLX_MACOS_DIR) -lmlx -framework OpenGL -framework AppKit

# =========================================
#              REGLAS GENERALES
# =========================================

all: linux

linux: $(LIBFT) $(MLX_LINUX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LINUX_FLAGS)

macos: $(LIBFT) $(MLX_MACOS) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -I$(MLX_MACOS_DIR) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_MACOS_FLAGS)

# =========================================
#        COMPILACIÓN DE ARCHIVOS .o
# =========================================

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =========================================
#        LIBRERÍAS ESTÁTICAS
# =========================================

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LINUX):
	make -C $(MLX_LINUX_DIR)

$(MLX_MACOS):
	make -C $(MLX_MACOS_DIR)

# =========================================
#                LIMPIEZA
# =========================================

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_LINUX_DIR) clean
	$(MAKE) -C $(MLX_MACOS_DIR) clean

fclean:
	$(MAKE) clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_LINUX_DIR) fclean || true
	$(MAKE) -C $(MLX_MACOS_DIR) fclean || true

re: fclean all

.PHONY: all linux macos clean fclean re
