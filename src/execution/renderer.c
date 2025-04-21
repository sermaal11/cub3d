/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:19:12 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/21 14:19:18 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_render_frame(t_pgm *pgm)
{
	t_ray ray;
	
	/* Si usamos la posiciones de valor entero directamente, estariamos 
	indicando las esquina superior izquierda del bloque al jugador, le sumamos
	la mitad de un entero dentro del double para poder indicar que nuestro 
	jugador se encuentra en medio medio del bloque y calcular correcamente 
	el trazado de rayos y evitar posibles bugs en la esquinas.*/
	ray.pos_x = pgm->game.y_plyr + 0.5;
	ray.pos_y = pgm->game.x_plyr + 0.5;
	
	//convertir en valores numericos la orientacion del jugador en 2D
	if (pgm->game.dir == 'N')
	{
		ray.dir_x = 0;
		ray.dir_y = -1;
	}
	if (pgm->game.dir == 'S')
	{
		ray.dir_x = 0;
		ray.dir_y = 1;
	}
	if (pgm->game.dir == 'E')
	{
		ray.dir_x = 1;
		ray.dir_y = 0;
	}
	if (pgm->game.dir == 'W')
	{	
		ray.dir_x = -1;
		ray.dir_y = 0;
	}
	
	/* Esto va ajustar el punto de vista mediante un plano perpendicular
	que nos indicará la vision del jugador (FOV ajustable en define) */
	ray.plane_x = FOV * -ray.dir_y;
	ray.plane_y = FOV * ray.dir_x;

	
	ray.x = 0; // Es la columna vertical que estamos pintando
	while (ray.x < WIDTH) //De izq a der de la pantalla calcularemos rayos
	{
		/*Convertir la columna de pantalla (ray.x) en un número 
		que representa la posición horizontal del rayo en el campo de visión.*/
		ray.camera_x = 2 * ray.x / (double)WIDTH - 1;
		//Calcula la direccion en la que sale el rayo
		ray.ray_dir_x = ray.dir_x + ray.plane_x * ray.camera_x;
		ray.ray_dir_y = ray.dir_y + ray.plane_y * ray.camera_x;

		//
		ray.x++;
	}
	return (0);
}