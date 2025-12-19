/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:59:48 by aijadid           #+#    #+#             */
/*   Updated: 2025/12/18 21:27:12 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	disp_win_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		perror("Closing Window !Mlx init failed!");
		return (1);
	}
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "WINDOW");
	if (!mlx->win)
	{
		perror("Closing Window !Window creation failed!");
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		printf("ERROR/invalid num of args\n");
		return (1);
	}
	if (disp_win_init(&mlx))
		return (1);
	ft_add_last_ptr(dump_ptr(), ft_new_ptr(&mlx, 0));
	map_init(&mlx);
	parsing(av, &(mlx.map));
	mlx.map.screenw = WIDTH;
	texture_init(&(mlx));
	init_ray_arr(&(mlx.map));
	render_func(&mlx);
	mlx_hook_loops(&mlx);
}
