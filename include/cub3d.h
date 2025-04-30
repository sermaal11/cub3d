/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:53:30 by smarin-a          #+#    #+#             */
/*   Updated: 2025/04/30 12:43:25 by jdelorme         ###   ########.fr       */
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
# define WIDTH 1280
# define HEIGHT 720
# define FOV 0.66
# define SPEED 0.05
# define ROT_SPEED 0.03
# define MINIMAP_SCALE 15

# ifdef __APPLE__
// Keycodes para macOS (MiniLibX OpenGL)
#  define KEY_ESC 53
#  define KEY_W   13
#  define KEY_A   0
#  define KEY_S   1
#  define KEY_D   2
#  define KEY_LEFT   123
#  define KEY_RIGHT  124
# else
#  define KEY_ESC 65307
#  define KEY_W   119
#  define KEY_A   97
#  define KEY_S   115
#  define KEY_D   100
#  define KEY_LEFT   65361
#  define KEY_RIGHT  65363
# endif

struct s_img;
typedef struct s_img t_img;


/* ESTRUCTURAS PARA LA NORMINETTE*/

typedef struct s_texdraw
{
	t_img	*texture;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_texdraw;

typedef struct s_minimap_row
{
	int		x;
	int		mx;
	int		my;
	int		col;
	int		sx;
	int		sy;
	double	cx;
	double	cy;
	double	dx_off;
	double	dy_off;
	int		offset;
	int		y;
}	t_minimap_row;

typedef struct s_draw_square
{
	int		dx;
	int		dy;
	int		tile;
	int		cx;
	int		cy;
	int		radius;
}	t_draw_square;

typedef struct s_circle_check
{
	int	dx;
	int	dy;
	int	distance_squared;
}	t_circle_check;

typedef struct s_draw_player
{
	int	cx;
	int	cy;
	int	dx;
	int	dy;
}	t_draw_player;

typedef struct s_circle
{
	int	x;
	int	y;
	int	cx;
	int	cy;
	int	radius;
}	t_circle;


/*FIN DE ESTRUCTURAS PARA LA NORMINETTE*/
typedef struct s_keys
{
	int w;
	int a;
	int s;
	int d;
	int left;
	int right;
}	t_keys;

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

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_img 	img_no;
	t_img 	img_so;
	t_img 	img_we;
	t_img 	img_ea;
}			   t_texture;

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		width;
	int		height;
}	t_map;


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
	t_img 		frame;
	t_keys		keys;
	t_img 		weapon_img;
	int    weapon_offset; // altura vertical para simular el movimiento
	int    weapon_frame;  // para alternar la animación

	
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

/* ************************************************************************** */
/*                               FUNCIONES DE JUAN                            */
/* ************************************************************************** */

/* ------------------------------ RENDERING --------------------------------- */

/* renderer.c */
int		ft_render_frame(t_pgm *pgm);
void	ft_draw_ceiling_and_floor(t_ray *ray, t_pgm *pgm);
void	ft_draw_column(t_ray *ray, t_pgm *pgm);

/* minimap_draw.c */
void	ft_draw_minimap_tiles(t_pgm *pgm, int offset, double cx, double cy);
void	ft_draw_square(t_pgm *pgm, int x, int y, int color);

/* minimap_utils.c */
void	ft_draw_player(t_pgm *pgm);
int		get_tile_color(t_pgm *pgm, int map_y, int map_x);
int		is_inside_circle(t_circle c);

/* minimap_background.c */
void	draw_minimap_background(t_pgm *pgm, int cx, int cy, int radius);

/* texture_render.c */
void	ft_put_pixel(t_img *img, int x, int y, int color);
t_img	*ft_get_texture(t_ray *ray, t_pgm *pgm);

/* texture_math.c */
int		ft_get_tex_x(t_ray *ray, double wall_x, t_img *texture);
double	ft_get_wall_hit_point(t_ray *ray);
void	ft_init_tex_step(t_ray *ray, t_img *texture,
			double *step, double *tex_pos);

/* texture_draw.c */
void	ft_draw_wall_stripe(t_ray *ray, t_pgm *pgm, t_texdraw d);

/* ------------------------------ TEXTURE LOADER ---------------------------- */

void	ft_load_all_textures(t_pgm *pgm);
void	ft_load_texture(t_pgm *pgm, t_img *img, char *path);

/* ------------------------------ MOVEMENT ---------------------------------- */

void	move_forward(t_pgm *pgm);
void	move_backward(t_pgm *pgm);
void	rotate_left(t_pgm *pgm);
void	rotate_right(t_pgm *pgm);
void	strafe_left(t_pgm *pgm);
void	strafe_right(t_pgm *pgm);

/* ------------------------------ INPUTS ------------------------------------ */

void	ft_handle_inputs(t_pgm *pgm);
int		key_press(int keycode, t_pgm *pgm);
int		key_release(int keycode, t_pgm *pgm);

/* ------------------------------ PARSE PLAYER ------------------------------ */

void	ft_init_player_orientation(t_game *game);

/* ------------------------------ UTILS ------------------------------------- */

int		ft_rgb_to_int(t_vec3 color);
int		ft_map_width(char **map);

void	ft_render_minimap(t_pgm *pgm);

# endif