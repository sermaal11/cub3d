/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:37:47 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/10 21:54:45 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int ft_validate_floor_ceiling(t_pgm *pgm)
{
    // ! Validar cantidad de F Y C en el archivo
    if (ft_check_fc_amount(pgm))
        return (ft_print_error("Error:\nFailed to validate F and C amount.\n", 1));
    // ! Validar posicion de F y C en el archivo
    if (ft_validate_colors_before_map(pgm))
        return (ft_print_error("Error:\nFailed to validt F and C position\n", 1));
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