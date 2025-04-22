/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:48:58 by volmer            #+#    #+#             */
/*   Updated: 2025/04/22 20:49:44 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, t_pgm *pgm)
{
	if (keycode == KEY_W)
		pgm->keys.w = 1;
	else if (keycode == KEY_A)
		pgm->keys.a = 1;
	else if (keycode == KEY_S)
		pgm->keys.s = 1;
	else if (keycode == KEY_D)
		pgm->keys.d = 1;
	else if (keycode == KEY_LEFT)
		pgm->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		pgm->keys.right = 1;
	else if (keycode == KEY_ESC)
		ft_close_window(pgm);
	return (0);
}

int	key_release(int keycode, t_pgm *pgm)
{
	if (keycode == KEY_W)
		pgm->keys.w = 0;
	else if (keycode == KEY_A)
		pgm->keys.a = 0;
	else if (keycode == KEY_S)
		pgm->keys.s = 0;
	else if (keycode == KEY_D)
		pgm->keys.d = 0;
	else if (keycode == KEY_LEFT)
		pgm->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		pgm->keys.right = 0;
	return (0);
}
