/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:42:34 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/19 13:08:19 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_pgm	pgm;

	ft_init_struct_parsing(&pgm);
	if (ft_parsing(argc, argv[1], &pgm))
	{
		ft_free(&pgm);
		return (1);
	}
	if (pgm.map_file.fd_map_file != -1)
		close(pgm.map_file.fd_map_file);
	ft_free(&pgm);
	return (0);
}
