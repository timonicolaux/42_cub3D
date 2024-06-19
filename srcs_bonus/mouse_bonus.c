/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:21:11 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/05 15:24:27 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	turn_camera(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(angle) - data->dir_y * sin(angle);
	data->dir_y = old_dir_x * sin(angle) + data->dir_y * cos(angle);
	data->plane_x = data->plane_x * cos(angle) - data->plane_y * sin(angle);
	data->plane_y = old_plane_x * sin(angle) + data->plane_y * cos(angle);
}

int	mouse_hook(int x, int y, t_data *data)
{
	int	delta_x;

	(void)y;
	delta_x = x - data->last_mouse_x;
	if (delta_x != 0)
	{
		turn_camera(data, delta_x * 0.0015);
		data->last_mouse_x = x;
	}
	data->mouse_x = x;
	return (0);
}

int	mouse_infinite_turn(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (data->mouse_x < (WIDTH / 8) && data->mouse_x >= 0)
			turn_camera(data, -0.08);
		else if (data->mouse_x > (WIDTH - (WIDTH / 8)) && \
		data->mouse_x <= WIDTH)
			turn_camera(data, 0.08);
	}
	return (0);
}
