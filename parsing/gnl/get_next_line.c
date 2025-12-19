/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:07:11 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/18 21:16:32 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
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

char	*read_f(int fd, char *holder)
{
	char	*line;
	int		n;
	char	*temp;

	n = 1;
	line = ft_malloc((size_t)(BUFFER_SIZE) + 1);
	if (!line)
		return (NULL);
	while (n > 0)
	{
		n = read(fd, line, BUFFER_SIZE);
		if (n < 0)
			return (ft_free_select(line), NULL);
		line[n] = 0;
		temp = ft_strjoin1(holder, line);
		ft_free_select(holder);
		if (!temp)
			return (ft_free_select(line), NULL);
		holder = temp;
		if (ft_strchr(holder, '\n'))
			break ;
	}
	ft_free_select(line);
	return (holder);
}

char	*get_line(char *holder)
{
	int	i;

	i = 0;
	if (!holder || !*holder)
		return (NULL);
	while (holder[i] != '\n' && holder[i])
		i++;
	return (ft_substr(holder, 0, i));
}

char	*get_remain(char *holder)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!holder)
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	if (!holder[i])
	{
		ft_free_select(holder);
		holder = NULL;
		return (NULL);
	}
	tmp = ft_substr(holder, (i + 1), ft_strlen(holder) - i - 1);
	ft_free_select(holder);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = read_f(fd, holder);
	if (!holder)
		return (NULL);
	line = get_line(holder);
	if (!line)
	{
		ft_free_select(holder);
		holder = NULL;
		return (NULL);
	}
	if (ft_strchr(holder, '\n') == NULL)
	{
		ft_free_select(holder);
		holder = NULL;
		return (line);
	}
	holder = get_remain(holder);
	return (line);
}
