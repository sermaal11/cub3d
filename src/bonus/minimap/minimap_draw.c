/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:13:02 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 11:13:44 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_square(t_pgm *pgm, int x, int y, int color)
{
	int	dx, dy;
	int	tile = MINIMAP_SCALE;
	int	cx = MINIMAP_SCALE * 5 + tile / 2;
	int	cy = MINIMAP_SCALE * 5 + tile / 2;
	int	radius = tile * 5;

	dy = 0;
	while (dy < tile)
	{
		dx = 0;
		while (dx < tile)
		{
			if (is_inside_circle(x + dx, y + dy, cx, cy, radius))
				ft_put_pixel(&pgm->frame, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	ft_draw_minimap_row(t_pgm *pgm, int off, double cx, double cy, int y)
{
	int	x, mx, my, col;
	int	sx, sy;
	double	dx_off = (cx - (int)cx) * MINIMAP_SCALE;
	double	dy_off = (cy - (int)cy) * MINIMAP_SCALE;

	x = -off;
	while (x <= off)
	{
		mx = (int)cx + x;
		my = (int)cy + y;
		if (my >= 0 && my < pgm->map.height && mx >= 0 && mx < pgm->map.width)
		{
			col = get_tile_color(pgm, my, mx);
			sx = (x + off) * MINIMAP_SCALE - dx_off;
			sy = (y + off) * MINIMAP_SCALE - dy_off;
			ft_draw_square(pgm, sx, sy, col);
		}
		x++;
	}
}

void	ft_draw_minimap_tiles(t_pgm *pgm, int offset, double cx, double cy)
{
	int	y = -offset;

	while (y <= offset)
		ft_draw_minimap_row(pgm, offset, cx, cy, y++);
}

