/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:45:56 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/18 17:09:53 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	error(char *message)
{
	printf("error/ %s\n", message);
	ft_free_all();
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

char	*ft_substr1(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup1(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	p = ft_malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
