/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:19:12 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/22 13:35:40 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_ceiling_and_floor(t_ray *ray, t_pgm *pgm)
{
	int	y;
	int	ceiling_color = rgb_to_int(pgm->ceiling);
	int	floor_color = rgb_to_int(pgm->floor);

	y = 0;
	while (y < ray->draw_start)
	{
		ft_put_pixel(&pgm->frame, ray->x, y, ceiling_color);
		y++;
	}
	y = ray->draw_end;
	while (y < HEIGHT)
	{
		ft_put_pixel(&pgm->frame, ray->x, y, floor_color);
		y++;
	}
}



static void ft_calc_wall_strip(t_ray *ray)
{
	// Esta formula nos ayuda a calcular la altura respecto a la distancia del pl
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	//esta formula carlcula donde tiene que empezar a dibujarse la txtura y centra
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	//si el muro supera la pantalla superior, lo ajustamos para que empiece e el borde
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	//Centra el muro y donde tiene que empzar a dibujarse pero esta vez por debajo
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	//Si la pared se sale poor abajo, ajusta los pixeles
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}
/*Esta funcion asegura que la distancia se mida hasta la cara de la pared 
que chocaste, no hasta el centro de la casilla.*/
static void ft_calc_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x -  ray->pos_x + (1 - ray->step_x) / 2.0) / ray->ray_dir_x;		
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y -  ray->pos_y + (1 - ray->step_y) / 2.0) / ray->ray_dir_y;			
	}
}

/*Comparas side_dist_x y side_dist_y

El menor te dice por cuál eje avanzar primero

Sumas el delta correspondiente

Actualizas map_x o map_y

Compruebas si hay muro

Guardas si fue un golpe en X o Y (side)*/
static void	ft_find_wall_hit(t_ray *ray, char **map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		//compara que eje tiene mas cerca para decidir por cual avanzar antes
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; // golpe en eje X
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; // golpe en eje Y
		}
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
		//los golpes en que eje son importantes para saber despues que textura
	}
}


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
	// Copia la posición actual del jugador
	ray->pos_x = pgm->game.pos_x;
	ray->pos_y = pgm->game.pos_y;

	// Usa la dirección actualizada (rotación) desde game
	ray->dir_x = pgm->game.dir_x;
	ray->dir_y = pgm->game.dir_y;

	// Usa el plano de cámara actualizado desde game
	ray->plane_x = pgm->game.plane_x;
	ray->plane_y = pgm->game.plane_y;
}

int	ft_render_frame(t_pgm *pgm)
{
	t_ray ray;

	ft_init_ray_direction(&ray, pgm);
	ray.x = 0;
	while (ray.x < WIDTH)
	{
		ft_init_ray_for_column(&ray);
		ft_init_ray_step_and_side_distance(&ray);
		ft_find_wall_hit(&ray, pgm->map.map);
		ft_calc_perp_wall_dist(&ray);
		ft_calc_wall_strip(&ray);
		ft_draw_ceiling_and_floor(&ray, pgm);
		ft_draw_column(&ray, pgm);
		ray.x++;
	}
	// ⚠️ Esto faltaba
	mlx_put_image_to_window(pgm->window.mlx, pgm->window.win, pgm->frame.ptr, 0, 0);
	return (0);
}
