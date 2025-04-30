/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:35:45 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/30 12:35:52 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	ft_get_wall_hit_point(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y
			- floor(ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y));
	return (ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x
		- floor(ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x));
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

void	ft_init_tex_step(t_ray *ray, t_img *texture, double *step,
		double *tex_pos)
{
	*step = 1.0 * texture->height / ray->line_height;
	*tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * (*step);
}
