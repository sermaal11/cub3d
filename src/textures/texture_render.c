/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:02:02 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 12:46:17 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img	*ft_get_texture(t_ray *ray, t_pgm *pgm)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (&pgm->texture.img_we);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (&pgm->texture.img_ea);
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (&pgm->texture.img_no);
	if (ray->side == 1 && ray->ray_dir_y < 0)
		return (&pgm->texture.img_so);
	return (NULL);
}

void	ft_draw_column(t_ray *ray, t_pgm *pgm)
{
	t_texdraw	d;

	d.texture = ft_get_texture(ray, pgm);
	d.step = 0;
	d.tex_pos = 0;
	d.tex_x = ft_get_tex_x(ray, ft_get_wall_hit_point(ray), d.texture);
	ft_init_tex_step(ray, d.texture, &d.step, &d.tex_pos);
	ft_draw_wall_stripe(ray, pgm, d);
}
