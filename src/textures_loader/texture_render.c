/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:02:02 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 00:36:40 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
t_img *ft_get_texture(t_ray *ray, t_pgm *pgm)
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
double	ft_get_wall_hit_point(t_ray *ray)
{
	if (ray->side == 0)
	{
		return (ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y -
				floor(ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y));
	}
	else
	{
		return (ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x -
			floor(ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x));
	}
}

int	ft_get_tex_x(t_ray *ray, double wall_x, t_img *texture)
{
	int	tex_x;

	tex_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}
void	ft_init_tex_step(t_ray *ray, t_img *texture, double *step, double *tex_pos)
{
	*step = 1.0 * texture->height / ray->line_height;
	*tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * (*step);
}

void	ft_draw_wall_stripe(t_ray *ray, t_pgm *pgm, t_img *texture, int tex_x, double step, double tex_pos)
{
	int	y;
	int	tex_y;
	int	color;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = *(unsigned int *)(texture->addr
				+ (tex_y * texture->line_length + tex_x * (texture->bits_per_pixel / 8)));
		ft_put_pixel(&pgm->frame, ray->x, y, color);
		y++;
	}
}

void	ft_draw_column(t_ray *ray, t_pgm *pgm)
{
	t_img	*texture;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;

	texture = ft_get_texture(ray, pgm);
	wall_x = ft_get_wall_hit_point(ray);
	tex_x = ft_get_tex_x(ray, wall_x, texture);
	ft_init_tex_step(ray, texture, &step, &tex_pos);
	ft_draw_wall_stripe(ray, pgm, texture, tex_x, step, tex_pos);
}
