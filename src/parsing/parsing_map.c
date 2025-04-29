/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:01:54 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/25 18:55:16 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_width(char **map)
{
	int	i = 0;
	int	max = 0;
	int	len;

	while (map && map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	ft_is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!ft_strchr(" 1", line[i]))
		return (1);
	while (line[i])
	{
		if (!ft_strchr(" 10NSWE", line[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_find_map_start(char **map_file)
{
	int	i;

	i = 0;
	while (map_file[i])
	{
		if (ft_strchr("1 ", map_file[i][0]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_extract_map(t_pgm *pgm)
{
	int		start;
	int		map_lines;
	int		i;

	start = ft_find_map_start(pgm->map_file.file_matrix);
	if (start == -1)
		return (ft_print_error("Error:\nMap not found in file.\n", 1));
	map_lines = 0;
	while (pgm->map_file.file_matrix[start + map_lines])
		map_lines++;
	pgm->map.map = (char **)malloc(sizeof(char *) * (map_lines + 1));
	pgm->map.copy = (char **)malloc(sizeof(char *) * (map_lines + 1));
	if (!pgm->map.map || !pgm->map.copy)
		return (ft_print_error("Error:\nFailed malloc for map.\n", 1));
	i = -1;
	while (++i < map_lines)
	{
		pgm->map.map[i] = ft_strdup(pgm->map_file.file_matrix[start + i]);
		pgm->map.copy[i] = ft_strdup(pgm->map_file.file_matrix[start + i]);
		if (!pgm->map.map[i] || !pgm->map.copy[i])
			return (ft_print_error("Error:\nFailed malloc for map rows.\n", 1));
	}
	pgm->map.map[i] = NULL;
	pgm->map.copy[i] = NULL;
	pgm->map.height = map_lines;
	pgm->map.width = ft_map_width(pgm->map.map);
	return (0);
}

int	ft_validate_map(t_pgm *pgm)
{
	if (ft_check_number_of_players(pgm))
		return (ft_print_error("Error:\nInvalid number of players.\n", 1));
	if (ft_check_player_position(pgm))
		return (ft_print_error("Error:\nInvalid player position.\n", 1));
	if (ft_validate_fully_closed_map(pgm))
		return (1);
	return (0);
}
