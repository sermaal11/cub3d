/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:33:54 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/19 12:09:50 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_print_error(char *msg, int error_code)
{
	printf("%s", msg);
	return (error_code);
}

static void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_free(t_pgm *pgm)
{
	if (pgm->map_file.file_matrix)
		ft_free_matrix(pgm->map_file.file_matrix);
	if (pgm->map.map)
		ft_free_matrix(pgm->map.map);
	if (pgm->map.copy)
		ft_free_matrix(pgm->map.copy);
	if (pgm->texture.no)
		free(pgm->texture.no);
	if (pgm->texture.so)
		free(pgm->texture.so);
	if (pgm->texture.we)
		free(pgm->texture.we);
	if (pgm->texture.ea)
		free(pgm->texture.ea);
	if (pgm->floor.color)
		free(pgm->floor.color);
	if (pgm->ceiling.color)
		free(pgm->ceiling.color);
}

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
