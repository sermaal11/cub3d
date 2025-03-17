/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariskan <jariskan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:01:54 by jariskan          #+#    #+#             */
/*   Updated: 2025/03/17 17:37:46 by jariskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!ft_strchr(" 1", line[i]))
		return (1);
	while (line[i])
	{
		if (!ft_strchr(" 10NSWE", line[i]))
			return (1);
		i++;
	}
	return (0);
}
