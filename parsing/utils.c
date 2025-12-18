/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:45:56 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/16 21:17:20 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	error(char *message)
{
	printf("error/ %s\n", message);
	exit(1);
}

char	*skip_spaces(char *str)
{
	while (str)
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

char	*ft_strdup1(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
// void    initialize(t_map *map)
// {
//     data->EA_path =NULL;
//     data->NO_path =NULL;
//     data->SO_path= NULL;
//     data->WE_path= NULL;
//     data->count = 0;
//     data->player_dir  = 0;
// }

// int main(int ac, char **av)
// {
//     if(ac != 2)
//         error("invalid args");
//     t_data data;
//     initialize(&data);
//     parsing(av, &data);
// }