/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/21 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forward(t_pgm *pgm)
{
	if (pgm->map.map[(int)(pgm->game.pos_y)]
		[(int)(pgm->game.pos_x + pgm->game.dir_x * SPEED)] != '1')
		pgm->game.pos_x += pgm->game.dir_x * SPEED;
	if (pgm->map.map[(int)(pgm->game.pos_y + pgm->game.dir_y * SPEED)]
		[(int)(pgm->game.pos_x)] != '1')
		pgm->game.pos_y += pgm->game.dir_y * SPEED;
}

void	move_backward(t_pgm *pgm)
{
	if (pgm->map.map[(int)(pgm->game.pos_y)]
		[(int)(pgm->game.pos_x - pgm->game.dir_x * SPEED)] != '1')
		pgm->game.pos_x -= pgm->game.dir_x * SPEED;
	if (pgm->map.map[(int)(pgm->game.pos_y - pgm->game.dir_y * SPEED)]
		[(int)(pgm->game.pos_x)] != '1')
		pgm->game.pos_y -= pgm->game.dir_y * SPEED;
}

void	rotate_left(t_pgm *pgm)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pgm->game.dir_x;
	old_plane_x = pgm->game.plane_x;
	pgm->game.dir_x = pgm->game.dir_x * cos(-ROT_SPEED)
		- pgm->game.dir_y * sin(-ROT_SPEED);
	pgm->game.dir_y = old_dir_x * sin(-ROT_SPEED)
		+ pgm->game.dir_y * cos(-ROT_SPEED);
	pgm->game.plane_x = pgm->game.plane_x * cos(-ROT_SPEED)
		- pgm->game.plane_y * sin(-ROT_SPEED);
	pgm->game.plane_y = old_plane_x * sin(-ROT_SPEED)
		+ pgm->game.plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_pgm *pgm)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pgm->game.dir_x;
	old_plane_x = pgm->game.plane_x;
	pgm->game.dir_x = pgm->game.dir_x * cos(ROT_SPEED)
		- pgm->game.dir_y * sin(ROT_SPEED);
	pgm->game.dir_y = old_dir_x * sin(ROT_SPEED)
		+ pgm->game.dir_y * cos(ROT_SPEED);
	pgm->game.plane_x = pgm->game.plane_x * cos(ROT_SPEED)
		- pgm->game.plane_y * sin(ROT_SPEED);
	pgm->game.plane_y = old_plane_x * sin(ROT_SPEED)
		+ pgm->game.plane_y * cos(ROT_SPEED);
}