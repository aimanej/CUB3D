#include "../../includes/cub3d.h"

t_ray	*newray(void)
{
	t_ray	*ray;

	ray = ft_malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	bzero(ray, sizeof(t_ray));
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
		return ft_free_all();
	t = 0;
	while (t < WIDTH)
	{
		map->ray_arr[t] = newray();
		if(!map->ray_arr[t])
			return ft_free_all();
		t++;
	}
	map->ray_arr[t] = NULL;
	return ;
}

void	map_init(t_mlx *mlx)
{
	bzero(&(mlx->map), sizeof(mlx->map));
	mlx->map.player.move_speed = 2;
	mlx->map.player.rotation_speed = 2 * (PI / 180);
	mlx->map.player.fov = 60 * (PI / 180);
}
