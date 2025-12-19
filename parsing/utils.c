/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:45:56 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/19 11:16:34 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(t_map *map, char *message)
{
	if (map->fd > 2)
		close(map->fd);
	printf("error/ %s\n", message);
	ft_free_all();
}

char	*skip_spaces(char *str)
{
	while (str && *str)
	{
		if (!((*str >= 9 && *str <= 13) || *str == 32))
			break ;
		str++;
	}
	return (str);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 9 && str[i] <= 13) && str[i] != 32)
			return (1);
		i++;
	}
	return (0);
}
