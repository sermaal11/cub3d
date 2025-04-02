/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:05:40 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/02 12:02:42 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct_parsing(t_pgm *pgm)
{
	ft_bzero(pgm, sizeof(t_pgm));
	pgm->map_file.file_matrix = NULL;
	pgm->map_file.fd_map_file = -1;
	pgm->map_file.count_f = 0;
	pgm->map_file.count_c = 0;
	pgm->floor.color = NULL;
	pgm->floor.r = 0;
	pgm->floor.g = 0;
	pgm->floor.b = 0;
	pgm->ceiling.color = NULL;
	pgm->ceiling.r = 0;
	pgm->ceiling.g = 0;
	pgm->ceiling.b = 0;
	pgm->texture.no = NULL;
	pgm->texture.so = NULL;
	pgm->texture.we = NULL;
	pgm->texture.ea = NULL;
	pgm->map.map = NULL;
	pgm->map.copy = NULL;
	pgm->game.x_plyr = -1;
	pgm->game.y_plyr = -1;
	pgm->game.dir = '\0';
}

int	ft_is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	ft_look_around(char **copy, int x, int y)
{
	t_corner	corner;

	corner.upright = 'V';
	corner.upleft = 'V';
	corner.downright = 'V';
	corner.downleft = 'V';
	if (copy[x + 1][y + 1])
		corner.upright = copy[x + 1][y + 1];
	if (copy[x - 1][y + 1])
		corner.upleft = copy[x - 1][y + 1];
	if (copy[x + 1][y - 1])
		corner.downright = copy[x + 1][y - 1];
	if (copy[x - 1][y - 1])
		corner.downleft = copy[x - 1][y - 1];
	if (corner.upright == ' ' || corner.upleft == ' '
		|| corner.downright == ' ' || corner.downleft == ' '
		|| corner.upright == 'V' || corner.upleft == 'V'
		|| corner.downright == 'V' || corner.downleft == 'V')
		return (1);
	return (0);
}
