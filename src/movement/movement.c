/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:26:58 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/21 18:16:15 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_handle_keys(int keycode, t_pgm *pgm)
{
	if (keycode == ESC)
		ft_close_window(pgm);
	if (keycode == W)
	{
		if (pgm->map.map[(int)(pgm->game.pos_y)]
	                [(int)(pgm->game.pos_x + pgm->game.dir_x * SPEED)] != '1')
			pgm->game.pos_x += pgm->game.dir_x * SPEED;
		if (pgm->map.map[(int)(pgm->game.pos_y + pgm->game.dir_y * SPEED)]
	            [(int)(pgm->game.pos_x)] != '1')
		pgm->game.pos_y += pgm->game.dir_y * SPEED;	
	}
	if (keycode == S)
	{
		//logica atrás satanás
	}
	return 0;
}