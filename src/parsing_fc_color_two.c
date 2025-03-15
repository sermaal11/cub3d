/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fc_color_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:45:52 by smarin-a          #+#    #+#             */
/*   Updated: 2025/03/15 11:39:47 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_extract_rgb_value(char **color_str)
{
	int	value;
	int	digits;

	value = 0;
	digits = 0;
	while (**color_str && **color_str != ',')
	{
		if (**color_str < '0' || **color_str > '9')
			return (-1);
		value = value * 10 + (**color_str - '0');
		digits++;
		(*color_str)++;
	}
	if (digits == 0 || value < 0 || value > 255)
		return (-1);
	if (**color_str == ',')
		(*color_str)++;
	return (value);
}

int	ft_check_rgb_value(char *color, t_vec3 *vec)
{
	vec->r = ft_extract_rgb_value(&color);
	vec->g = ft_extract_rgb_value(&color);
	vec->b = ft_extract_rgb_value(&color);
	if (vec->r == -1 || vec->g == -1 || vec->b == -1)
		return (ft_print_error("Error:\nValue out of range.\n", 1));
	return (0);
}
