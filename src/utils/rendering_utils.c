/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:50:15 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/22 13:33:18 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct_rendering(t_pgm *pgm)
{
	pgm->window.mlx = NULL;
	pgm->window.win = NULL;	
}
void	ft_init_player_orientation(t_game *game)
{
	if (game->dir == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	if (game->dir == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	if (game->dir == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	if (game->dir == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
}
int ft_rgb_to_int(t_vec3 color)
{
	return ((int)(color.r) << 16 | (int)(color.g) << 8 | (int)(color.b));
}