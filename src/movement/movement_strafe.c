/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_strafe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:27:10 by volmer            #+#    #+#             */
/*   Updated: 2025/04/30 00:27:30 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	strafe_left(t_pgm *pgm)
{
	if (pgm->map.map[(int)(pgm->game.pos_y)]
		[(int)(pgm->game.pos_x - pgm->game.plane_x * SPEED)] != '1')
		pgm->game.pos_x -= pgm->game.plane_x * SPEED;
	if (pgm->map.map[(int)(pgm->game.pos_y - pgm->game.plane_y * SPEED)]
		[(int)(pgm->game.pos_x)] != '1')
		pgm->game.pos_y -= pgm->game.plane_y * SPEED;
}

void	strafe_right(t_pgm *pgm)
{
	if (pgm->map.map[(int)(pgm->game.pos_y)]
		[(int)(pgm->game.pos_x + pgm->game.plane_x * SPEED)] != '1')
		pgm->game.pos_x += pgm->game.plane_x * SPEED;
	if (pgm->map.map[(int)(pgm->game.pos_y + pgm->game.plane_y * SPEED)]
		[(int)(pgm->game.pos_x)] != '1')
		pgm->game.pos_y += pgm->game.plane_y * SPEED;
}
