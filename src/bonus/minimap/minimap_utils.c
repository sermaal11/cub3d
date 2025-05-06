/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:52:31 by jdelorme          #+#    #+#             */
/*   Updated: 2025/05/06 12:57:12 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_inside_circle(t_circle c)
{
	int	dx;
	int	dy;
	int	dist_squared;

	dx = c.x - c.cx;
	dy = c.y - c.cy;
	dist_squared = dx * dx + dy * dy;
	return (dist_squared <= c.radius * c.radius);
}

int	get_tile_color(t_pgm *pgm, int map_y, int map_x)
{
	char	tile;

	tile = pgm->map.map[map_y][map_x];
	if (tile == '1')
		return (0xFF0000);
	if (tile == '0')
		return (0x111111);
	return (0);
}

void	ft_draw_player(t_pgm *pgm)
{
	t_draw_player	p;

	p.cx = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	p.cy = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	p.dy = -2;
	while (p.dy <= 2)
	{
		p.dx = -2;
		while (p.dx <= 2)
		{
			ft_put_pixel(&pgm->frame, p.cx + p.dx, p.cy + p.dy, 0x00FF00);
			p.dx++;
		}
		p.dy++;
	}
}
