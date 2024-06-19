/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:05:26 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/06 10:36:28 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	find_hit(t_data *data, t_texture texture)
{
	double	hit;
	int		wall_orientation;

	hit = 0;
	wall_orientation = data->wall % 4;
	if ((wall_orientation == 0 || wall_orientation == 1))
		hit = data->pos_y + data->shortest_dist_wall_cam * data->ray_dir_y;
	else
		hit = data->pos_x + data->shortest_dist_wall_cam * data->ray_dir_x;
	hit -= (int)hit;
	data->texture_x = (int)(hit * (double)texture.width);
	if ((wall_orientation == 0 || wall_orientation == 1) && data->ray_dir_x < 0)
		data->texture_x = texture.width - data->texture_x - 1;
	if ((wall_orientation == 2 || wall_orientation == 3) && data->ray_dir_y > 0)
		data->texture_x = texture.width - data->texture_x - 1;
}

void	texture_select_display(t_data *data, int x)
{
	update_animation(&data->anim);
	if (data->wall >= 4)
	{
		if (data->map.map[data->ray_y][data->ray_x] == 'O')
			one_texture_hit_display(data, data->door_open_txt, x);
		else if (data->map.map[data->ray_y][data->ray_x] == 'D')
			one_texture_hit_display(data, data->door_closed_txt, x);
	}
	if (data->wall == 0)
		one_texture_hit_display(data, data->w_txt, x);
	else if (data->wall == 1)
		one_texture_hit_display(data, data->e_txt, x);
	else if (data->wall == 2)
		one_texture_hit_display(data, data->n_txt, x);
	else if (data->wall == 3)
	{
		find_hit(data, data->anim.frames[data->anim.current_frame]);
		display_line(data, data->anim.frames[data->anim.current_frame], x);
	}
}

void	wall_dist(t_data *data)
{
	int	wall_orientation;

	wall_orientation = data->wall % 4;
	if (wall_orientation < 2)
		data->shortest_dist_wall_cam = (data->side_dist_x - data->delta_dist_x);
	else
		data->shortest_dist_wall_cam = (data->side_dist_y - data->delta_dist_y);
}

void	calc_line(t_data *data)
{
	data->line = HEIGHT / data->shortest_dist_wall_cam;
	data->start = -data->line / 2 + HEIGHT / 2;
	if (data->start < 0)
		data->start = 0;
	data->end = data->line / 2 + HEIGHT / 2;
	if (data->end >= HEIGHT)
		data->end = HEIGHT - 1;
}

void	display_line(t_data *data, t_texture texture, int x)
{
	double			dist;
	double			pos;
	int				texture_y;
	int				y;
	unsigned int	color;

	dist = 1.0 * texture.height / data->line;
	pos = ((double)data->start - (double)HEIGHT / 2 + (double)data->line / 2) \
	* dist;
	if (pos < 0)
		pos = 0;
	y = data->start;
	while (y < data->end)
	{
		texture_y = (int)pos;
		if (pos > texture.height - 1)
			pos = texture.height - 1;
		pos += dist;
		color = get_pixel_color(texture, data->texture_x, texture_y);
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}
