/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:53:30 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/19 11:25:15 by jariskan         ###   ########.fr       */
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
	
}				t_game;


typedef struct s_pgm
{
	t_map_file	map_file;
	t_vec3		floor;
	t_vec3		ceiling;
	t_texture	texture;
    t_map   	map;
	t_game  	game;
	
}               t_pgm;

typedef struct	s_data 
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}				t_data;

// * parsing.c
// ? (3 funciones)
int	ft_parsing(int argc, char *map, t_pgm *pgm);
// ! static int	ft_split_map_file(char *argv_map, t_pgm *pgm);
int	ft_validate_extension(char *file, char *ext);

// * parsing_map_file.c 
// ! (5 funciones)
// ! static int ft_validate_identifiers(t_pgm *pgm);
// ! static int	ft_check_id_order(t_pgm *pgm);
// ! static int ft_validate_textures(t_pgm *pgm);
// ! static int ft_validate_floor_ceiling(t_pgm *pgm);
int	ft_validate_map_file(t_pgm *pgm);

// * parsing_fc_color.c
// ! (5 funciones)
int ft_check_fc_amount(t_pgm *pgm);
int ft_check_id_before_map(t_pgm *pgm);
// ! static int ft_check_rgb_format(char *rgb_format);
// ! static int ft_take_rgb_format(t_pgm *pgm);
int ft_take_fc_content(t_pgm *pgm);

// * parsing_fc_color_two.c
// ? (2 funciones)
// ! static int ft_extract_rgb_value(char **color_str);
int ft_check_rgb_value(char *color, t_vec3 *vec);

// * parsing_textures.c
// ? (3 funciones)
// ! static int	ft_validate_textures_content(t_pgm *pgm);
int ft_check_texture_amount(t_pgm *pgm);
int	ft_take_textures_content(t_pgm *pgm);

// * parsing_map.c
// ! (4 funciones)
int	ft_is_map_line(char *line);
// ! static int	ft_find_map_start(char **map_file);
int	ft_extract_map(t_pgm *pgm);
int	ft_validate_map(t_pgm *pgm);

// * parsing_map_two.c
// ! (5 funciones)
// ! static int	ft_is_player_char(char c);
int	ft_check_number_of_players(t_pgm *pgm);
// ! static int	ft_is_invalid_position(char **copy_map, int x, int y);
int ft_check_player_position(t_pgm *pgm);
int	ft_validate_fully_closed_map(t_pgm *pgm);

// ? parsing_map_three.c
// ! static void	ft_get_map_dimensions(char **map, int *rows, int *cols);
int	ft_is_map_open_ext(int row, int col, char **map);
int	ft_is_map_open_int(t_pgm *pgm);
int	ft_outside_element(t_pgm *pgm);

// * utils.c 
// ? (3 funciones)
int    ft_print_error(char *msg, int error_code);
// ! static void	ft_free_matirx(char **matrix);
void	ft_free(t_pgm *pgm);

# endif