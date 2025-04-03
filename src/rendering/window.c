/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:59:00 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/02 17:57:46 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_close_window(t_pgm *pgm)
{
	mlx_destroy_window(pgm->window.mlx, pgm->window.win);
	exit (1);
}

int ft_open_window(t_pgm *pgm)
{
	pgm->window.mlx = mlx_init();
	if (!pgm->window.mlx)
		return (ft_print_error("Error\n.Failed mlx init.\n", 1));
	return (0);
}
