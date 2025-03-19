/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/19 11:10:50 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// ! pritnf de control (borrar funcion)
static void	print_char_array(char **array, char *msg)
{
	int i = 0;

	printf("\n%s\n", msg);
	printf("===============================================================\n");
	while (array[i])
	{
		printf("[]:\"%s\"\n", array[i]);
		i++;
	}
	printf("===============================================================\n");
}

int	main(int argc, char **argv)
{
	t_pgm	pgm;

	if (ft_parsing(argc, argv[1], &pgm))
		return (1);

	// ! BORRAR
	print_char_array(pgm.map.copy, "Mapa copia");
	printf("Jugador en x: %d\n", pgm.game.x_plyr);
	printf("Jugador en y: %d\n", pgm.game.y_plyr);
	printf("Direccion del jugador: %c\n", pgm.game.dir);
	print_char_array(pgm.map.map, "Mapa original");
	// ! BORRAR
	
	if (pgm.map_file.fd_map_file != -1)
		close(pgm.map_file.fd_map_file);
	ft_free(&pgm);
	return (0);
}
