/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:53:30 by smarin-a          #+#    #+#             */
/*   Updated: 2025/04/21 23:49:22 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <math.h>

# define MAP_BUFF_SIZE 1000000
# define WIDTH 960
# define HEIGHT 540
# define FOV 0.66
# define SPEED 0.1
# define ROT_SPEED 0.05


# ifdef __APPLE__
// Keycodes para macOS (MiniLibX OpenGL)
#  define KEY_ESC 53
#  define KEY_W   13
#  define KEY_A   0
#  define KEY_S   1
#  define KEY_D   2
# else
#  define KEY_ESC 65307
#  define KEY_W   119
#  define KEY_A   97
#  define KEY_S   115
#  define KEY_D   100
# endif

typedef struct s_ray
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	/*Posiciones centradas +0.5*/
	double	pos_x;
	double	pos_y;
	/*Direccion numerica jugador*/
	double	dir_x;
	double	dir_y;
	/*Plano perpendicular a la dirección en la que mira el jugador,
	respresenta el ancho de la cámara en 2D*/
	double	plane_x;
	double	plane_y;
	/*ALGORITMO*/
	/* coordenadas enteras de la celda del mapa donde se encuentra
	actualmente el rayo*/
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	// para dibujo
	int		line_height;
	int		draw_start;
	int		draw_end;

}				t_ray;


typedef struct s_corner
{
	char	upright;
	char	upleft;
	char	downright;
	char	downleft;
}			   t_corner;

typedef struct s_vec3
{
	char *color;
	int r;
	int g;
	int b;
}               t_vec3;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			   t_texture;

typedef struct s_map
{
	char	**map;
    char	**copy;
}               t_map;

typedef struct s_map_file
{
	char	**file_matrix;
	int		fd_map_file;
	int		count_f;
    int		count_c;
}				t_map_file;

typedef struct s_game
{
	int 	x_plyr;
	int 	y_plyr;
	char	dir;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double pos_x;
	double pos_y;

}				t_game;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}				t_window;

typedef struct s_pgm
{
	t_map_file	map_file;
	t_vec3		floor;
	t_vec3		ceiling;
	t_texture	texture;
    t_map   	map;
	t_game  	game;
	t_window   	window;
	
}               t_pgm;

// * parsing/parsing.c
int	ft_parsing(int argc, char *map, t_pgm *pgm);
// ! static int	ft_split_map_file(char *argv_map, t_pgm *pgm);
int	ft_validate_extension(char *file, char *ext);

// * parsing/parsing_map_file.c 
// ! static int ft_validate_identifiers(t_pgm *pgm);
// ! static int	ft_check_id_order(t_pgm *pgm);
// ! static int ft_validate_textures(t_pgm *pgm);
// ! static int ft_validate_floor_ceiling(t_pgm *pgm);
int	ft_validate_map_file(t_pgm *pgm);

// * parsing/parsing_fc_color.c
int ft_check_fc_amount(t_pgm *pgm);
int ft_check_id_before_map(t_pgm *pgm);
// ! static int ft_check_rgb_format(char *rgb_format);
// ! static int ft_take_rgb_format(t_pgm *pgm);
int ft_take_fc_content(t_pgm *pgm);

// * parsing/parsing_fc_color_two.c
// ! static int ft_extract_rgb_value(char **color_str);
int ft_check_rgb_value(char *color, t_vec3 *vec);

// * parsing/parsing_textures.c
// ! static int	ft_validate_textures_content(t_pgm *pgm);
int ft_check_texture_amount(t_pgm *pgm);
int	ft_take_textures_content(t_pgm *pgm);

// * parsing/parsing_map.c
int	ft_is_map_line(char *line);
// ! static int	ft_find_map_start(char **map_file);
int	ft_extract_map(t_pgm *pgm);
int	ft_validate_map(t_pgm *pgm);

// * parsing/parsing_map_two.c
int	ft_check_number_of_players(t_pgm *pgm);
// ! static int	ft_is_invalid_position(char **copy_map, int x, int y);
int ft_check_player_position(t_pgm *pgm);
// ! static int	ft_is_valid_corner(t_pgm *pgm);
int	ft_validate_fully_closed_map(t_pgm *pgm);

// * parsing/parsing_map_three.c
// ! static void	ft_get_map_dimensions(char **map, int *rows, int *cols);
int	ft_is_map_open_ext(int row, int col, char **map);
int	ft_is_map_open_int(t_pgm *pgm);
int	ft_outside_element(t_pgm *pgm);

// rendering/window.c
int ft_open_window(t_pgm *pgm);
int	ft_close_window(t_pgm *pgm);

// * utils/parsing_utils.c
void	ft_init_struct_parsing(t_pgm *pgm);
int		ft_is_player_char(char c);
int		ft_look_around(char **copy, int x, int y);

// * utils/rendering_utils.c
void	ft_init_struct_rendering(t_pgm *pgm);

// * utils.c 
int    ft_print_error(char *msg, int error_code);
// ! static void	ft_free_matirx(char **matrix);
void	ft_free(t_pgm *pgm);


/* FUNCIONES DE EJECUCION DE JUAN*/
/*renderer.c*/
int ft_render_frame(t_pgm *pgm);
/*PARSEO QUE NO HA HECHO SERGIO Y LE HA TOCADO HACER A JUAN CUANDO ERA LA PARTE
MAS FACIL*/
void	ft_init_player_orientation(t_game *game);
int	ft_handle_keys(int keycode, t_pgm *pgm);
/*MOVEMENT*/
void move_forward(t_pgm *pgm);
void move_backward(t_pgm *pgm);
void rotate_left(t_pgm *pgm);
void rotate_right(t_pgm *pgm);
# endif