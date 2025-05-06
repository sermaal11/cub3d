/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:23:30 by jariskan          #+#    #+#             */
/*   Updated: 2025/05/06 11:30:08 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_map_dimensions(char **map, int *rows, int *cols)
{
	int	i;
	int	row_length;

	*rows = 0;
	*cols = 0;
	i = 0;
	while (map[*rows])
		(*rows)++;
	while (i < *rows)
	{
		row_length = ft_strlen(map[i]);
		if (row_length > *cols)
			*cols = row_length;
		i++;
	}
}

int	ft_is_map_open_ext(int row, int col, char **map)
{
	int	rows;
	int	cols;

	ft_get_map_dimensions(map, &rows, &cols);
	if (row < 0 || col < 0 || row >= rows || col >= (int)ft_strlen(map[row]))
		return (1);
	if (map[row][col] == '1' || map[row][col] == 'X' || map[row][col] == ' ')
		return (0);
	map[row][col] = 'X';
	if (ft_is_map_open_ext(row - 1, col, map))
		return (1);
	if (ft_is_map_open_ext(row + 1, col, map))
		return (1);
	if (ft_is_map_open_ext(row, col - 1, map))
		return (1);
	if (ft_is_map_open_ext(row, col + 1, map))
		return (1);
	return (0);
}

int	ft_is_map_open_int(t_pgm *pgm)
{
	int	i;
	int	j;

	i = 0;
	while (pgm->map.copy[i])
	{
		j = 0;
		while (pgm->map.copy[i][j])
		{
			if (pgm->map.copy[i][j] == ' ' &&
				((i > 0 && pgm->map.copy[i - 1][j] == 'X') ||
				(pgm->map.copy[i + 1] && pgm->map.copy[i + 1][j] == 'X') ||
				(j > 0 && pgm->map.copy[i][j - 1] == 'X') ||
				(pgm->map.copy[i][j + 1] && pgm->map.copy[i][j + 1] == 'X')))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_outside_element(t_pgm *pgm)
{
	int	i;
	int	j;

	i = 0;
	while (pgm->map.copy[i])
	{
		j = 0;
		while (pgm->map.copy[i][j])
		{
			if (pgm->map.copy[i][j] != 'X' && pgm->map.copy[i][j] != '1' &&
				!ft_isspace(pgm->map.copy[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
