/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:14:59 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/30 13:42:25 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_validate_identifiers(t_pgm *pgm)
{
	int		i;
	char	*line;

	i = 0;
	while (pgm->map_file.file_matrix[i])
	{
		line = pgm->map_file.file_matrix[i];
		if (ft_strncmp(line, "NO ", 3) == 0
			|| ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "F ", 2) == 0
			|| ft_strncmp(line, "C ", 2) == 0)
		{
			i++;
			continue ;
		}
		if (ft_strlen(line) > 0 && ft_is_map_line(line))
			return (ft_print_error("Error:\nInvalid ID found.\n", 1));
		i++;
	}
	return (0);
}

static int	ft_check_id_order(t_pgm *pgm)
{
	int		i;
	int		block_type;
	char	*line;

	i = -1;
	block_type = -1;
	while (pgm->map_file.file_matrix[++i])
	{
		line = pgm->map_file.file_matrix[i];
		if (!line[0] || ft_is_map_line(line) == 0)
			break ;
		if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2))
		{
			if (block_type == 1)
				return (1);
			block_type = 0;
		}
		else if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
			if (block_type == -1 || block_type == 0)
				block_type = 1;
	}
	return (0);
}

static int	ft_validate_textures(t_pgm *pgm)
{
	if (ft_check_texture_amount(pgm))
		return (ft_print_error("Error:\nInvalid check textures amount.\n", 1));
	if (ft_take_textures_content(pgm))
		return (ft_print_error("Error\nInvalid check texture format\n", 1));
	return (0);
}

static int	ft_validate_floor_ceiling(t_pgm *pgm)
{
	if (ft_check_fc_amount(pgm))
		return (ft_print_error("Error:\nInvalid check FC amount.\n", 1));
	if (ft_take_fc_content(pgm))
		return (ft_print_error("Error\nInvalid check RGB format\n", 1));
	return (0);
}

int	ft_validate_map_file(t_pgm *pgm)
{
	if (ft_validate_identifiers(pgm))
		return (ft_print_error("Error:\nInvalid ID.\n", 1));
	if (ft_check_id_order(pgm))
		return (ft_print_error("Error:\nInvalid ID order.\n", 1));
	if (ft_check_id_before_map(pgm))
		return (ft_print_error("Error:\nInvalid ID position\n", 1));
	if (ft_validate_textures(pgm))
		return (ft_print_error("Error:\nInvalid textures format.\n", 1));
	if (ft_validate_floor_ceiling(pgm))
		return (ft_print_error("Error:\nInvalid FC format.\n", 1));
	if (ft_extract_map(pgm))
		return (ft_print_error("Error.\nInvalid map extraction.\n", 1));
	if (ft_validate_map(pgm))
		return (ft_print_error("Error.\nInvalid map format.\n", 1));
	return (0);
}
