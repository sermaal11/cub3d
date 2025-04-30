
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:52:31 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 10:52:48 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_inside_circle(int x, int y, int cx, int cy, int radius)
{
	int dx = x - cx;
	int dy = y - cy;
	return (dx * dx + dy * dy <= radius * radius);
}

int	get_tile_color(t_pgm *pgm, int map_y, int map_x)
{
	if (pgm->map.map[map_y][map_x] == '1')
		return (0xFFFFFF);
	else if (ft_is_player_char(pgm->map.map[map_y][map_x]))
		return (0xFF0000);
	return (0x000000);
}

void	ft_draw_player(t_pgm *pgm)
{
	int	cx = MINIMAP_SCALE * 5;
	int	cy = MINIMAP_SCALE * 5;
	int	dx, dy;

	dy = -2;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
			ft_put_pixel(&pgm->frame, cx + dx++, cy + dy, 0x00FF00);
		dy++;
	}
}