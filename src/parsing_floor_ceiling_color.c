/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_floor_ceiling_color.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:22:41 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/10 21:54:56 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_validate_colors_before_map(t_pgm *pgm)
{
    int i = 0;
    int map_started = 0;

    while (pgm->map_file.map_file_matrix[i])
    {
        char *line = pgm->map_file.map_file_matrix[i];
        int j = 0;
        while (line[j])
        {
            if (!ft_strchr(" 10NSEW", line[j]))
                break;
            j++;
        }
        if (line[j] == '\0')
            map_started = 1;
        if (map_started && (ft_strchr(line, 'F') || ft_strchr(line, 'C')))
            return (ft_print_error("Error: Color (F or C) found after the map.\n", 1));
        i++;
    }
    return (0);
}

int ft_check_fc_amount(t_pgm *pgm)
{
    int i;
    int j;

    i = -1;
    pgm->map_file.count_f = 0;
    pgm->map_file.count_c = 0;
    while (pgm->map_file.map_file_matrix[++i])
    {
        j = -1;
        while (pgm->map_file.map_file_matrix[i][++j])
        {
            if (pgm->map_file.map_file_matrix[i][j] == 'F')
                pgm->map_file.count_f++;
            else if (pgm->map_file.map_file_matrix[i][j] == 'C')
                pgm->map_file.count_c++;
        }
    }
    if (pgm->map_file.count_f != 1 || pgm->map_file.count_c != 1) 
    {
        if (pgm->map_file.count_f == 0 || pgm->map_file.count_c == 0)
            return (ft_print_error("Error:\nColor not found (F or C).\n", 1));
        if (pgm->map_file.count_f > 1 || pgm->map_file.count_c > 1)
            return (ft_print_error("Error:\nColor repeated (F or C).\n", 1));
    }
    return (0);
}
