/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/12 04:23:20 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// ! pritnf de control (borrar funcion)
void	print_char_array(char **array)
{
	if (!array)
    {
		printf("El array está vacío o es NULL.\n");
    	return;
    }
	for (int i = 0; array[i]; i++)
		printf("%s\n", array[i]);
}

int	main(int argc, char **argv)
{
	t_pgm pgm;

	if (ft_parsing(argc, argv[1], &pgm))
		return (1);
	// ! Print_f de control
	// ! Solo imprime el mapa si es valido (si se ha validado correctamente)
	// ! f_color y c_color validados. faltan map_invalid_colors3.cub y map_invalid_colors11.cub
	print_char_array(pgm.map_file.map_file_matrix);
    if (pgm.map_file.fd_map_file != -1)
        close(pgm.map_file.fd_map_file);
    return (0);
}
