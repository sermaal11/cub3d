/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fc_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:22:41 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/21 02:59:33 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_fc_amount(t_pgm *pgm)
{
	int	i;
	int	j;

	i = -1;
	pgm->map_file.count_f = 0;
	pgm->map_file.count_c = 0;
	while (pgm->map_file.file_matrix[++i])
	{
		j = -1;
		while (pgm->map_file.file_matrix[i][++j])
		{
			if (pgm->map_file.file_matrix[i][j] == 'F')
				pgm->map_file.count_f++;
			else if (pgm->map_file.file_matrix[i][j] == 'C')
				pgm->map_file.count_c++;
		}
	}
	if (pgm->map_file.count_f != 1 || pgm->map_file.count_c != 1)
	{
		if (pgm->map_file.count_f == 0 || pgm->map_file.count_c == 0)
			return (ft_print_error("Error:\nColor not found (F or C).\n", 1));
		if (pgm->map_file.count_f > 1 || pgm->map_file.count_c > 1)
			return (ft_print_error("Error:\nColor repeated (F or C).\n", 1));
	}
	return (0);
}

int	ft_check_id_before_map(t_pgm *pgm)
{
	int		i;
	int		map_started;
	char	*line;

	i = 0;
	map_started = 0;
	while (pgm->map_file.file_matrix[i])
	{
		line = pgm->map_file.file_matrix[i];
		if (ft_is_map_line(line) == 0)
			map_started = 1;
		if (map_started && (ft_strchr(line, 'F') || ft_strchr(line, 'C')
				|| ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "SO ", 3)
				|| ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "EA ", 3)))
			return (ft_print_error("Error:\nID after the map.\n", 1));
		i++;
	}
	return (0);
}

static int	ft_check_rgb_format(char *rgb_format, int num_count)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	if (!rgb_format)
		return (ft_print_error("Error:\nRGB format is NULL.\n", 1));
	while (rgb_format[i])
	{
		if (i == 0 || !ft_isdigit(rgb_format[i - 1]))
			num_count += 1;
		if (ft_isdigit(rgb_format[i]))
			i++;
		else if (rgb_format[i] == ',' && (i == 0 || rgb_format[i + 1] == '\0'
				|| rgb_format[i + 1] == ','))
			return (ft_print_error("Error:\nUnexpect comma.\n", 1));
		else if (rgb_format[i] == ',' && i++ >= 0)
			comma_count++;
		else
			return (ft_print_error("Error:\nOnly digits and commas.\n", 1));
	}
	if (comma_count != 2 || num_count != 3)
		return (ft_print_error("Error:\nExpected 3 numbers & 2 commas.\n", 1));
	return (0);
}

static int	ft_take_rgb_format(t_pgm *pgm)
{
	if (ft_check_rgb_format(pgm->floor.color, 0))
		return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
	if (ft_check_rgb_format(pgm->ceiling.color, 0))
		return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
	if (ft_check_rgb_value(pgm->floor.color, &pgm->floor))
		return (ft_print_error("Error:\nInvalid RGB value.\n", 1));
	if (ft_check_rgb_value(pgm->ceiling.color, &pgm->ceiling))
		return (ft_print_error("Error:\nInvalid RGB value.\n", 1));
	return (0);
}

int	ft_take_fc_content(t_pgm *pgm)
{
	int		i;
	char	*line;
	char	*color_value;

	i = -1;
	while (pgm->map_file.file_matrix[++i])
	{
		line = pgm->map_file.file_matrix[i];
		if (line[0] == 'F' || line[0] == 'C')
		{
			color_value = ft_strchr(line, ' ');
			if (!color_value)
				return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
			color_value++;
			if (!ft_isdigit(*color_value))
				return (ft_print_error("Error:\nInvalid RGB format.\n", 1));
			if (line[0] == 'F')
				pgm->floor.color = ft_strdup(color_value);
			else if (line[0] == 'C')
				pgm->ceiling.color = ft_strdup(color_value);
		}
	}
	if (ft_take_rgb_format(pgm))
		return (1);
	return (0);
}
