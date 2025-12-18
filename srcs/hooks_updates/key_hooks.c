/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:18:37 by aijadid           #+#    #+#             */
/*   Updated: 2025/12/18 20:18:38 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mlx_hook_loops(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, (1L << 0), press_hook, mlx);
	mlx_hook(mlx->win, 3, (1L << 1), release_hook, mlx);
	mlx_hook(mlx->win, 17, 0, destroy_notify, NULL);
	mlx_loop_hook(mlx->mlx, gameloop, mlx);
	mlx_loop(mlx->mlx);
}

int	destroy_notify(int keysim, void *data)
{
	(void)keysim;
	(void)data;
	ft_free_all();
	return (0);
}

int	press_hook(int keysim, void *data)
{
	t_mlx	*mlx;

	mlx = data;
	if (keysim == 65361)
		mlx->map.player.turn_dir = -1;
	else if (keysim == 65363)
		mlx->map.player.turn_dir = 1;
	else if (keysim == 119)
		mlx->map.player.walk_dir = 1;
	else if (keysim == 115)
		mlx->map.player.walk_dir = -1;
	else if (keysim == 97)
		mlx->map.player.side_walk = -1;
	else if (keysim == 100)
		mlx->map.player.side_walk = 1;
	else if (keysim == 65505)
		mlx->map.player.move_speed *= 5;
	else if (keysim == 65307)
	{
		mlx_loop_end(mlx->mlx);
		ft_free_all();
	}
	return (0);
}

int	release_hook(int keysim, void *data)
{
	t_mlx	*mlx;

	mlx = data;
	if (keysim == 65361)
		mlx->map.player.turn_dir = 0;
	if (keysim == 65363)
		mlx->map.player.turn_dir = 0;
	if (keysim == 119 || keysim == 115)
		mlx->map.player.walk_dir = 0;
	if (keysim == 65505)
		mlx->map.player.move_speed = 2;
	else if (keysim == 97 || keysim == 100)
		mlx->map.player.side_walk = 0;
	return (0);
}
