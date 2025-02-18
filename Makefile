# Nombre ejecutable
NAME = cub3D

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -g3 -Wall -Wextra -Werror #-fsanitize=address

# Minilibx
MLX_PATH = ./minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Directorios
SRC_DIR = src
OBJ_DIR = obj

# Archivos fuente
SRC = main.c

# Archivos objeto
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Reglas make
all: $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -I/usr/include -Imlx_linux -L/usr/lib

$(MLX):
	make -sC $(MLX_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -sC $(MLX_PATH) clean

re: fclean $(MLX) all

.PHONY: all clean fclean re