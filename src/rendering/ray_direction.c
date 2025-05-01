/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:00 by jdelorme          #+#    #+#             */
/*   Updated: 2025/05/01 16:26:31 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_ray_direction(t_ray *ray, t_pgm *pgm)
{
	ray->pos_x = pgm->game.pos_x;
	ray->pos_y = pgm->game.pos_y;
	ray->dir_x = pgm->game.dir_x;
	ray->dir_y = pgm->game.dir_y;
	ray->plane_x = pgm->game.plane_x;
	ray->plane_y = pgm->game.plane_y;
}

void	ft_init_ray_for_column(t_ray *ray)
{
	ray->camera_x = 2 * ray->x / (double)WIDTH - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
}
