/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/04 17:24:29 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_pgm	pgm;

	ft_init_struct_parsing(&pgm);
	ft_init_struct_rendering(&pgm);
	if (ft_parsing(argc, argv[1], &pgm))
	{
		ft_free(&pgm);
		return (1);
	}
	if (ft_open_window(&pgm))
	{
		ft_free(&pgm);
		return (1);
	}
	pgm.window.win = mlx_new_window(pgm.window.mlx, WIDTH, HEIGHT, "cub3d");
	if (!pgm.window.win)
	{
		ft_free(&pgm);
		return (1);
	}
	// Funcion para imprimir texturas y actualizarlas --> so_long ft_print_sprites(&window, game.map);
	//mlx_key_hook();
	mlx_hook(pgm.window.win, 17, 0, ft_close_window, &pgm);
	
	
	mlx_loop(pgm.window.mlx);
	close(pgm.map_file.fd_map_file);
	ft_free(&pgm);
	return (0);
}
