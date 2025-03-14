/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:53:30 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/15 11:42:39 by jariskan         ###   ########.fr       */
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
    char	**copy_map;
	
}               t_map;

typedef struct s_map_file
{
	char	**map_file_matrix;
	int		fd_map_file;
	int		count_f;
    int		count_c;
	
}				t_map_file;


typedef struct s_pgm
{
	t_map_file	map_file;
	t_vec3		floor;
	t_vec3		ceiling;
	t_texture	texture;
    t_map   	map;
	
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
int	ft_parsing(int argc, char *map, t_pgm *pgm);

// * parsing_map_file.c
// ! static int ft_validate_identifiers(t_pgm *pgm);
// ! static int ft_validate_floor_ceiling(t_pgm *pgm);
// ! static int ft_validate_textures(t_pgm *pgm);
int	ft_validate_map_file(t_pgm *pgm);

// * parsing_fc_color.c
int ft_check_fc_amount(t_pgm *pgm);
int ft_check_id_before_map(t_pgm *pgm);
// ! static int ft_check_rgb_format(char *rgb_format);
// ! static int ft_take_rgb_format(t_pgm *pgm);
int ft_take_fc_content(t_pgm *pgm);

// * parsing_fc_color_two.c
// ! static int ft_extract_rgb_value(char **color_str);
int ft_check_rgb_value(char *color, t_vec3 *vec);

// * parsing_textures.c
int ft_check_texture_amount(t_pgm *pgm);

// * utils.c
int    ft_print_error(char *msg, int error_code);

# endif