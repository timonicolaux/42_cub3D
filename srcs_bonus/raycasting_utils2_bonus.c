/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:17:25 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/06 10:01:59 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	setup_raycasting(t_data *data, int x)
{
	data->ray_x = (int)data->pos_x;
	data->ray_y = (int)data->pos_y;
	data->camera = 2 * (double)x / (double)WIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
}

void	one_texture_hit_display(t_data *data, t_texture texture, int x)
{
	find_hit(data, texture);
	display_line(data, texture, x);
}
