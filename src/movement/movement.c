/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:26:58 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/21 23:46:37 by volmer           ###   ########.fr       */
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
