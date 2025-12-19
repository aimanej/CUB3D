/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:02:17 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/18 21:27:12 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_elem(t_map *map, int i, int j)
{
	char	c;

	c = map->map[i][j];
	if (ft_strchr("10NSEW", c) || is_space(c))
	{
		if (ft_strchr("NSEW", c))
		{
			player_angle_set(map, c);
			map->player.center_pos.row = i * TILE_SIZE + (TILE_SIZE / 2);
			map->player.center_pos.col = j * TILE_SIZE + (TILE_SIZE / 2);
		}
		return (0);
	}
	return (1);
}

int	map_elements(t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strchr("NSEW", map->map[i][j]))
				count++;
			if (check_elem(map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	if (count != 1)
		error("Closing Window !player count");
	return (0);
}
