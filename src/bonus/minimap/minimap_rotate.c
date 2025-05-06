/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:41:51 by jdelorme          #+#    #+#             */
/*   Updated: 2025/05/06 12:51:37 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_in_fov(double angle, double angle_center)
{
	double	diff;

	diff = angle - angle_center;
	if (diff > M_PI)
		diff -= 2 * M_PI;
	if (diff < -M_PI)
		diff += 2 * M_PI;
	return (fabs(diff) <= FOV / 2);
}

void	ft_draw_fov_cone(t_pgm *pgm)
{
	int		x;
	int		y;
	int		cx;
	int		cy;
	double	angle_center;

	cx = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	cy = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	angle_center = atan2(pgm->game.dir_y, pgm->game.dir_x);
	y = -MINIMAP_SCALE * 4;
	while (y <= MINIMAP_SCALE * 4)
	{
		x = -MINIMAP_SCALE * 4;
		while (x <= MINIMAP_SCALE * 4)
		{
			if (sqrt(x * x + y * y) <= MINIMAP_SCALE * 4
				&& is_in_fov(atan2(y, x), angle_center))
				ft_put_pixel(&pgm->frame, cx + x, cy + y, 0x00CCFF);
			x++;
		}
		y++;
	}
}
