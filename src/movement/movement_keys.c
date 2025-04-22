/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/04/22 20:51:22 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_handle_inputs(t_pgm *pgm)
{
	if (pgm->keys.w)
		move_forward(pgm);
	if (pgm->keys.s)
		move_backward(pgm);
	if (pgm->keys.a)
		strafe_left(pgm);
	if (pgm->keys.d)
		strafe_right(pgm);
	if (pgm->keys.left)
		rotate_left(pgm);
	if (pgm->keys.right)
		rotate_right(pgm);
}



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

