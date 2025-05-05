/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:20:00 by jdelorme          #+#    #+#             */
/*   Updated: 2025/05/05 14:51:23 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_weapon(t_pgm *pgm)
{
	int		x;
	int		y;
	int		color;
	char	*pixel;
	int		weapon_x = (WIDTH - pgm->weapon_img.width) / 2;
	int		weapon_y = HEIGHT - pgm->weapon_img.height + pgm->weapon_offset;

	y = 0;
	while (y < pgm->weapon_img.height)
	{
		x = 0;
		while (x < pgm->weapon_img.width)
		{
			pixel = pgm->weapon_img.addr
				+ (y * pgm->weapon_img.line_length
				+ x * (pgm->weapon_img.bits_per_pixel / 8));
			color = *(unsigned int *)pixel;
			if (color != 0xFF00FF) // Color rosa = transparencia simulada
				ft_put_pixel(&pgm->frame, weapon_x + x, weapon_y + y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_ceiling_and_floor(t_ray *ray, t_pgm *pgm)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	y = 0;
	ceiling_color = ft_rgb_to_int(pgm->ceiling);
	floor_color = ft_rgb_to_int(pgm->floor);
	while (y < ray->draw_start)
		ft_put_pixel(&pgm->frame, ray->x, y++, ceiling_color);
	y = ray->draw_end;
	while (y < HEIGHT)
		ft_put_pixel(&pgm->frame, ray->x, y++, floor_color);
}

static void	ft_update_weapon_offset(t_pgm *pgm)
{
	if (pgm->keys.w || pgm->keys.a || pgm->keys.s || pgm->keys.d)
	{
		if (++pgm->weapon_frame % 10 < 5)
			pgm->weapon_offset = WEAPON_OSCILLATION_UP;
		else
			pgm->weapon_offset = WEAPON_OSCILLATION_DOWN;
	}
	else
		pgm->weapon_offset = 0;
}

static void	ft_render_rays(t_pgm *pgm, t_ray *ray)
{
	ray->x = 0;
	ft_init_ray_direction(ray, pgm);
	while (ray->x < WIDTH)
	{
		ft_init_ray_for_column(ray);
		ft_init_ray_step_and_side_distance(ray);
		ft_find_wall_hit(ray, pgm->map.map);
		ft_calc_perp_wall_dist(ray);
		ft_calc_wall_strip(ray);
		ft_draw_ceiling_and_floor(ray, pgm);
		ft_draw_column(ray, pgm);
		ray->x++;
	}
}

int	ft_render_frame(t_pgm *pgm)
{
	t_ray	ray;
	int		weapon_x;
	int		weapon_y;

	(void)weapon_x;
	(void)weapon_y;
	ft_handle_inputs(pgm);
	ft_update_weapon_offset(pgm);
	ft_render_rays(pgm, &ray);
	ft_render_minimap(pgm);
	mlx_put_image_to_window(pgm->window.mlx, pgm->window.win, pgm->frame.ptr, 0, 0);
	ft_draw_weapon(pgm);
	return (0);
}


