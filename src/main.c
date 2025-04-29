/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/04/30 00:43:06 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_setup_and_loop(t_pgm *pgm)
{
	if (ft_open_window(pgm))
		return (ft_free(pgm), 1);
	pgm->window.win = mlx_new_window(pgm->window.mlx, WIDTH, HEIGHT, "cub3d");
	if (!pgm->window.win)
		return (ft_free(pgm), 1);
	pgm->frame.ptr = mlx_new_image(pgm->window.mlx, WIDTH, HEIGHT);
	if (!pgm->frame.ptr)
		return (ft_free(pgm), 1);
	pgm->frame.addr = mlx_get_data_addr(pgm->frame.ptr,
			&pgm->frame.bits_per_pixel,
			&pgm->frame.line_length,
			&pgm->frame.endian);
	if (!pgm->frame.addr)
		return (ft_free(pgm), 1);
	ft_load_all_textures(pgm);
	mlx_hook(pgm->window.win, 17, 0, ft_close_window, pgm);
	mlx_hook(pgm->window.win, 2, 1L << 0, key_press, pgm);
	mlx_hook(pgm->window.win, 3, 1L << 1, key_release, pgm);
	mlx_loop_hook(pgm->window.mlx, ft_render_frame, pgm);
	mlx_loop(pgm->window.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pgm	pgm;

	ft_init_struct_parsing(&pgm);
	ft_init_struct_rendering(&pgm);
	if (ft_parsing(argc, argv[1], &pgm))
		return (ft_free(&pgm), 1);
	ft_init_player_orientation(&pgm.game);
	pgm.game.pos_x = pgm.game.y_plyr + 0.5;
	pgm.game.pos_y = pgm.game.x_plyr + 0.5;
	if (ft_setup_and_loop(&pgm))
		return (1);
	close(pgm.map_file.fd_map_file);
	ft_free(&pgm);
	return (0);
}
