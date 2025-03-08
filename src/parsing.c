/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:09:59 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/07 14:10:48 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int ft_validate_extension(char *argv_map)
{
	int len;
	int i;
	char *extension;

	extension = ".cub";
	len = ft_strlen(argv_map);
	
	if (len < 4)
    return (1);
    
	i = 1;
	while (i <= 4)
	{
		if (argv_map[len - i] != *(extension + (4 - i)))
			return (1);
		i++;
	}
	return (0);
}

void	ft_extract_color_rgb(char *line_map, t_pgm *pgm, int letter)
{
	while (!ft_strchr(line_map, letter))
		*line_map++;
	while (*line_map != (ft_isdigit))
}

int ft_store_map_info(char *argv_map, t_pgm *pgm)
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

	// printf de control
	printf("texture_flag -> %d\n", pgm->texture.texture_flag);
	
	// Antes de guardar el mapa he de guardar en una estructura los valores de las texturas
	ft_extract_color_rgb(line_map, pgm, 'F');

	
	printf("texture_flag -> %d\n", pgm->texture.texture_flag);
	
    pgm->map.map = ft_split(line_map, '\n');
    pgm->map.copy_map = ft_split(line_map, '\n');
    if(!pgm->map.map || !pgm->map.copy_map)
        return (ft_print_error("Error:\nFailed split map file. ([map || copy_map] == NULL)\n", 1));
    free(line_map);
    line_map = NULL;
    return (0);
}

// int ft_validate_char_map(t_pgm *pgm)
// {
//     int		i;
//     int     j;
//     char    valid_map_chars[] = "01NSEW ";
// 	char	valid_player_chars[] = "NSEW";
// 	int		player_amount;

// 	player_amount = 0;
//     i = -1;
//     while (pgm->map.copy_map[++i])
//     {
//         j = -1;
//         while (pgm->map.copy_map[i][++j])
//         {
//             if (!ft_strchr(valid_map_chars, pgm->map.copy_map[i][j]))
//                 return (ft_print_error("Error:\nInvalid character in map.\n", 1));
// 			if (ft_strchr(valid_player_chars, pgm->map.copy_map[i][j]))
// 			{
// 				pgm->player.x_pos_player = i;
//                 pgm->player.y_pos_player = j;
// 				player_amount++;
// 			}
//         }
//     }
// 	if (player_amount != 1)
// 		return (ft_print_error("Error:\nOnly one player allow.\n", 1));
//     return (0);
// }

int	ft_parsing(int argc, char *argv_map, t_pgm *pgm)
{
	if (argc != 2)
		return (ft_print_error("Error:\nInvalid number of arguments.\n", 1));
	if (ft_validate_extension(argv_map) == 1)
        return (ft_print_error("Error:\nInvalid map extension.\n", 1));
    if (ft_store_map_info(argv_map, pgm) == 1)
        return (ft_print_error("Error:\nFailed parse map.\n", 1));
    
    // // Validaciones sobre el copy_map ft_validate_map()
    //     // Verificar que el mapa tenga solo caracteres válidos y haya solo un jugador
    // if (ft_validate_char_map(pgm) == 1)
	// 	return (ft_print_error("Error:\nFailed validate map.\n", 1));

    return (0);
}
