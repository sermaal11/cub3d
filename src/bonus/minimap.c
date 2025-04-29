/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:38:51 by volmer            #+#    #+#             */
/*   Updated: 2025/04/29 13:14:30 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_inside_circle(int x, int y, int center_x, int center_y, int radius)
{
	int	dx;
	int	dy;

	dx = x - center_x;
	dy = y - center_y;
	return (dx * dx + dy * dy <= radius * radius);
}

void	ft_draw_square(t_pgm *pgm, int x, int y, int color)
{
	int	dx;
	int	dy;
	int	tile_size;
	int	center_x;
	int	center_y;
	int	radius;

	tile_size = MINIMAP_SCALE;
	center_x = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	center_y = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	radius = MINIMAP_SCALE * 5; // 5 tiles de radio

	dy = 0;
	while (dy < tile_size)
	{
		dx = 0;
		while (dx < tile_size)
		{
			if (is_inside_circle(x + dx, y + dy, center_x, center_y, radius))
				ft_put_pixel(&pgm->frame, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}


static void	ft_draw_minimap_row(t_pgm *pgm, int offset, double center_x, double center_y, int y)
{
	int		x;
	int		map_x;
	int		map_y;
	int		color;
	int		screen_x;
	int		screen_y;
	double	dx_offset;
	double	dy_offset;

	dx_offset = (center_x - (int)center_x) * MINIMAP_SCALE;
	dy_offset = (center_y - (int)center_y) * MINIMAP_SCALE;
	x = -offset;
	while (x <= offset)
	{
		map_x = (int)(center_x) + x;
		map_y = (int)(center_y) + y;
		if (map_y >= 0 && map_y < pgm->map.height
			&& map_x >= 0 && map_x < pgm->map.width)
		{
			color = 0x000000;
			if (pgm->map.map[map_y][map_x] == '1')
				color = 0xFFFFFF;
			else if (ft_is_player_char(pgm->map.map[map_y][map_x]))
				color = 0xFF0000;
			screen_x = (x + offset) * MINIMAP_SCALE - dx_offset;
			screen_y = (y + offset) * MINIMAP_SCALE - dy_offset;
			ft_draw_square(pgm, screen_x, screen_y, color);
		}
		x++;
	}
}

static void	ft_draw_minimap_tiles(t_pgm *pgm, int offset, double center_x, double center_y)
{
	int	y;

	y = -offset;
	while (y <= offset)
	{
		ft_draw_minimap_row(pgm, offset, center_x, center_y, y);
		y++;
	}
}

static void	ft_draw_player(t_pgm *pgm)
{
	int	center_x;
	int	center_y;
	int	dx;
	int	dy;

	center_x = MINIMAP_SCALE * 5;
	center_y = MINIMAP_SCALE * 5;
	dy = -2;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
		{
			ft_put_pixel(&pgm->frame, center_x + dx, center_y + dy, 0x00FF00);
			dx++;
		}
		dy++;
	}
}

void	ft_render_minimap(t_pgm *pgm)
{
	int	i;
	int	j;
	int	center_x;
	int	center_y;
	int	radius;

	center_x = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	center_y = MINIMAP_SCALE * 5 + MINIMAP_SCALE / 2;
	radius = MINIMAP_SCALE * 5;
	i = center_y - radius;
	while (i <= center_y + radius)
	{
		j = center_x - radius;
		while (j <= center_x + radius)
		{
			if (is_inside_circle(j, i, center_x, center_y, radius))
				ft_put_pixel(&pgm->frame, j, i, 0x000000);
			j++;
		}
		i++;
	}
	ft_draw_minimap_tiles(pgm, 5, pgm->game.pos_x, pgm->game.pos_y);
	ft_draw_player(pgm);
}

