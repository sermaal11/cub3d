/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:37:47 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/11 14:12:42 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#include <stdio.h>
#include <stdlib.h>

static int ft_extract_rgb_value(char **color_str)
{
    int value;
    int digits;

    value = 0;
    digits = 0;
    while (**color_str && **color_str != ',')
    {
        if (**color_str < '0' || **color_str > '9')
            return (-1);
        value = value * 10 + (**color_str - '0');
        digits++;
        (*color_str)++;
    }
    if (digits == 0 || value < 0 || value > 255)
        return (-1);
    if (**color_str == ',')
        (*color_str)++;

    return (value);
}

int ft_check_rgb_value(char *color, t_vec3 *vec)
{
    vec->r = ft_extract_rgb_value(&color);
    vec->g = ft_extract_rgb_value(&color);
    vec->b = ft_extract_rgb_value(&color);
    if (vec->r == -1 || vec->g == -1 || vec->b == -1)
        return (ft_print_error("Error:\nInvalid RGB format or out of range.\n", 1));
    return (0);
}

static int ft_validate_floor_ceiling(t_pgm *pgm)
{
    if (ft_check_fc_amount(pgm))
        return (ft_print_error("Error:\nFailed to check F and C amount.\n", 1));
    if (ft_check_fc_before_map(pgm))
        return (ft_print_error("Error:\nFailed to check F and C position\n", 1));
    if (ft_take_fc_content(pgm))
        return(ft_print_error("Error\nFailed to check RGB format\n", 1));
    
    
    // ! printf de control (borrar)
    printf("F: %s\n", pgm->floor.color);
    printf("FLOOR RGB int value\n");
    printf("R: %d\n", pgm->floor.r);
    printf("G: %d\n", pgm->floor.g);
    printf("B: %d\n", pgm->floor.b);
    printf("\n");
    printf("C: %s\n", pgm->ceiling.color);
    printf("CEILING RGB int value\n");
    printf("R: %d\n", pgm->ceiling.r);
    printf("G: %d\n", pgm->ceiling.g);
    printf("B: %d\n", pgm->ceiling.b);
    printf("\n");
    return (0);
}

int ft_validate_map_file(t_pgm *pgm)
{
    // ! 1. Validar colores de suelo y techo con todos los casos limite y guardar
    if (ft_validate_floor_ceiling(pgm))
        return (ft_print_error("Error:\nFailed to validate F and C format.\n", 1));
    // ! 2. valñidar texturas NO, SO, WE, EA con todos los casos limite y guardar

    // ! 3. Validar mapa con todos los casos limite y guradar
    
    return (0);
}
