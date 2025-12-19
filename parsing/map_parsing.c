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

void	allocation(t_map *map, char *line, int *i, int *flag)
{
	if (is_map(line))
	{
		map->map[*i] = ft_strdup(line);
		(*i)++;
		(*flag)++;
	}
	if (!is_map(line) && *flag && *flag < map->size)
		error(map, "bad map\n");
}

void	allocate_map(t_map *map, char *filename)
{
	char	*line;
	int		fd;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error(map, "Closing Window !OPEN");
	map->fd = fd;
	map->map = ft_malloc((map->size + 1) * sizeof(char *));
	line = get_next_line(fd);
	while (line)
	{
		allocation(map, line, &i, &flag);
		ft_free_select(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->map[i] = 0;
}

void	parse_map(t_map *map)
{
	if (map_elements(map))
		error(map, "Closing Window !invalid map elements");
	if (valid_spaces(map))
		error(map, "Closing Window !invalid spaces");
	if (is_surrounded_by_walls(map))
		error(map, "Closing Window !not surrounded by wall");
}
