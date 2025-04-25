/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:38:51 by volmer            #+#    #+#             */
/*   Updated: 2025/04/25 12:05:13 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_draw_square(t_pgm *pgm, int x, int y, int color)
{
	int dx;
	int dy;
	int title_size;

	title_size = MINIMAP_SCALE; // Tamaño del cuadrado
	dy = 0;
	while (dy < title_size)
	{
		dx = 0;
		while (dx < title_size)
		{
			ft_put_pixel(&pgm->frame, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

static void ft_draw_player(t_pgm *pgm)
{
	int px;
	int py;
	int dx;
	int dy;

	px = (int)(pgm->game.pos_x * MINIMAP_SCALE);
	py = (int)(pgm->game.pos_y * MINIMAP_SCALE);
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			ft_put_pixel(&pgm->frame, px + dx, py + dy, 0x00FF00); // Color para el jugador
			dx++;
		}
		dy++;
	}
}

void	ft_render_minimap(t_pgm *pgm)
{
	int x;
	int y;
	int color;

	y = 0;
	while (pgm->map.map[y])
	{
		x = 0;
		while (pgm->map.map[y][x])
		{
			color = 0x000000; // Color para el minimapa
			if (pgm->map.map[y][x] == '1')
				color = 0xFFFFFF; // Color para las paredes
			else if (ft_is_player_char(pgm->map.map[y][x]))
				color = 0xFF0000; // Color para el jugador
			ft_draw_square(pgm, x * MINIMAP_SCALE, y * MINIMAP_SCALE, color);
			x++;
		}
		y++;
	}
	ft_draw_player(pgm);
}