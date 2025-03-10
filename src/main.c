/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/10 20:48:39 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// ! pritnf de control
void print_char_array(char **array) {
    if (!array) {
        printf("⚠ El array está vacío o es NULL.\n");
        return;
    }
    for (int i = 0; array[i]; i++)
        printf("%s\n", array[i]);
}

int main(int argc, char **argv)
{
    t_pgm pgm;

	if (ft_parsing(argc, argv[1], &pgm))
    	return (1);

	// ! Print_f de control
	print_char_array(pgm.map_file.map_file_matrix);
	// ! print_f de control
	
    if (pgm.map_file.fd_map_file != -1)
        close(pgm.map_file.fd_map_file);
    return (0);
}