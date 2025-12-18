/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <aijadid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:18:32 by aijadid           #+#    #+#             */
/*   Updated: 2025/12/18 20:18:33 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

void	ray_direction(t_ray *ray)
{
	if (ray->angle > (PI / 2) && ray->angle < (3 * PI) / 2)
		ray->face_lr = LEFT;
	else
		ray->face_lr = RIGHT;
	if (ray->angle >= 0 && ray->angle <= PI)
		ray->face_du = DOWN;
	else
		ray->face_du = UP;
}

void	player_direction(t_player *py)
{
	if (py->view_angle > (PI / 2) && py->view_angle < (3 * PI) / 2)
		py->face_lr = LEFT;
	else
		py->face_lr = RIGHT;
	if (py->view_angle >= 0 && py->view_angle <= PI)
		py->face_du = DOWN;
	else
		py->face_du = UP;
}
