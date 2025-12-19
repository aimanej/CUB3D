/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:49:44 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/18 23:29:22 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_valid_num(char *tmp)
{
	int	i;

	i = 0;
	tmp = skip_spaces(tmp);
	if (tmp[i] == '+')
		i++;
	while (tmp[i])
	{
		if (tmp[i] && !ft_isdigit(tmp[i]))
		{
			tmp = skip_spaces(&tmp[i]);
			if (*tmp != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	check_rgb(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (!is_valid_num(tmp[i]))
			return (1);
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

static int	apply_color(char **tmp, char c, t_map *map)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r > 255 || g > 255 || b > 255)
		return (1);
	if (r < 0 || g < 0 || b < 0)
		return (1);
	if (c == 'F')
		map->fl_color = chimicolor(r, g, b);
	else
		map->ceil_color = chimicolor(r, g, b);
	return (0);
}

int	floor_ceiling(char *line, char c, t_map *map)
{
	char	**tmp;

	if (f_c_count(*line))
		return (1);
	line++;
	line = skip_spaces(line);
	tmp = ft_split(line, ',');
	if (!tmp)
		return (1);
	if (check_rgb(tmp))
		return (free_2d(tmp), 1);
	if (apply_color(tmp, c, map))
		return (free_2d(tmp), 1);
	free_2d(tmp);
	return (0);
}
