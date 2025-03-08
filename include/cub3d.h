/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:53:30 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/05 19:44:11 by smarin-a         ###   ########.fr       */
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

# define MAP_BUFFER_SIZE 1000000

typedef struct s_vec3
{
	int r;
	int g;
	int b;
}               t_vec3;

typedef struct s_texture
{
	int		texture_flag;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			   t_texture;

typedef struct s_map
{
	int		fd_map;
    char	**map;
    char	**copy_map;
	
}               t_map;

typedef struct s_pgm
{
    t_map   	map;
	t_vec3		floor; 
	t_vec3		ceiling;
	t_texture	texture;
        
}               t_pgm;

typedef struct	s_data 
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}				t_data;

// parsing.c
int	ft_parsing(int argc, char *map, t_pgm *pgm);

// utils.c
int    ft_print_error(char *msg, int error_code);
# endif