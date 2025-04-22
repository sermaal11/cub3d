/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/04/22 20:23:00 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_handle_keys(int keycode, t_pgm *pgm)
{
	if (keycode == KEY_ESC)
		ft_close_window(pgm);
	if (keycode == KEY_W)
		move_forward(pgm);
	else if (keycode == KEY_S)
		move_backward(pgm);
	else if (keycode == KEY_A)
		rotate_left(pgm);
	else if (keycode == KEY_D)
		rotate_right(pgm);
	return (0);
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
