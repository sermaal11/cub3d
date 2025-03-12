/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:37:47 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/12 04:26:34 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int ft_validate_floor_ceiling(t_pgm *pgm)
{
    if (ft_check_fc_amount(pgm))
        return (ft_print_error("Error:\nFailed to check F and C amount.\n", 1));
    if (ft_check_fc_before_map(pgm))
        return (ft_print_error("Error:\nFailed to check F and C position\n", 1));
    if (ft_take_fc_content(pgm))
        return(ft_print_error("Error\nFailed to check RGB format\n", 1));
    return (0);
}

static int ft_validate_textures(t_pgm *pgm)
{
    if (ft_check_texture_amount(pgm))
        return (ft_print_error("Error:\nFailed to check textures amount.\n", 1));
    // * 2 Validar posicion de texturas con ft_check_textures_before_map

    // TODO: 3 Validar contenido de texturas con ft_take_textures_content
    return (0);
}

int ft_validate_map_file(t_pgm *pgm)
{
    if (ft_validate_textures(pgm))
        return (ft_print_error("Error:\nFailed to validate textures.\n", 1));
    // ! Revisar caso limite map_invalid_colors11.cub -> int ft_check_fc_before_map(t_pgm *pgm)
    if (ft_validate_floor_ceiling(pgm))
        return (ft_print_error("Error:\nFailed to validate F and C format.\n", 1));
    // TODO: 3. Validar mapa con todos los casos limite y guradar
    
    return (0);
}
