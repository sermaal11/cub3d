/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:35:23 by jariskan          #+#    #+#             */
/*   Updated: 2025/05/06 11:30:54 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_number_of_players(t_pgm *pgm)
{
	int	i;
	int	j;
	int	player_count;

	i = -1;
	player_count = 0;
	while (pgm->map.copy[++i])
	{
		j = -1;
		while (pgm->map.copy[i][++j])
		{
			if (ft_is_player_char(pgm->map.copy[i][j]))
			{
				pgm->game.x_plyr = i;
				pgm->game.y_plyr = j;
				pgm->game.dir = pgm->map.copy[i][j];
				player_count++;
			}
		}
	}
	if (player_count == 0)
		return (1);
	if (player_count > 1)
		return (1);
	return (0);
}

static int	ft_is_invalid_position(char **copy, int x, int y)
{
	if (x == 0 || y == 0 || !copy[y + 1] || !copy[y][x + 1])
		return (1);
	if (copy[y - 1][x] == ' ' || copy[y + 1][x] == ' ' ||
		copy[y][x - 1] == ' ' || copy[y][x + 1] == ' ' )
		return (1);
	return (0);
}

int	ft_check_player_position(t_pgm *pgm)
{
	int	i;
	int	j;

	i = 0;
	while (pgm->map.copy[i])
	{
		j = 0;
		while (pgm->map.copy[i][j])
		{
			if (ft_is_player_char(pgm->map.copy[i][j]))
			{
				if (ft_is_invalid_position(pgm->map.copy, j, i))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_is_valid_corner(t_pgm *pgm)
{
	int	i;
	int	j;

	i = 0;
	while (pgm->map.copy[i])
	{
		j = 0;
		while (pgm->map.copy[i][j])
		{
			if (pgm->map.copy[i][j] == 'X')
			{
				if (ft_look_around(pgm->map.copy, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_validate_fully_closed_map(t_pgm *pgm)
{
	if (pgm->game.x_plyr < 0 || pgm->game.y_plyr < 0)
		return (1);
	if (ft_is_map_open_ext(pgm->game.x_plyr, pgm->game.y_plyr, pgm->map.copy))
		return (1);
	if (ft_is_valid_corner(pgm))
		return (1);
	if (ft_is_map_open_int(pgm))
		return (1);
	if (ft_outside_element(pgm))
		return (1);
	return (0);
}
