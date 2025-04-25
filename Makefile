# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 42 Student                                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22                                 #+#    #+#              #
#    Updated: 2025/04/22                                 ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================================
#              CONFIGURACIÓN
# =========================================

NAME := cub3D
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3

SRC_DIR := src
OBJ_DIR := obj
INCLUDES := -Iinclude -Iutils

SRCS := \
	main.c \
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
	rendering/renderer.c \
	movement/movement_keys.c \
	textures_loader/texture_load.c \
	textures_loader/texture_render.c \
	movement/key_pressing.c \
	bonus/minimap.c

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

linux: MODE = linux
linux: fclean init libft $(MLX_LINUX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LINUX_FLAGS)

macos: MODE = macos
macos: fclean init libft $(MLX_MACOS) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -I$(MLX_MACOS_DIR) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_MACOS_FLAGS)

macos\ re: macos

init:
	@mkdir -p $(OBJ_DIR)

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
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LINUX):
	$(MAKE) -C $(MLX_LINUX_DIR)

$(MLX_MACOS):
	$(MAKE) -C $(MLX_MACOS_DIR)

libft:
	$(MAKE) -C $(LIBFT_DIR)

# =========================================
#                LIMPIEZA
# =========================================

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	-$(MAKE) -C $(MLX_LINUX_DIR) clean
	-$(MAKE) -C $(MLX_MACOS_DIR) clean

fclean:
	$(MAKE) clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	# Elimina libmlx.a si existe
	rm -f $(MLX_LINUX)
	rm -f $(MLX_MACOS)

re: fclean all

.PHONY: all linux macos macos\ re clean fclean re libft
