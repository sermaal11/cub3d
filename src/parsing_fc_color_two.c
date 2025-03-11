/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fc_color_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:45:52 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/11 16:47:26 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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