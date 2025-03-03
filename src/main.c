/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/03 11:23:16 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
//     if(!mlx)
//     {
//         printf("ERROR\n");
//         return (0);
//     }
// 	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
// 	img.img = mlx_new_image(mlx, 400, 400);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

int ft_verify_extension(char *map_file)
{
	int len;
	int i;
	char *extension;

	i = 1;
	extension = ".cub";
	len =ft_strlen(map_file);
	while (i <= 4)
	{
		if (map_file[len - i] != *(extension + (4 - i)))
			printf("Error\n.Extension invalida.\n");
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		printf("Invalid number of arguments\n");
	// Verificar extension del mapa.
	if (ft_verify_extension(argv[1]))
	{
		printf("Error\nInvalid map extension\n");
		return (1);
	}
	
}