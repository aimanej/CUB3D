/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/12/15 23:21:37 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/15 23:21:37 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && !is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!is_walls(map->map[0]) || !is_walls(map->map[map->size - 1]))
		return (1);
	while (map->map[i])
	{
		if ((map->map[i][0] != '1' && !is_space(map->map[i][0]))
			|| (map->map[i][ft_strlen(map->map[i]) - 1] != '1'
				&& !is_space(map->map[i][ft_strlen(map->map[i]) - 1])))
			return (1);
		i++;
	}
	return (0);
}

void	allocate_map(t_map *map, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("OPEN");
	map->map = ft_malloc((map->size + 1) * sizeof(char *));
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line))
		{
			map->map[i] = ft_strdup1(line);
			i++;
		}
		ft_free_select(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->map[i] = 0;
}

void	player_angle_set(t_map *map, char c)
{
	map->player.player_dir = c;
	if (c == 'N')
		map->player.view_angle = 270 * (PI / 180);
	else if (c == 'S')
		map->player.view_angle = 90 * (PI / 180);
	else if (c == 'E')
		map->player.view_angle = 0 * (PI / 180);
	else if (c == 'W')
		map->player.view_angle = 180 * (PI / 180);
	player_direction(&(map->player));
}

void	parse_map(t_map *map)
{
	if (map_elements(map))
		error("invalid map elements");
	if (valid_spaces(map))
		error("invalid spaces");
	if (is_surrounded_by_walls(map))
		error("not surrounded by wall");
}
