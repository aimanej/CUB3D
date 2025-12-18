/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:59:48 by aijadid           #+#    #+#             */
/*   Updated: 2025/12/18 19:59:49 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		printf("ERROR/invalid num of args\n");
		return (1);
	}
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
	{
		perror("Mlx init failed!");
		return (0);
	}
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "WINDOW");
	if (!mlx.win)
	{
		perror("Window creation failed!");
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
		return (0);
	}
	ft_add_last_ptr(dump_ptr(), ft_new_ptr(&mlx, 0));
	map_init(&mlx);
	parsing(av, &(mlx.map));
	mlx.map.screenw = WIDTH;
	texture_init(&(mlx));
	init_ray_arr(&(mlx.map));
	render_func(&mlx);
	mlx_hook_loops(&mlx);
}
