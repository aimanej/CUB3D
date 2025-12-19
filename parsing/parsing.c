/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:45:29 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/19 01:02:22 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	skipper(char *str)
{
	int	t;

	t = 0;
	while (str[t] && str[t] != ' ')
		t++;
	return (t);
}

// char *skipper(char *str)
// {
// 	while(str && *str != ' ')
// 		str++;
// 	return (str);
// }

char	*get_path(char *str)
{
	char	*path;

	path = NULL;
	str += 2;
	path = skip_spaces(str);
	if (!path)
		return (NULL);
	return (path);
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
		error("Closing Window !invalid filename");
	if (check_map_file(av[1], map))
		error("Closing Window !invalid path or componant");
	if (map->ceil_color == -1 || map->ceil_color == -1)
		error("Closing Window !F or C identifier needed");
	allocate_map(map, av[1]);
	parse_map(map);
}
