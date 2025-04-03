# Nombre ejecutable
NAME = cub3D

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -g3 -Wall -Wextra -Werror -Iinclude -Iutils

# Minilibx
MLX_PATH = ./minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# Directorios
SRC_DIR = src
OBJ_DIR = obj

# Archivos fuente
SRC =	main.c \
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
		rendering/window.c

# Archivos objeto
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Reglas make
all: $(LIBFT) $(MLX) $(NAME)

# Compila el ejecutable principal
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) \
		-L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -lXext -lX11 -lm -I/usr/include -Imlx_linux -L/usr/lib

# Compilar primero libft
$(LIBFT):
	@echo "Compilando Libft..."
	@make -C $(LIBFT_PATH)

# Compilar primero MinilibX
$(MLX):
	@echo "Compilando MinilibX..."
	@make -C $(MLX_PATH)

# Compilar archivos fuente a objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear el directorio de objetos si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Eliminar archivos objeto y limpiar librerías
clean:
	@echo "Limpiando archivos objeto..."
	rm -rf $(OBJ_DIR)
	@echo "Limpiando Libft..."
	make -C $(LIBFT_PATH) clean
	@echo "Limpiando MinilibX..."
	make -C $(MLX_PATH) clean

# Eliminar todo lo generado (ejecutable + librerías)
fclean: clean
	@echo "Eliminando ejecutable..."
	rm -f $(NAME)
	@echo "Eliminando Libft..."
	make -C $(LIBFT_PATH) fclean
	@echo "Eliminando MinilibX..."
	make -C $(MLX_PATH) clean

# Regenerar todo desde cero
re: fclean all

.PHONY: all clean fclean re