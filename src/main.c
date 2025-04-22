/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/22 12:58:59 by jdelorme         ###   ########.fr       */
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
	ft_init_player_orientation(&pgm.game); //Parseo que sergio no ha hecho
	pgm.game.pos_x = pgm.game.y_plyr + 0.5;
	pgm.game.pos_y = pgm.game.x_plyr + 0.5;
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
	pgm.frame.ptr = mlx_new_image(pgm.window.mlx, WIDTH, HEIGHT);
	if (!pgm.frame.ptr)
	{
		ft_free(&pgm);
		return (1);
	}
	pgm.frame.addr = mlx_get_data_addr(pgm.frame.ptr,
		&pgm.frame.bits_per_pixel,
		&pgm.frame.line_length,
		&pgm.frame.endian);
if (!pgm.frame.addr)
{
	ft_free(&pgm);
	return (1);
}

	ft_load_all_textures(&pgm);
	// Funcion para imprimir texturas y actualizarlas --> so_long ft_print_sprites(&window, game.map);
	mlx_loop_hook(pgm.window.mlx, ft_render_frame, &pgm);
	mlx_hook(pgm.window.win, 17, 0, ft_close_window, &pgm);
	mlx_hook(pgm.window.win, 2, 1L << 0, ft_handle_keys, &pgm); // key press

	
	
	mlx_loop(pgm.window.mlx);
	close(pgm.map_file.fd_map_file);
	ft_free(&pgm);
	return (0);
}
