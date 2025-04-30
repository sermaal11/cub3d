/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:36:15 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 12:42:00 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_wall_stripe(t_ray *ray, t_pgm *pgm, t_texdraw d)
{
	int	y;
	int	tex_y;
	int	color;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)d.tex_pos & (d.texture->height - 1);
		d.tex_pos += d.step;
		color = *(unsigned int *)(d.texture->addr
				+ (tex_y * d.texture->line_length + d.tex_x
					* (d.texture->bits_per_pixel / 8)));
		ft_put_pixel(&pgm->frame, ray->x, y, color);
		y++;
	}
}
