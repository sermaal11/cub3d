/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:50:15 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/02 17:56:05 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct_rendering(t_pgm *pgm)
{
	pgm->window.mlx = NULL;
	pgm->window.win = NULL;	
}