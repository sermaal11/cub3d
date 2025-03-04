/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:09:59 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/04 15:34:49 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int ft_verify_extension(char *map_file)
{
	int len;
	int i;
	char *extension;

	extension = ".cub";
	len = ft_strlen(map_file);
	
	if (len < 4)
    return (1);
    
	i = 1;
	while (i <= 4)
	{
		if (map_file[len - i] != *(extension + (4 - i)))
			return (1);
		i++;
	}
	return (0);
}

int ft_read_map_file(char *argv_map, t_pgm *pgm)
{
    char	*line_map;
    ssize_t	line_len_map;
    
    pgm->map.fd_map = open(argv_map, O_RDONLY);
    if (pgm->map.fd_map  == -1)
        return (ft_print_error("Error:\nFailed open map file. (fd_map == -1\n", 1));
    line_map = (char *)malloc(MAP_BUFFER_SIZE * sizeof(char));
    if (!line_map)
        return (ft_print_error("Error:\nFailed malloc map file. (line_map == NULL)\n", 1));
    line_len_map = read(pgm->map.fd_map , line_map, MAP_BUFFER_SIZE);
    if (!line_len_map)
        return (ft_print_error("Error:\nFailed read map file. (line_len_map == -1)\n", 1));
    line_map[line_len_map] = '\0';
    pgm->map.map = ft_split(line_map, '\n');
    pgm->map.copy_map = ft_split(line_map, '\n');
    if(!pgm->map.map || !pgm->map.copy_map)
        return (ft_print_error("Error:\nFailed split map file. (map || copy_map == NULL)\n", 1));
    free(line_map);
    line_map = NULL;
    return (0);
}
int ft_validate_char_map(t_pgm *pgm)
{
    int i;
    int j;
    char valid_chars[] = "01NSEW ";

    i = 0;
    while (pgm->map.map[i])
    {
        j = 0;
        while (pgm->map.map[i][j])
        {
            if (!ft_strchr(valid_chars, pgm->map.map[i][j]))
                return (ft_print_error("Error:\nInvalid character in map.\n", 1));
            j++;
        }
        i++;
    }
    return (0);
}

int	ft_parsing(int argc, char *argv_map, t_pgm *pgm)
{
	// Comprobar número de argumentos
	if (argc != 2)
		return (ft_print_error("Error:\nInvalid number of arguments.\n", 1));
	// Verificar extensión del mapa
	if (ft_verify_extension(argv_map) == 1)
        return (ft_print_error("Error:\nInvalid map extension.\n", 1));
    // Leer y guardar el mapa en un char **
    if (ft_read_map_file(argv_map, pgm) == 1)
        return (ft_print_error("Error:\nFailed parse map.\n", 1));
    
    // Validaciones sobre el mapa
        // Validar que el mapa tenga solo caracteres válidos
    if (ft_validate_char_map(pgm) == 1)
        return (ft_print_error("Error:\nFailed validate map.\n", 1));

        //
    
    return (0);
}
