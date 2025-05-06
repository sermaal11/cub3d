/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:59:00 by jariskan          #+#    #+#             */
/*   Updated: 2025/05/06 11:18:01 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_close_window(t_pgm *pgm)
{
	mlx_destroy_window(pgm->window.mlx, pgm->window.win);
	exit (1);
}

int	ft_open_window(t_pgm *pgm)
{
	pgm->window.mlx = mlx_init();
	if (!pgm->window.mlx)
		return (ft_print_error("Error\n.Failed mlx init.\n", 1));
	return (0);
}

void	ft_scale_and_draw_pixel(t_pgm *pgm, int x, int y, int color)
{
	int	dx;
	int	dy;
	int	wx;
	int	wy;

	wx = (WIDTH - pgm->weapon_img.width * WEAPON_SCALE) / 2;
	wy = HEIGHT - pgm->weapon_img.height * WEAPON_SCALE + pgm->weapon_offset;
	dy = 0;
	while (dy < WEAPON_SCALE)
	{
		dx = 0;
		while (dx < WEAPON_SCALE)
		{
			ft_put_pixel(&pgm->frame,
				wx + x * WEAPON_SCALE + dx,
				wy + y * WEAPON_SCALE + dy, color);
			dx++;
		}
		dy++;
	}
}
