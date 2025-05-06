/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:13:02 by jdelorme          #+#    #+#             */
/*   Updated: 2025/05/06 12:46:44 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_square(t_pgm *pgm, int x, int y, int color)
{
	t_draw_square	s;
	t_circle		c;
	int				half;

	half = MINIMAP_SCALE / 2;
	s.radius = MINIMAP_SCALE * 5;
	s.dy = -half;
	while (s.dy < half)
	{
		s.dx = -half;
		while (s.dx < half)
		{
			c.x = x + s.dx;
			c.y = y + s.dy;
			c.cx = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
			c.cy = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
			c.radius = s.radius;
			if (is_inside_circle(c))
				ft_put_pixel(&pgm->frame, c.x, c.y, color);
			s.dx++;
		}
		s.dy++;
	}
}

static void	ft_draw_minimap_row(t_pgm *pgm, t_minimap_row *m)
{
	double	rel_x;
	double	rel_y;

	m->x = -m->offset;
	while (m->x <= m->offset)
	{
		m->mx = (int)(pgm->game.pos_x) + m->x;
		m->my = (int)(pgm->game.pos_y) + m->y;
		if (m->my >= 0 && m->my < pgm->map.height
			&& m->mx >= 0 && m->mx < pgm->map.width
			&& m->mx < (int)ft_strlen(pgm->map.map[m->my]))
		{
			m->col = get_tile_color(pgm, m->my, m->mx);
			rel_x = (double)m->mx + 0.5 - pgm->game.pos_x;
			rel_y = (double)m->my + 0.5 - pgm->game.pos_y;
			m->sx = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2
				+ rel_x * MINIMAP_SCALE;
			m->sy = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2
				+ rel_y * MINIMAP_SCALE;
			ft_draw_square(pgm, m->sx, m->sy, m->col);
		}
		m->x++;
	}
}

void	ft_draw_minimap_tiles(t_pgm *pgm, int offset, double cx, double cy)
{
	t_minimap_row	m;
	int				y;

	y = -offset;
	while (y <= offset)
	{
		m.cx = cx;
		m.cy = cy;
		m.offset = offset;
		m.y = y;
		ft_draw_minimap_row(pgm, &m);
		y++;
	}
}
