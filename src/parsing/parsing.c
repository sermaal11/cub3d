/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:09:59 by smarin-a          #+#    #+#             */
/*   Updated: 2025/05/06 13:43:47 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_alloc_map_storage(t_pgm *pgm, int start, int *map_lines)
{
	*map_lines = 0;
	while (pgm->map_file.file_matrix[start + *map_lines])
		(*map_lines)++;
	pgm->map.map = malloc(sizeof(char *) * (*map_lines + 1));
	pgm->map.copy = malloc(sizeof(char *) * (*map_lines + 1));
	if (!pgm->map.map || !pgm->map.copy)
		return (ft_print_error("Error:\nFailed malloc for map.\n", 1));
	return (0);
}

int	ft_fill_map_lines(t_pgm *pgm, int start, int map_lines)
{
	int	i;

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
	return (0);
}

int	ft_validate_extension(char *file, char *ext)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + (len - 4), ext, 4) != 0)
		return (1);
	return (0);
}

static int	ft_split_map_file(char *argv_map, t_pgm *pgm)
{
	char	*line_map;
	ssize_t	line_len_map;

	pgm->map_file.fd_map_file = open(argv_map, O_RDONLY);
	if (pgm->map_file.fd_map_file == -1)
		return (1);
	line_map = malloc(MAP_BUFF_SIZE * sizeof(char));
	if (!line_map)
		return (1);
	line_len_map = read(pgm->map_file.fd_map_file, line_map, MAP_BUFF_SIZE - 1);
	if (line_len_map <= 0)
	{
		free(line_map);
		return (1);
	}
	line_map[line_len_map] = '\0';
	pgm->map_file.file_matrix = ft_split(line_map, '\n');
	if (!pgm->map_file.file_matrix)
		return (1);
	free(line_map);
	return (0);
}

int	ft_parsing(int argc, char *argv_map, t_pgm *pgm)
{
	if (argc != 2)
		return (ft_print_error("Error:\nInvalid number of arguments.\n", 1));
	if (ft_validate_extension(argv_map, ".cub"))
		return (ft_print_error("Error:\nInvalid map extension.\n", 1));
	if (ft_split_map_file(argv_map, pgm))
		return (ft_print_error("Error:\nFailed to split map file.\n", 1));
	if (ft_validate_map_file(pgm))
		return (ft_print_error("Error:\nFailed to validate map file.\n", 1));
	return (0);
}
