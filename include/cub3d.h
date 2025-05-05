/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:53:30 by smarin-a          #+#    #+#             */
/*   Updated: 2025/05/05 15:11:25 by jdelorme         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080
# define FOV 0.66
# define SPEED 0.05
# define ROT_SPEED 0.03
# define MINIMAP_SCALE 30
# define WEAPON_OSCILLATION_UP 20
# define WEAPON_OSCILLATION_DOWN 0
# define WEAPON_OSCILLATION_MAX 12
# define WEAPON_OSCILLATION_MIN 0.0
# define WEAPON_OSCILLATION_SPEED 1.1
# define WEAPON_RETURN_SPEED 1.5
# define WEAPON_IDLE_THRESHOLD 0.1
# define WEAPON_UP 1
# define WEAPON_DOWN -1
#define WEAPON_SCALE 1.5


# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

struct	s_img;
typedef struct s_img t_img;

/* =========================== STRUCTS DE APOYO ============================ */

typedef struct s_texdraw {
	t_img	*texture;
	int		tex_x;
	double	step;
	double	tex_pos;
} t_texdraw;

typedef struct s_minimap_row {
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
} t_minimap_row;

typedef struct s_draw_square {
	int	dx;
	int	dy;
	int	tile;
	int	cx;
	int	cy;
	int	radius;
} t_draw_square;

typedef struct s_circle_check {
	int	dx;
	int	dy;
	int	distance_squared;
} t_circle_check;

typedef struct s_draw_player {
	int	cx;
	int	cy;
	int	dx;
	int	dy;
} t_draw_player;

typedef struct s_circle {
	int	x;
	int	y;
	int	cx;
	int	cy;
	int	radius;
} t_circle;

/* ============================ STRUCTS BASE =============================== */

typedef struct s_keys {
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
} t_keys;

typedef struct s_ray {
	int		x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
} t_ray;

typedef struct s_corner {
	char	upright;
	char	upleft;
	char	downright;
	char	downleft;
} t_corner;

typedef struct s_vec3 {
	char	*color;
	int	r;
	int	g;
	int	b;
} t_vec3;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
} t_img;

typedef struct s_texture {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
} t_texture;

typedef struct s_map {
	char	**map;
	char	**copy;
	int		width;
	int		height;
} t_map;

typedef struct s_map_file {
	char	**file_matrix;
	int		fd_map_file;
	int		count_f;
	int		count_c;
} t_map_file;

typedef struct s_game {
	int		x_plyr;
	int		y_plyr;
	char	dir;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
} t_game;

typedef struct s_window {
	void	*mlx;
	void	*win;
} t_window;

typedef struct s_pgm {
	t_map_file	map_file;
	t_vec3		floor;
	t_vec3		ceiling;
	t_texture	texture;
	t_map		map;
	t_game		game;
	t_window	window;
	t_img		frame;
	t_keys		keys;
	t_img		weapon_img;
	int			weapon_offset;
	int			weapon_frame;
	double		weapon_offset_float;
	int			weapon_direction;

} t_pgm;

/* ========================= FUNCIONES DE SERGIO =========================== */

int	ft_parsing(int argc, char *map, t_pgm *pgm);
int	ft_validate_extension(char *file, char *ext);
int	ft_validate_map_file(t_pgm *pgm);
int	ft_check_fc_amount(t_pgm *pgm);
int	ft_check_id_before_map(t_pgm *pgm);
int	ft_take_fc_content(t_pgm *pgm);
int	ft_check_rgb_value(char *color, t_vec3 *vec);
int	ft_check_texture_amount(t_pgm *pgm);
int	ft_take_textures_content(t_pgm *pgm);
int	ft_is_map_line(char *line);
int	ft_extract_map(t_pgm *pgm);
int	ft_validate_map(t_pgm *pgm);
int	ft_check_number_of_players(t_pgm *pgm);
int	ft_check_player_position(t_pgm *pgm);
int	ft_validate_fully_closed_map(t_pgm *pgm);
int	ft_is_map_open_ext(int row, int col, char **map);
int	ft_is_map_open_int(t_pgm *pgm);
int	ft_outside_element(t_pgm *pgm);
int	ft_open_window(t_pgm *pgm);
int	ft_close_window(t_pgm *pgm);
void	ft_init_struct_parsing(t_pgm *pgm);
int	ft_is_player_char(char c);
int	ft_look_around(char **copy, int x, int y);
int	ft_print_error(char *msg, int error_code);
void	ft_free(t_pgm *pgm);

/* ========================== FUNCIONES DE JUAN ============================ */

/* === CALCULO (RAYCAST) === */
void	ft_init_ray_direction(t_ray *ray, t_pgm *pgm);
void	ft_init_ray_for_column(t_ray *ray);
void	ft_init_ray_step_and_side_distance(t_ray *ray);
void	ft_find_wall_hit(t_ray *ray, char **map);
void	ft_calc_perp_wall_dist(t_ray *ray);
void	ft_calc_wall_strip(t_ray *ray);

/* === RENDERIZADO === */
int	ft_render_frame(t_pgm *pgm);
void	ft_draw_ceiling_and_floor(t_ray *ray, t_pgm *pgm);
void	ft_draw_column(t_ray *ray, t_pgm *pgm);
void	ft_draw_wall_stripe(t_ray *ray, t_pgm *pgm, t_texdraw d);
void	ft_put_pixel(t_img *img, int x, int y, int color);
t_img	*ft_get_texture(t_ray *ray, t_pgm *pgm);
int	ft_get_tex_x(t_ray *ray, double wall_x, t_img *texture);
double	ft_get_wall_hit_point(t_ray *ray);
void	ft_init_tex_step(t_ray *ray, t_img *texture, double *step, double *tex_pos);

/* === BONUS (MINIMAPA, INPUTS, MOVIMIENTO, TEXTURAS) === */
void	ft_draw_minimap_tiles(t_pgm *pgm, int offset, double cx, double cy);
void	ft_draw_square(t_pgm *pgm, int x, int y, int color);
void	ft_draw_player(t_pgm *pgm);
int		get_tile_color(t_pgm *pgm, int map_y, int map_x);
int		is_inside_circle(t_circle c);
void	draw_minimap_background(t_pgm *pgm, int cx, int cy, int radius);
void	ft_render_minimap(t_pgm *pgm);

void	ft_load_all_textures(t_pgm *pgm);
void	ft_load_texture(t_pgm *pgm, t_img *img, char *path);

void	move_forward(t_pgm *pgm);
void	move_backward(t_pgm *pgm);
void	rotate_left(t_pgm *pgm);
void	rotate_right(t_pgm *pgm);
void	strafe_left(t_pgm *pgm);
void	strafe_right(t_pgm *pgm);

void	ft_handle_inputs(t_pgm *pgm);
int		key_press(int keycode, t_pgm *pgm);
int		key_release(int keycode, t_pgm *pgm);

void	ft_init_player_orientation(t_game *game);
void	ft_init_struct_rendering(t_pgm *pgm);

int		ft_rgb_to_int(t_vec3 color);
int		ft_map_width(char **map);
int		ft_alloc_map_storage(t_pgm *pgm, int start, int *map_lines);
int		ft_fill_map_lines(t_pgm *pgm, int start, int map_lines);

#endif
