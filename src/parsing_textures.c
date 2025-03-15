/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:58:08 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/15 11:42:06 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_texture_amount(t_pgm *pgm)
{
	int	i;
	int	no;
	int	so;
	int	ea;
	int	we;

	i = -1;
	no = 0;
	so = 0;
	ea = 0;
	we = 0;
	while (pgm->map_file.map_file_matrix[++i])
	{
		if (ft_strncmp(pgm->map_file.map_file_matrix[i], "NO ", 3) == 0)
			no++;
		else if (ft_strncmp(pgm->map_file.map_file_matrix[i], "SO ", 3) == 0)
			so++;
		else if (ft_strncmp(pgm->map_file.map_file_matrix[i], "EA ", 3) == 0)
			ea++;
		else if (ft_strncmp(pgm->map_file.map_file_matrix[i], "WE ", 3) == 0)
			we++;
	}
	if (no != 1 || so != 1 || ea != 1 || we != 1)
		return (ft_print_error("Error:\nInvalid number of textures.\n", 1));
	return (0);
}
