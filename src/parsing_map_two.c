/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:35:23 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/18 15:31:12 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	ft_check_number_of_players(t_pgm *pgm)
{
	int	i;
	int	j;
	int	player_count;

	i = -1;
	player_count = 0;
	while (pgm->map.copy_map[++i])
	{
		j = -1;
		while (pgm->map.copy_map[i][++j])
		{
			if (ft_is_player_char(pgm->map.copy_map[i][j]))
			{
				pgm->game.x_plyr = i;
				pgm->game.y_plyr = j;
				pgm->game.dir = pgm->map.copy_map[i][j];
				player_count++;
			}
		}
	}
	if (player_count == 0)
		return (ft_print_error("Error:\nNo player found in map.\n", 1));
	if (player_count > 1)
		return (ft_print_error("Error:\nMultiple player found in map.\n", 1));
	return (0);
}

static int	ft_is_invalid_position(char **copy_map, int x, int y)
{
	if (x == 0 || y == 0 || !copy_map[y + 1] || !copy_map[y][x + 1])
		return (1);
	if (copy_map[y - 1][x] == ' ' || copy_map[y + 1][x] == ' ' ||
		copy_map[y][x - 1] == ' ' || copy_map[y][x + 1] == ' ' )
		return (1);
	return (0);
}

int	ft_check_player_position(t_pgm *pgm)
{
	int	i;
	int	j;

	i = 0;
	while (pgm->map.copy_map[i])
	{
		j = 0;
		while (pgm->map.copy_map[i][j])
		{
			if (ft_is_player_char(pgm->map.copy_map[i][j]))
			{
				if (ft_is_invalid_position(pgm->map.copy_map, j, i))
					return (ft_print_error("Error:\nInvalid position.\n", 1));
			}
			j++;
		}
		i++;
	}
	return (0);
}

// int	ft_validate_fully_closed_map(t_pgm *pgm)
// {
	
// 	return (0);
// }
