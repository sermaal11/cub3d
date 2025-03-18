/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:58:08 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/18 09:27:30 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_validate_textures_content(t_pgm *pgm)
{
	if (!pgm->texture.no || !pgm->texture.so
		|| !pgm->texture.ea || !pgm->texture.we)
		return (ft_print_error("Error:\nVoid path.\n", 1));
	if (ft_strncmp(pgm->texture.no, "./textures/", 11) != 0
		|| ft_strncmp(pgm->texture.so, "./textures/", 11) != 0
		|| ft_strncmp(pgm->texture.ea, "./textures/", 11) != 0
		|| ft_strncmp(pgm->texture.we, "./textures/", 11) != 0)
		return (ft_print_error("Error:\nInvalid directory.\n", 1));
	if (ft_strncmp(pgm->texture.no + ft_strlen(pgm->texture.no) - 4, ".xpm", 4) != 0
		|| ft_strncmp(pgm->texture.so + ft_strlen(pgm->texture.so) - 4, ".xpm", 4) != 0
		|| ft_strncmp(pgm->texture.ea + ft_strlen(pgm->texture.ea) - 4, ".xpm", 4) != 0
		|| ft_strncmp(pgm->texture.we + ft_strlen(pgm->texture.we) - 4, ".xpm", 4) != 0)
		return (ft_print_error("Error:\nInvalid path extension.\n", 1));
	return (0);
}

int	ft_take_textures_content(t_pgm *pgm)
{
	int		i;
	char	*line;

	i = 0;
	while (pgm->map_file.map_file_matrix[i])
	{
		line = pgm->map_file.map_file_matrix[i];
		if (ft_strncmp(line, "NO ", 3) == 0)
			pgm->texture.no = ft_strdup(line + 3);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			pgm->texture.so = ft_strdup(line + 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			pgm->texture.ea = ft_strdup(line + 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			pgm->texture.we = ft_strdup(line + 3);
		i++;
	}
	if (ft_validate_textures_content(pgm))
		return (ft_print_error("Error:\nInvalid texture path.\n", 1));
	return (0);
}

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
