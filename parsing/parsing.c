/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:45:29 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/18 15:08:13 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_map(char *line)
{
	char	*str;

	str = skip_spaces(line);
	if (ft_isdigit(*str))
		return (1);
	return (0);
}

int	check_filename(char *filename)
{
	size_t	i;

	if (!filename)
		return (1);
	i = ft_strlen(filename);
	if (i <= 4 || filename[i - 1] != 'b' || filename[i - 2] != 'u' || filename[i
			- 3] != 'c' || filename[i - 4] != '.' || filename[i - 5] == '/')
		return (1);
	return (0);
}

char	*get_path(char *str)
{
	char	*path;

	path = ft_strchr(str, '.');
	if (!path)
		return (NULL);
	if (path[0] == '/')
		return (path);
	return (NULL);
}

static char	**ft_free(char **r, int in)
{
	int	t;

	t = 0;
	while (r[t])
	{
		free(r[t]);
		t++;
	}
	free(r);
	return (NULL);
}

void	parsing(char **av, t_map *map)
{
	if (check_filename(av[1]))
		error("invalid filename");
	if (check_map_file(av[1], map))
		error("invalid path or componant");
	if (map->ceil_color == -1 || map->ceil_color == -1)
		error("F or C identifier needed");
	allocate_map(map, av[1]);
	parse_map(map);
}
