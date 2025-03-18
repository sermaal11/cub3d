/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:35:23 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/18 12:51:28 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	ft_check_number_of_players(t_pgm *pgm)
{
	int i;
	int j;
	int player_count;

	i = 0;
	player_count = 0;
	while (pgm->map.copy_map[i])
	{
		j = 0;
		while (pgm->map.copy_map[i][j])
		{
			if (ft_is_player_char(pgm->map.copy_map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count == 0)
		return (ft_print_error("Error:\nNo player found in map.\n", 1));
	if (player_count > 1)
		return (ft_print_error("Error:\nMultiple player found in map.\n", 1));
	return (0);
}
