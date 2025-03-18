/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/18 14:49:16 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// ! pritnf de control (borrar funcion)
void	print_char_array(char **array)
{
	int	i;

	if (!array)
	{
		printf("El array está vacío o es NULL.\n");
		return ;
	}
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}

// ! Printf de control (borrar funcion print_char_array)
int	main(int argc, char **argv)
{
	t_pgm	pgm;

	if (ft_parsing(argc, argv[1], &pgm))
		return (1);
	// print_char_array(pgm.map_file.map_file_matrix);
	// printf("Mapa:\n");
	// print_char_array(pgm.map.map);
	// printf("\nMapa copia:\n");
	print_char_array(pgm.map.copy_map);
	printf("Jugador en x: %d\n", pgm.game.x_plyr);
	printf("Jugador en y: %d\n", pgm.game.y_plyr);
	printf("Direccion del jugador: %c\n", pgm.game.dir);
	if (pgm.map_file.fd_map_file != -1)
		close(pgm.map_file.fd_map_file);
	ft_free(&pgm);
	return (0);
}
