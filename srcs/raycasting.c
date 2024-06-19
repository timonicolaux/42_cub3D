/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:14:06 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/06 10:06:41 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	raycasting(t_data *data)
{
	int	x;

	x = 0;
	clear_image(data);
	while (x < WIDTH)
	{
		setup_raycasting(data, x);
		calc_direction(data);
		hit_wall(data);
		wall_dist(data);
		calc_line(data);
		texture_select_display(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->main.img, 0, 0);
	return (0);
}

void	clear_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			if (y < (HEIGHT / 2))
				my_mlx_pixel_put(data, x, y, data->map.ceiling_color);
			else
				my_mlx_pixel_put(data, x, y, data->map.floor_color);
			y++;
		}
		y = 0;
		x++;
	}
}

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

void	calc_direction(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->grid_step_x = -1;
		data->side_dist_x = (data->pos_x - data->ray_x) * data->delta_dist_x;
	}
	else
	{
		data->grid_step_x = 1;
		data->side_dist_x = (data->ray_x + 1.0 - data->pos_x) * \
		data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->grid_step_y = -1;
		data->side_dist_y = (data->pos_y - data->ray_y) * data->delta_dist_y;
	}
	else
	{
		data->grid_step_y = 1;
		data->side_dist_y = (data->ray_y + 1.0 - data->pos_y) * \
		data->delta_dist_y;
	}
}

void	hit_wall(t_data *data)
{
	while (data->wall_hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->ray_x += data->grid_step_x;
			if (data->ray_dir_x > 0)
				data->wall = 0;
			else
				data->wall = 1;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->ray_y += data->grid_step_y;
			if (data->ray_dir_y > 0)
				data->wall = 2;
			else
				data->wall = 3;
		}
		if (data->map.map[data->ray_y][data->ray_x] == '1')
			data->wall_hit = 1;
	}
	data->wall_hit = 0;
}
