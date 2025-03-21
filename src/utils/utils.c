/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:33:54 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/21 12:11:49 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
