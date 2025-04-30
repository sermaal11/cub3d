/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:56:33 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 12:32:42 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_background(t_pgm *pgm, int cx, int cy, int radius)
{
	int			i;
	int			j;
	t_circle	c;

	c.cx = cx;
	c.cy = cy;
	c.radius = radius;
	i = cy - radius;
	while (i <= cy + radius)
	{
		j = cx - radius;
		while (j <= cx + radius)
		{
			c.x = j;
			c.y = i;
			if (is_inside_circle(c))
				ft_put_pixel(&pgm->frame, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	ft_render_minimap(t_pgm *pgm)
{
	int	cx;
	int	cy;
	int	radius;

	radius = MINIMAP_SCALE * 5;
	cx = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	cy = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	draw_minimap_background(pgm, cx, cy, radius);
	ft_draw_minimap_tiles(pgm, 5, pgm->game.pos_x, pgm->game.pos_y);
	ft_draw_player(pgm);
}
