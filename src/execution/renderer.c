/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:19:12 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/21 15:09:34 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void ft_init_ray_step_and_side_distance(t_ray *ray)
{
	//Transformamos la posicón del jugador en coordenadas del mapa (enteros)
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	//Calcular cuánto "cuesta" cruzar una celda en X e Y
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	// Preparar los pasos y la distancia inicial al primer cruce en X
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}

}

static void ft_init_ray_for_column(t_ray *ray)
{

	/* Convertir la columna actual de pantalla (ray->x)
	en una posición horizontal relativa del rayo */
	ray->camera_x = 2 * ray->x / (double)WIDTH - 1;

	// Dirección del rayo ajustada con el plano de cámara
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
}

static void ft_init_ray_direction(t_ray *ray, t_pgm *pgm)
{
	/* Si usamos la posiciones de valor entero directamente, estariamos 
	indicando las esquina superior izquierda del bloque al jugador, le sumamos
	la mitad de un entero dentro del double para poder indicar que nuestro 
	jugador se encuentra en medio medio del bloque y calcular correcamente 
	el trazado de rayos y evitar posibles bugs en la esquinas.*/
	ray->pos_x = pgm->game.y_plyr + 0.5;
	ray->pos_y = pgm->game.x_plyr + 0.5;
	
	//convertir en valores numericos la orientacion del jugador en 2D
	if (pgm->game.dir == 'N')
	{
		ray->dir_x = 0;
		ray->dir_y = -1;
	}
	if (pgm->game.dir == 'S')
	{
		ray->dir_x = 0;
		ray->dir_y = 1;
	}
	if (pgm->game.dir == 'E')
	{
		ray->dir_x = 1;
		ray->dir_y = 0;
	}
	if (pgm->game.dir == 'W')
	{	
		ray->dir_x = -1;
		ray->dir_y = 0;
	}
	
	/* Esto va ajustar el punto de vista mediante un plano perpendicular
	que nos indicará la vision del jugador (FOV ajustable en define) */
	ray->plane_x = FOV * -ray->dir_y;
	ray->plane_y = FOV * ray->dir_x;

}

int	ft_render_frame(t_pgm *pgm)
{
	t_ray ray;
	
	ft_init_ray_direction(&ray, pgm);
	ray.x = 0; // Es la columna vertical que estamos pintando
	while (ray.x < WIDTH) //De izq a der de la pantalla calcularemos rayos
	{
		ft_init_ray_for_column(&ray);
		ft_init_ray_step_and_side_dist();

		ray.x++;
	}
	return (0);
}