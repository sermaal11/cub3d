/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:01:54 by jariskan          #+#    #+#             */
/*   Updated: 2025/05/01 16:16:01 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
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
		if (!ft_strchr(" 10NSWED", line[i]))
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
	int	start;
	int	map_lines;

	start = ft_find_map_start(pgm->map_file.file_matrix);
	if (start == -1)
		return (ft_print_error("Error:\nMap not found in file.\n", 1));
	if (ft_alloc_map_storage(pgm, start, &map_lines))
		return (1);
	if (ft_fill_map_lines(pgm, start, map_lines))
		return (1);
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
