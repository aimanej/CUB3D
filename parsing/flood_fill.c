/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:26:28 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/18 21:22:29 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_spaces(t_map *map, int i, int j)
{
	if (i < 0 || i >= map->size)
		return (0);
	if (j < 0 || j >= (int)ft_strlen(map->map[i]))
		return (0);
	if (map->map[i][j] == '1' || map->map[i][j] == 'o'
		|| map->map[i][j] == map->player.player_dir)
		return (1);
	if (map->map[i][j] != '0')
		return (0);
	map->map[i][j] = 'o';
	if (!parse_spaces(map, i + 1, j))
		return (0);
	if (!parse_spaces(map, i, j - 1))
		return (0);
	if (!parse_spaces(map, i - 1, j))
		return (0);
	if (!parse_spaces(map, i, j + 1))
		return (0);
	return (1);
}

int	valid_spaces(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
			{
				if (!parse_spaces(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	free_2d(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

int	textured(t_map *map)
{
	int	t;

	t = 0;
	while (t < 4)
	{
		if (!(map->textures[t].path))
			return (1);
		t++;
	}
	if (map->ceil_color == -1 || map->fl_color == -1)
		return (1);
	return (0);
}

int	f_c_count(char c)
{
	static int	floors;
	static int	ceilings;

	if (c == 'F')
		floors++;
	else
		ceilings++;
	if (floors > 1 || ceilings > 1)
		return (1);
	return (0);
}
