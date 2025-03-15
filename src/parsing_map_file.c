/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:14:59 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/15 12:09:05 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// ToDo: Meter en los archivos de parseo de mapa.
int	ft_is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" 10NSEW", line[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_validate_identifiers(t_pgm *pgm)
{
	int		i;
	char	*line;

	i = 0;
	while (pgm->map_file.map_file_matrix[i])
	{
		line = pgm->map_file.map_file_matrix[i];
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
			return (ft_print_error("Error:\nInvalid identifier found.\n", 1));
		i++;
	}
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

// TODO: 3 Validar contenido de texturas con ft_take_textures_content
static int	ft_validate_textures(t_pgm *pgm)
{
	if (ft_check_texture_amount(pgm))
		return (ft_print_error("Error:\nInvalid check textures amount.\n", 1));
	return (0);
}

// TODO: 3. Validar mapa con todos los casos limite y guradar cada cosa en su sitio.
int	ft_validate_map_file(t_pgm *pgm)
{
	if (ft_validate_identifiers(pgm))
		return (ft_print_error("Error:\nInvalid identifier.\n", 1));
	if (ft_check_id_before_map(pgm))
		return (ft_print_error("Error:\nInvalid check ID position\n", 1));
	if (ft_validate_floor_ceiling(pgm))
		return (ft_print_error("Error:\nInvalid FC format.\n", 1));
	if (ft_validate_textures(pgm))
		return (ft_print_error("Error:\nInvalid textures format.\n", 1));
	return (0);
}
