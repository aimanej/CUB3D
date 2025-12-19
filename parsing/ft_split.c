/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:17:39 by ayboudya          #+#    #+#             */
/*   Updated: 2025/12/19 11:40:04 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	d;

	count = 0;
	d = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			d = 1;
		else if (s[i] == c && d == 1)
		{
			count++;
			d = 0;
		}
		i++;
	}
	if (d == 1)
		count++;
	return (count);
}

static int	lent(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static int	fill(const char *s, int i, char *r, char c)
{
	int	index;

	index = 0;
	while (s[i] != c && s[i])
	{
		r[index] = s[i];
		i++;
		index++;
	}
	r[index] = 0;
	return (i);
}

static char	**ft_free(char **r)
{
	int	t;

	t = 0;
	while (r[t])
	{
		ft_free_select(r[t]);
		t++;
	}
	ft_free_select(r);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		in;
	int		i;

	in = 0;
	i = 0;
	if (!s)
		return (NULL);
	r = ft_malloc((count_words(s, c) + 1) * (sizeof(char *)));
	if (!r)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			r[in] = ft_malloc(lent(s, i, c) + 1);
			if (!r[in])
				return (ft_free(r));
			i = fill(s, i, r[in], c);
			in++;
		}
		else
			i++;
	}
	return (r[in] = 0, r);
}
