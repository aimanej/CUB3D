/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fillers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:29:59 by aijadid           #+#    #+#             */
/*   Updated: 2025/12/19 11:30:32 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	skipper(char *str)
{
	int	t;

	t = 0;
	while (str[t] && str[t] != ' ')
		t++;
	return (t);
}

char	*filler(char *str)
{
	char	*s1;

	s1 = ft_substr(get_path(str), 0, skipper(get_path(str)));
	return (s1);
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
