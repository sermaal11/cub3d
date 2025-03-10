/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_floor_ceiling_color.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:22:41 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/11 00:33:43 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int ft_check_fc_before_map(t_pgm *pgm)
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
            return (ft_print_error("Error:\nColor (F or C) found after the map.\n", 1));
        i++;
    }
    return (0);
}

static int ft_check_rgb_format(char *rgb_format)
{
    int i = 0;
    int comma_count = 0;
    int num_count = 0;

    if (!rgb_format)
        return (ft_print_error("Error:\nRGB format is NULL.\n", 1));
    while (rgb_format[i])
    {
        if (ft_isdigit(rgb_format[i]))
        {
            if (i == 0 || !ft_isdigit(rgb_format[i - 1]))
                num_count++;
            i++;
        }
        else if (rgb_format[i] == ',')
        {
            if (i == 0 || rgb_format[i + 1] == '\0' || rgb_format[i + 1] == ',')
                return (ft_print_error("Error:\nUnexpected comma placement.\n", 1));
            comma_count++;
            i++;
        }
        else
            return (ft_print_error("Error:\nExpected only digits and commas.\n", 1));
    }
    if (comma_count != 2 || num_count != 3)
        return (ft_print_error("Error:\nExpected three numbers separated by two commas.\n", 1));
    return (0);
}

static int ft_take_rgb_format(t_pgm *pgm)
{
    if (ft_check_rgb_format(pgm->floor.color))
        return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
    if (ft_check_rgb_format(pgm->ceiling.color))
    return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
    
    // ! Checkear que los valores rgb obtenidos esten entre 0 y 256
    
    return (0);
}

int ft_take_fc_content(t_pgm *pgm)
{
    int i = -1;
    char *line;
    char *color_value;

    while (pgm->map_file.map_file_matrix[++i])
    {
        line = pgm->map_file.map_file_matrix[i];
        if (line[0] == 'F' || line[0] == 'C')
        {
            color_value = ft_strchr(line, ' ');
            if (!color_value)
                return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
            color_value++;
            if (!ft_isdigit(*color_value))
                return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
            if (line[0] == 'F')
                pgm->floor.color = ft_strdup(color_value);
            else if (line[0] == 'C')
                pgm->ceiling.color = ft_strdup(color_value);
        }   
    }
    if (ft_take_rgb_format(pgm))
        return (1);
    return (0);
}
