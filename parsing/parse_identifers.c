/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:23:22 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/17 20:42:39 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_identifier(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3))
		return (1);
	return (0);
}

int	parse_identif(char *str, t_map *map)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (map->textures[NO].path)
			return (0);
		map->textures[NO].path = ft_strdup1(get_path(str));
	}
	else if (!ft_strncmp(str, "SO ", 3))
	{
		if (map->textures[SO].path)
			return (0);
		map->textures[SO].path = ft_strdup1(get_path(str));
	}
	else if (!ft_strncmp(str, "WE ", 3))
	{
		if (map->textures[WE].path)
			return (0);
		map->textures[WE].path = ft_strdup1(get_path(str));
	}
	else if (!ft_strncmp(str, "EA ", 3))
	{
		if (map->textures[EA].path)
			return (0);
		map->textures[EA].path = ft_strdup1(get_path(str));
	}
	return (1);
}

void	parse_line(char *line, t_map *map, char *str)
{
	str = skip_spaces(line);
	if (is_identifier(str))
	{
		if (!parse_identif(str, map))
		{
			free(line);
			error("too many identifiers");
		}
	}
	else if (is_map(str) && !textured(map))
		map->size++;
	else if ((*str == 'F') || (*str == 'C'))
	{
		if (!f_c_count(*str) && floor_ceiling(str, *str, map))
		{
			free(line);
			error("invalid F or C identifiers");
		}
	}
	else if (is_whitespaces(line))
	{
		free(line);
		error("invalid file content");
	}
}

void	parse_loop(char *line, int fd, t_map *map, char *str)
{
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, map, str);
		free(line);
		line = get_next_line(fd);
	}
}

int	check_map_file(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	*str;

	line = NULL;
	str = NULL;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("OPEN FAILED");
	parse_loop(line, fd, map, str);
	close(fd);
	if (!map->textures[EA].path || !map->textures[SO].path
		|| !map->textures[NO].path || !map->textures[WE].path)
		return (1);
	return (0);
}
