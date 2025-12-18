/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:18:43 by aijadid           #+#    #+#             */
/*   Updated: 2025/12/18 20:18:44 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	t;

	str = (unsigned char *)s;
	t = 0;
	while (n > 0)
	{
		str[t] = c;
		t++;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

t_ray	*newray(void)
{
	t_ray	*ray;

	ray = ft_malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ft_bzero(ray, sizeof(t_ray));
	ray->hor_wall_distance = INFINITY;
	ray->ver_wall_distance = INFINITY;
	ray->wall_distance = INFINITY;
	return (ray);
}

void	init_ray_arr(t_map *map)
{
	int	t;

	map->ray_arr = ft_malloc(sizeof(t_ray *) * (WIDTH + 1));
	if (!(map->ray_arr))
		return (ft_free_all());
	t = 0;
	while (t < WIDTH)
	{
		map->ray_arr[t] = newray();
		if (!map->ray_arr[t])
			return (ft_free_all());
		t++;
	}
	map->ray_arr[t] = NULL;
	return ;
}

void	map_init(t_mlx *mlx)
{
	ft_bzero(&(mlx->map), sizeof(mlx->map));
	mlx->map.player.move_speed = 2;
	mlx->map.player.rotation_speed = 2 * (PI / 180);
	mlx->map.player.fov = 60 * (PI / 180);
	mlx->map.ceil_color = -1;
	mlx->map.fl_color = -1;
	mlx->map.textures[NO].path = NULL;
	mlx->map.textures[SO].path = NULL;
	mlx->map.textures[WE].path = NULL;
	mlx->map.textures[EA].path = NULL;
}
