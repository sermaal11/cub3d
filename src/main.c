/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/05 19:58:31 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void print_map(char **map)
{
    int i = 0;

    if (!map)
    {
        printf("Error: El mapa es NULL\n");
        return;
    }

    printf("Mapa:\n");
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    printf("\n");
}

void	ft_initialize(t_pgm *pgm)
{
	pgm->texture.texture_flag = 0;
}

int main(int argc, char **argv)
{
	t_pgm pgm;

	// Incializar las estructuras antes para evitarn fallos y comportamientos indefinidos.
	ft_initialize(&pgm);
	
	if (ft_parsing(argc, argv[1], &pgm))
		return (1);
	
	// Printf para ver el contenido de la estructura pgm.map.map y pgm.map.copy_map
	//print_map(pgm.map.map);
	
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	
	// // 🔹 Inicializar MinilibX
	// mlx = mlx_init();
	// if (!mlx)
	// {
	// 	printf("ERROR: Could not initialize MinilibX.\n");
	// 	return (1);
	// }

	// // 🔹 Crear ventana
	// mlx_win = mlx_new_window(mlx, 400, 400, "Cub3D");
	// if (!mlx_win)
	// {
	// 	printf("ERROR: Could not create the window.\n");
	// 	return (1);
	// }

	// // 🔹 Crear imagen
	// img.img = mlx_new_image(mlx, 400, 400);
	// if (!img.img) // Verificar que la imagen se creó correctamente
	// {
	// 	printf("ERROR: Could not create the image.\n");
	// 	return (1);
	// }

	// // 🔹 Obtener dirección de la imagen
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// if (!img.addr)
	// {
	// 	printf("ERROR: Could not get the image address.\n");
	// 	return (1);
	// }

	// // 🔹 Dibujar un píxel en la imagen
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	// // 🔹 Mostrar la imagen en la ventana
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	// // 🔹 Iniciar el loop de eventos
	// mlx_loop(mlx);
	close(pgm.map.fd_map);
	return (0); // 🔹 Corregido "retrun" a "return"
}