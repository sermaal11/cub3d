/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:13:02 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 12:29:54 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

void	ft_draw_square(t_pgm *pgm, int x, int y, int color)
{
	t_draw_square	s;
	t_circle		c;

	s.tile = MINIMAP_SCALE;
	s.cx = s.tile * 5 + s.tile / 2;
	s.cy = s.tile * 5 + s.tile / 2;
	s.radius = s.tile * 5;
	s.dy = 0;
	while (s.dy < s.tile)
	{
		s.dx = 0;
		while (s.dx < s.tile)
		{
			c.x = x + s.dx;
			c.y = y + s.dy;
			c.cx = s.cx;
			c.cy = s.cy;
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
	m->dx_off = (m->cx - (int)m->cx) * MINIMAP_SCALE;
	m->dy_off = (m->cy - (int)m->cy) * MINIMAP_SCALE;
	m->x = -m->offset;
	while (m->x <= m->offset)
	{
		m->mx = (int)m->cx + m->x;
		m->my = (int)m->cy + m->y;
		if (m->my >= 0 && m->my < pgm->map.height
			&& m->mx >= 0 && m->mx < pgm->map.width
			&& m->mx < (int)ft_strlen(pgm->map.map[m->my]))
		{
			m->col = get_tile_color(pgm, m->my, m->mx);
			m->sx = (m->x + m->offset) * MINIMAP_SCALE - m->dx_off;
			m->sy = (m->y + m->offset) * MINIMAP_SCALE - m->dy_off;
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
