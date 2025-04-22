/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:23:14 by jdelorme          #+#    #+#             */
/*   Updated: 2025/04/22 21:41:21 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_load_texture(t_pgm *pgm, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(pgm->window.mlx, path, &img->width, &img->height);
	if (!img->ptr)
	{
		perror("Error loading texture");
		// ! FIX
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
}
void	ft_load_all_textures(t_pgm *pgm)
{
	//revisar que pasa si no hay
	ft_load_texture(pgm, &pgm->weapon_img, "./textures/gun.xpm");
	ft_load_texture(pgm, &pgm->texture.img_no, pgm->texture.no);
	ft_load_texture(pgm, &pgm->texture.img_so, pgm->texture.so);
	ft_load_texture(pgm, &pgm->texture.img_we, pgm->texture.we);
	ft_load_texture(pgm, &pgm->texture.img_ea, pgm->texture.ea);
}