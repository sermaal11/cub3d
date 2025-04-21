/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:26:58 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/21 23:20:05 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_handle_keys(int keycode, t_pgm *pgm)
{
	if (keycode == KEY_ESC)
		ft_close_window(pgm);
	if (keycode == KEY_W)
	{
		if (pgm->map.map[(int)(pgm->game.pos_y)]
	                [(int)(pgm->game.pos_x + pgm->game.dir_x * SPEED)] != '1')
			pgm->game.pos_x += pgm->game.dir_x * SPEED;
		if (pgm->map.map[(int)(pgm->game.pos_y + pgm->game.dir_y * SPEED)]
	            [(int)(pgm->game.pos_x)] != '1')
		pgm->game.pos_y += pgm->game.dir_y * SPEED;	
	}
	if (keycode == KEY_S)
	{
		if (pgm->map.map[(int)(pgm->game.pos_y)]
                [(int)(pgm->game.pos_x - pgm->game.dir_x * SPEED)] != '1')
			pgm->game.pos_x -= pgm->game.dir_x * SPEED;

		if (pgm->map.map[(int)(pgm->game.pos_y - pgm->game.dir_y * SPEED)]
                [(int)(pgm->game.pos_x)] != '1')
			pgm->game.pos_y -= pgm->game.dir_y * SPEED;
	}
	if (keycode == KEY_A)
	{
		if (pgm->map.map[(int)(pgm->game.pos_y)]
	               [(int)(pgm->game.pos_x - pgm->game.plane_x * SPEED)] != '1')
			pgm->game.pos_x -= pgm->game.plane_x * SPEED;
		
		if (pgm->map.map[(int)(pgm->game.pos_y - pgm->game.plane_y * SPEED)]
	                [(int)(pgm->game.pos_x)] != '1')
			pgm->game.pos_y -= pgm->game.plane_y * SPEED;
	}
	if (keycode == KEY_D)
	{
		if (pgm->map.map[(int)(pgm->game.pos_y)]
	                [(int)(pgm->game.pos_x + pgm->game.plane_x * SPEED)] != '1')
			pgm->game.pos_x += pgm->game.plane_x * SPEED;

		if (pgm->map.map[(int)(pgm->game.pos_y + pgm->game.plane_y * SPEED)]
	                [(int)(pgm->game.pos_x)] != '1')
			pgm->game.pos_y += pgm->game.plane_y * SPEED;
	}
	return (0);
}
