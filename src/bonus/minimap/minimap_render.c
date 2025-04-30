/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:56:33 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 11:15:08 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_background(t_pgm *pgm, int cx, int cy, int radius)
{
	int	i = cy - radius;
	int	j;

	while (i <= cy + radius)
	{
		j = cx - radius;
		while (j <= cx + radius)
		{
			if (is_inside_circle(j, i, cx, cy, radius))
				ft_put_pixel(&pgm->frame, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	ft_render_minimap(t_pgm *pgm)
{
	int	cx = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	int	cy = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	int	radius = MINIMAP_SCALE * 5;

	draw_minimap_background(pgm, cx, cy, radius);
	ft_draw_minimap_tiles(pgm, 5, pgm->game.pos_x, pgm->game.pos_y);
	ft_draw_player(pgm);
}
