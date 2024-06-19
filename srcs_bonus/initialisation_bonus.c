/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:35:48 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/06 10:06:41 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	init_data(t_data *data)
{
	init_map(data);
	data->move_speed = 0.15;
	data->rot_speed = 0.05;
	data->a_move = false;
	data->w_move = false;
	data->s_move = false;
	data->d_move = false;
	data->l_turn = false;
	data->r_turn = false;
	data->display_minimap = false;
	data->door_action = false;
	data->mouse_x = 0;
	data->mouse_y = WIDTH / 2;
	data->last_mouse_x = WIDTH / 2;
	init_raycasting(data);
	init_minimap(&data->minimap);
	init_animation(data);
	init_texture(&data->e_txt);
	init_texture(&data->w_txt);
	init_texture(&data->n_txt);
	init_texture(&data->s_txt);
	init_texture(&data->door_open_txt);
	init_texture(&data->door_closed_txt);
}

void	init_raycasting(t_data *data)
{
	data->pos_x = 0.0;
	data->pos_y = 0.0;
	data->dir_x = 0.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.0;
	data->camera = 0.0;
	data->ray_dir_x = 0.0;
	data->ray_dir_y = 0.0;
	data->delta_dist_x = 0.0;
	data->delta_dist_y = 0.0;
	data->grid_step_x = 0;
	data->grid_step_y = 0;
	data->side_dist_x = 0.0;
	data->side_dist_y = 0.0;
	data->ray_x = 0;
	data->ray_y = 0;
	data->wall_hit = 0;
	data->wall = 0;
	data->shortest_dist_wall_cam = 0.0;
	data->cos_rot_speed = cos(data->rot_speed);
	data->sin_rot_speed = sin(data->rot_speed);
	data->cos_rot_speed_neg = cos(-data->rot_speed);
	data->sin_rot_speed_neg = sin(-data->rot_speed);
}

void	init_texture(t_texture *texture)
{
	texture->img = NULL;
	texture->address = NULL;
	texture->height = 300;
	texture->width = 300;
	texture->bpp = 0;
	texture->line_length = 0;
	texture->endian = 0;
}

void	init_map(t_data *data)
{
	data->map.map = NULL;
	data->map.biggest_line = 0;
	data->map.ceiling_color_arr = NULL;
	data->map.south_texture = NULL;
	data->map.north_texture = NULL;
	data->map.floor_color_arr = NULL;
	data->map.west_texture = NULL;
	data->map.east_texture = NULL;
	data->map.position = false;
}
